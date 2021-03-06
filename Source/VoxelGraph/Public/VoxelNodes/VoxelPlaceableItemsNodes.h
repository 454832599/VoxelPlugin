// Copyright 2020 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelNodeHelper.h"
#include "VoxelNodeHelperMacros.h"
#include "VoxelPlaceableItemsNodes.generated.h"

class UVoxelGraphDataItemConfig;

UCLASS(DisplayName = "Data Item Sample", Category = "Placeable Items")
class VOXELGRAPH_API UVoxelNode_DataItemSample : public UVoxelNodeWithContext
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

	UVoxelNode_DataItemSample();
};

UCLASS(DisplayName = "Data Item Parameters", Category = "Placeable Items")
class VOXELGRAPH_API UVoxelNode_DataItemParameters : public UVoxelNodeWithContext
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "Config", meta = (ReconstructNode))
	UVoxelGraphDataItemConfig* Config;

	// If no parameters are provided these will be used
	UPROPERTY(EditAnywhere, Category = "Preview")
	TMap<FName, float> PreviewValues;

public:
	UVoxelNode_DataItemParameters();

	//~ Begin UVoxelNode Interface
	virtual void LogErrors(FVoxelGraphErrorReporter& ErrorReporter) override;
	virtual int32 GetOutputPinsCount() const override;
	virtual FName GetOutputPinName(int32 PinIndex) const override;
	EVoxelPinCategory GetOutputPinCategory(int32 PinIndex) const override;
	//~ End UVoxelNode Interface

#if WITH_EDITOR
	//~ Begin UObject Interface
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	//~ End UObject Interface
#endif

	TArray<v_flt> GetPreviewValues() const;
};