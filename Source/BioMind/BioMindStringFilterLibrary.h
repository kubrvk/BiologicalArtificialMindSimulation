// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BioMindStringFilterLibrary.generated.h"

/**
 * TTS'e gönderilecek metinleri sadece harf, rakam ve izin verilen noktalama
 * işaretlerine indirgeyen yardımcı fonksiyonlar.
 */
UCLASS()
class BIOMIND_API UBioMindStringFilterLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// Harf, rakam, boşluk ve ? ! . , - dışındaki tüm karakterleri (emoji, markdown, özel işaretler vb.) siler.
	UFUNCTION(BlueprintCallable, Category = "TTS|Filter")
	static FString FilterForTTS(const FString& InText);
};
