// Fill out your copyright notice in the Description page of Project Settings.

#include "BioMindStringFilterLibrary.h"

FString UBioMindStringFilterLibrary::FilterForTTS(const FString& InText)
{
	FString Result;
	Result.Reserve(InText.Len());

	for (const TCHAR& Ch : InText)
	{
		const bool bIsAlphaNumeric = FChar::IsAlpha(Ch) || FChar::IsDigit(Ch);
		const bool bIsSpace = FChar::IsWhitespace(Ch);
		const bool bIsAllowedPunct =
			Ch == TEXT('!') || Ch == TEXT('?') ||
			Ch == TEXT('.') || Ch == TEXT(',') ||
			Ch == TEXT('-');

		if (bIsAlphaNumeric || bIsSpace || bIsAllowedPunct)
		{
			Result.AppendChar(Ch);
		}
	}

	// Ardışık boşlukları teke indir
	while (Result.Contains(TEXT("  ")))
	{
		Result = Result.Replace(TEXT("  "), TEXT(" "));
	}

	return Result.TrimStartAndEnd();
}
