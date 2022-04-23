#include "string.h"

void TString::Set_String(char* _string)
{
	if (_string == 0) throw "Length of string == 0";
	length = Str_Len(_string) + 1;
	string = new char[length];
	for (int i = 0; i < length; i++)	string[i] = _string[i];
}

void TString::Set_Count_String_Of_Symbols(int count)
{
	countStringOfSymbols = count;
}

void TString::Set_Count_Of_Split(int count)
{
	countSplit = count;
}

void TString::Set_Count_Of_Find_Indexes(int count)
{
	countFinds = count;
}