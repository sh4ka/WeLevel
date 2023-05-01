#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "TagWatcher_WaitGameplayTag.generated.h"

UCLASS(Abstract)
class WELEVEL_API UTagWatcher_WaitGameplayTag : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
protected:

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAsyncWaitGameplayTagDelegate);

	virtual void Activate() override;
	virtual void EndAction();

	virtual void GameplayTagCallback(const FGameplayTag Tag, int32 NewCount);
	virtual void BroadcastDelegate();
	
	UAbilitySystemComponent* ASC;
	FGameplayTag Tag;

	FDelegateHandle MyHandle;
};

UCLASS()
class WELEVEL_API UTagWatcher_WaitGameplayTagAdded : public UTagWatcher_WaitGameplayTag
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FAsyncWaitGameplayTagDelegate Added;

	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (BlueprintInternalUseOnly = "TRUE"))
	static UTagWatcher_WaitGameplayTagAdded* WaitForTagAddToActor(UAbilitySystemComponent* ASC, FGameplayTag Tag);

	virtual void BroadcastDelegate() override;
};