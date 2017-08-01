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

	UPROPERTY(EditAnywhere, Category = "Parameters|Frames", meta = (DisplayName = "From Frame", AllowPrivateAccess = "true"))
		int32 FromFrame;
	UPROPERTY(EditAnywhere, Category = "Parameters|Frames", meta = (DisplayName = "To Frame", AllowPrivateAccess = "true"))
		int32 ToFrame; 
	
	UPROPERTY(EditAnywhere, Category = "Parameters|Transformation", meta = (AllowPrivateAccess = "true"))
		bool Location;
	UPROPERTY(EditAnywhere, Category = "Parameters|Transformation", meta = (AllowPrivateAccess = "true"))
		bool Rotation;
	UPROPERTY(EditAnywhere, Category = "Parameters|Transformation", meta = (AllowPrivateAccess = "true"))
		bool Scaling;

	UPROPERTY(EditAnywhere, Category = "Parameters|Transformation|Curve", meta = (DisplayName = "X", AllowPrivateAccess = "true"))
		bool XCurve;
	UPROPERTY(EditAnywhere, Category = "Parameters|Transformation|Curve", meta = (DisplayName = "Y", AllowPrivateAccess = "true"))
		bool YCurve;
	UPROPERTY(EditAnywhere, Category = "Parameters|Transformation|Curve", meta = (DisplayName = "Z", AllowPrivateAccess = "true"))
		bool ZCurve;

	

	

	//Filters
	UPROPERTY(EditAnywhere, Category = "Butterworth Filter", meta = (DisplayName = "Hz", Keywords = "Hz"))
		float Hz;
	UPROPERTY(EditAnywhere, Category = "Filter Keys", meta = (DisplayName = "Delta", Keywords = "Delta"))
		float Delta;

	//Scale selected keys
	UPROPERTY(EditAnywhere, Category = "Scaling", meta = (DisplayName = "Scale Captured Range Only"))
		bool bScaleCapturedRange;

	//Scaling
	UPROPERTY(EditAnywhere, Category = "Scaling", meta = (DisplayName = "Scale Top"))
		float ScaleTopValue;
	float OldScaleTopValue;

	UPROPERTY(EditAnywhere, Category = "Scaling", meta = (DisplayName = "Scale Bottom"))
		float ScaleBotValue;
	float OldScaleBotValue;

	UPROPERTY(EditAnywhere, Category = "Scaling", meta = (DisplayName = "Scale Left"))
		float ScaleLeftValue;
	float OldScaleLeftValue;

	UPROPERTY(EditAnywhere, Category = "Scaling", meta = (DisplayName = "Scale Right"))
		float ScaleRightValue;
	float OldScaleRightValue;

	

	UFUNCTION(Exec)
		void CaptureRange();

	UFUNCTION(Exec)
		void ResetCapture();

	UFUNCTION(Exec)
		void Butterworth();

	UFUNCTION(Exec)
		void FilterKeys();

private:
	ULevelSequence * Sequencer = nullptr;
	UMovieScene3DTransformSection * TransformSection = nullptr;

	CustomTransform TransformToEdit;

	void GetInfoFromTransformSection(
		UMovieScene3DTransformSection * TransformSection, 
		float FromTime, 
		float ToTime, 
		CustomTransform& Transform, 
		TArray <float>& UnsortedTimes, 
		TArray <float>& UnsortedValues);

	void GetTransformAndCurves(TArray<TransformType>& TransformTypes, TArray<EAxis::Type>& Axises);

	TArray<TransformType> TransformTypes;
	TArray<EAxis::Type> Axises;


	float MinValue;
	float MaxValue;

	float MaxTime;
	float MinTime;
};


