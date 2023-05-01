// Fill out your copyright notice in the Description page of Project Settings.


#include "TagWatcher_WaitGameplayTag.h"

UTagWatcher_WaitGameplayTagAdded* UTagWatcher_WaitGameplayTagAdded::WaitForTagAddToActor(UAbilitySystemComponent* ASC, FGameplayTag Tag)
{
	UTagWatcher_WaitGameplayTagAdded* MyObj = NewObject<UTagWatcher_WaitGameplayTagAdded>();
	MyObj->ASC = ASC;
	MyObj->Tag = Tag;

	return MyObj;
}

void UTagWatcher_WaitGameplayTagAdded::BroadcastDelegate()
{
	Added.Broadcast();
}

void UTagWatcher_WaitGameplayTag::Activate()
{
	Super::Activate();

	if (ASC) // we always broadcast delegates
	{
		MyHandle = ASC->RegisterGameplayTagEvent(Tag).AddUObject(this, &UTagWatcher_WaitGameplayTag::GameplayTagCallback);

		if (ASC->GetTagCount(Tag) > 0)
		{
			BroadcastDelegate();
			EndAction();
		}
	}
	else
	{
		EndAction();
	}
}

void UTagWatcher_WaitGameplayTag::EndAction()
{
	if (ASC && MyHandle.IsValid())
	{
		ASC->RegisterGameplayTagEvent(Tag).Remove(MyHandle);
	}
}

void UTagWatcher_WaitGameplayTag::GameplayTagCallback(const FGameplayTag EvaluatedTag, int32 NewCount)
{
	if (NewCount == 1)
	{
		BroadcastDelegate();
		EndAction();
	}
}

void UTagWatcher_WaitGameplayTag::BroadcastDelegate()
{
}
