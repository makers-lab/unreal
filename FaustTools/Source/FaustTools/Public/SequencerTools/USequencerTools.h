#pragma once

#include "Engine.h"
#include "ModuleManager.h"
#include "FaustToolsBaseClass.h"
#include "USequencerTools.generated.h"

class UScale;
class ULevelSequence;
class UMovieScene3DTransformSection;

enum TransformType;
struct CustomTransform;

UCLASS(Blueprintable)
class USequencerTools : public UFaustToolsBaseClass
{
	GENERATED_BODY()
public:

	USequencerTools();

	virtual void PreEditChange(UProperty* PropertyAboutToChange) override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void OnToolClosed() override;

	UFUNCTION(Exec)
	void CaptureRange();
	UFUNCTION(Exec)
	void ResetCapture();

	UPROPERTY(EditAnywhere, Category = "Transform Parameters")
	bool Location;
	UPROPERTY(EditAnywhere, Category = "Transform Parameters")
	bool Rotation;
	UPROPERTY(EditAnywhere, Category = "Transform Parameters")
	bool Scaling;

	UPROPERTY(EditAnywhere, Category = "Curve Parameters")
	bool X;
	UPROPERTY(EditAnywhere, Category = "Curve Parameters")
	bool Y;
	UPROPERTY(EditAnywhere, Category = "Curve Parameters")
	bool Z;

	UPROPERTY(EditAnywhere, Category = "Parameters", meta = (DisplayName = "From Frame", Keywords = "From Frame"))
	int32 FromFrame;
	
	UPROPERTY(EditAnywhere, Category = "Parameters", meta = (DisplayName = "To Frame", Keywords = "To Frame"))
	int32 ToFrame;

	//Scale selected keys
	UPROPERTY(EditAnywhere, Category = "Scaling", meta = (DisplayName = "Scale Captured Range Only", Keywords = "Scale Capture Range Only"))
	bool bScaleCapturedRange;

	//Scaling
	UPROPERTY(EditAnywhere, Category = "Scaling", meta = (DisplayName = "Scale Top", Keywords = "Scale Top"))
	float ScaleTopValue;
	float OldScaleTopValue;

	UPROPERTY(EditAnywhere, Category = "Scaling", meta = (DisplayName = "Scale Bottom", Keywords = "Scale Bottom"))
	float ScaleBotValue;
	float OldScaleBotValue;

	UPROPERTY(EditAnywhere, Category = "Scaling", meta = (DisplayName = "Scale Left", Keywords = "Scale Left"))
	float ScaleLeftValue;
	float OldScaleLeftValue;

	UPROPERTY(EditAnywhere, Category = "Scaling", meta = (DisplayName = "Scale Right", Keywords = "Scale Right"))
	float ScaleRightValue;
	float OldScaleRightValue;

	UPROPERTY(EditAnywhere, Category = "Scaling", meta = (DisplayName = "Move Horizontal", Keywords = "Move Horizontal"))
	float MoveHorizontalValue;
	float OldMoveHorizontalValue;

	UPROPERTY(EditAnywhere, Category = "Scaling", meta = (DisplayName = "Move Vertical", Keywords = "Move Vertical"))
	float MoveVerticalValue;
	float OldMoveVerticalValue;

private:
	TSharedPtr<UScale> Scale;
	ULevelSequence * Sequencer = nullptr;
	UMovieScene3DTransformSection * TransformSection = nullptr;

	CustomTransform TransformToEdit;

	void GetValuesAndTimesToEditFromCurve(FRichCurve Curve, float FromTime, float ToTime, TArray<float>& OutValues, TArray<float>& OutTimes, TArray<int32>& OutIndexes);
	void GetTransformAndCurves(TArray<TransformType>& TransformTypes, TArray<EAxis::Type>& Axises);

	TMap<EAxis::Type, CustomTransform> CurvesValuesToEdit;

	TArray<TransformType> TransformTypes;
	TArray<EAxis::Type> Axises;

	TArray<float> ValuesToEdit;
	TArray<float> TimesToEdit;

	float MinValue;
	float MaxValue;
};


