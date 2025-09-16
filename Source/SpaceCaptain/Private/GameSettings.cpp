#include "GameSettings.h"

UGameSettings::UGameSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Large text for where settings should be grouped on the left
	CategoryName = "Space Captain";

	// Smaller sub-heading for grouping
	SectionName = "Database";
}