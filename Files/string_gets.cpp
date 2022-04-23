#include "string.h"

char* TString::Get_String()
{
	return string;
}

int TString::Get_Length()
{
	return length;
}

int TString::Get_Count_Of_Split()
{
	return countSplit;
}

int TString::Get_Count_Of_Find_Indexes()
{
	return countFinds;
}

int TString::Get_Count_String_Of_Symbols()
{
	return countStringOfSymbols;
}