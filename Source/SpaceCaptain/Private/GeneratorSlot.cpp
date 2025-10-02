

#include "GeneratorSlot.h"
#include "GameSettings.h"

void UGeneratorSlot::InitializeSlot(const FGeneratorData& mData)
{
	
	SlotData = mData;
	STRUCTURE = mData.STRUCTURE;
	
}
