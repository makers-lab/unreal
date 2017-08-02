#include "FaustTools/Private/FaustToolsPrivatePCH.h"
#include "UnrealEd.h"
#include "Networking.h"
#include "MayaToUETickObject.h"

#define LOCTEXT_NAMESPACE "EditorTick"

UMayaToUE::UMayaToUE()

	:Client(NULL),
	TcpListener(NULL)

{	
}

void UMayaToUE::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	UProperty *PropertyThatChanged = PropertyChangedEvent.Property;
	if (PropertyThatChanged->GetFName() == FName("Connect"))
	{
		if (Connect)
		{
			ResetConnection(DEFAULT_M2U_PORT);
			EditorTickObject = new FEditorTickObject(this);
		}
		else
		{
			if (Client != NULL)
			{
				Client->Close();
				delete Client;
				Client = NULL;
			}
			if (TcpListener != NULL)
			{
				TcpListener->Stop();
				delete TcpListener;
				TcpListener = NULL;
			}
			if (EditorTickObject)
			{
				delete EditorTickObject;
				EditorTickObject = NULL;
			}
		}
	}
}

void UMayaToUE::OnToolClosed()
{
	if (Client != NULL)
	{
		Client->Close();
		delete Client;
		Client = NULL;
	}
	if (TcpListener)
	{
		delete TcpListener;
		TcpListener = NULL;
	}
	if (EditorTickObject)
	{
		delete EditorTickObject;
		EditorTickObject = NULL;
	}
}

void UMayaToUE::Tick(float DeltaTime)
{
	if (Client != NULL && Client->GetConnectionState() == SCS_Connected)
	{
		FString Message;
		if (GetMessage(Message))
		{
			UE_LOG(LogTemp, Display, TEXT("Message %s"), *Message);
		}
		//else UE_LOG(LogTemp, Display, TEXT("Message is empty!"));
	}
	//else UE_LOG(LogTemp, Display, TEXT("Not connected!"));
}

bool UMayaToUE::HandleConnectionAccepted(FSocket* ClientSocket, const struct FIPv4Endpoint& ClientEndpoint)
{
	if (Client == NULL)
	{
		Client = ClientSocket;
		int32 NewSize;
		Client->SetReceiveBufferSize(4000000, NewSize);
		UE_LOG(LogTemp, Display, TEXT("Connected on Port %i, Buffersize %i."), Client->GetPortNo(), NewSize);
		return true;
	}
	UE_LOG(LogTemp, Display, TEXT("Connection declined"));
	return false;
}

bool UMayaToUE::GetMessage(FString& Result)
{
	uint32 DataSize = 0;
	while (Client->HasPendingData(DataSize) && DataSize > 0)
	{
		FArrayReader Data;
		Data.SetNumUninitialized(DataSize);

		int32 BytesRead = 0;
		if (Client->Recv(Data.GetData(), Data.Num(), BytesRead))
		{
			int32 DestLen = TStringConvert<ANSICHAR, TCHAR>::ConvertedLength((char*)(Data.GetData()), Data.Num());
			TCHAR* Dest = new TCHAR[DestLen + 1];
			TStringConvert<ANSICHAR, TCHAR>::Convert(Dest, DestLen, (char*)(Data.GetData()), Data.Num());
			Dest[DestLen] = '\0';
			Result += Dest;
			delete Dest;
		}
	}
	if (!Result.IsEmpty())
		return true;
	else
		return false;
}

void UMayaToUE::ResetConnection(uint16 Port)
{
	if (Client != NULL)
	{
		Client->Close();
		delete Client;
		Client = NULL;
	}
	if (TcpListener != NULL)
	{
		TcpListener->Stop();
		delete TcpListener;
		TcpListener = NULL;

	}
	UE_LOG(LogTemp, Display, TEXT("Hosting on Port %i"), Port);
	TcpListener = new FTcpListener(FIPv4Endpoint(DEFAULT_M2U_ADDRESS, Port));
	TcpListener->OnConnectionAccepted().BindUObject(this, &UMayaToUE::HandleConnectionAccepted);
}

#undef LOCTEXT_NAMESPACE

/*delete 



*/