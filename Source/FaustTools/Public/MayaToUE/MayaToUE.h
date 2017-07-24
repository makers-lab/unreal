#pragma once
#include "Engine.h"
#include "ModuleManager.h"
#include "FaustToolsBaseClass.h"
#include "MayaToUE.generated.h"

class FEditorTickObject;
#define DEFAULT_M2U_ADDRESS FIPv4Address(0,0,0,0)
#define DEFAULT_M2U_PORT 3939

UCLASS(Blueprintable)
class UMayaToUE : public UFaustToolsBaseClass
{
	GENERATED_BODY()
public:

	UMayaToUE();

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void OnToolClosed() override;

	void Tick(float DeltaTime);

	bool HandleConnectionAccepted(FSocket* ClientSocket, const struct FIPv4Endpoint& ClientEndpoint);
	bool GetMessage(FString& Result);
	void ResetConnection(uint16 Port);

	UPROPERTY(EditAnywhere, Category = "Commnands")
		bool Connect;



private:
	FSocket* Client;
	class FTcpListener* TcpListener;
	FEditorTickObject* EditorTickObject;
};