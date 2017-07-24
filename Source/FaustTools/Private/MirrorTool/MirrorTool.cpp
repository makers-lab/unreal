#include "FaustTools/Private/FaustToolsPrivatePCH.h"
#include "MirrorTool.h"
#include "ScopedTransaction.h"



UMirrorTool::UMirrorTool()
{
	MirrorPlane = FPlane(1.0, 0.0f, 0.0f, 0.0f);
}

void UMirrorTool::MirrorSelectedObjects()
{
	for (FSelectionIterator It(GEditor->GetSelectedActorIterator()); It; ++It)
	{
		if (AActor* Actor = Cast<AActor>(*It))
		{
			const FVector CurrentPos = Actor->GetActorLocation();
			const FVector NewPos = CurrentPos.MirrorByPlane(MirrorPlane);

			Actor->Modify();
			Actor->SetActorLocation(NewPos);
		}
	}
}
