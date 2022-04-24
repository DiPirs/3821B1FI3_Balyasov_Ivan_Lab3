#include "string.h"

TString::TString()
{
	length = 0;
	string = 0;
	countSplit = 0;
	countFinds = 0;
	countStringOfSymbols = 0;
}

TString::TString(char* _string) : TString()
{
	if (_string == 0) throw "Length of string == 0";
	length = Str_Len(_string) + 1;
	string = new char[length];
	for (int i = 0; i < length; i++)	string[i] = _string[i];
}

TString::TString(int len, char c) : TString()
{
	if (len <= 0) throw "Length of string == 0";
	length = len + 1;
	string = new char[length];
	for (int i = 0; i < len; i++)  string[i] = c;
	string[len] = '\0';
}

TString::TString(const TString& p)
{
	countStringOfSymbols = p.countStringOfSymbols;
	countSplit = p.countSplit;
	countFinds = p.countFinds;
	length = p.length;
	string = new char[length];
	for (int i = 0; i < length; i++)	string[i] = p.string[i];
}

TString::~TString()
{
	if (string != 0)
	{
		delete[] string;
		string = 0;
	}
	length = 0;
	countSplit = 0;
	countFinds = 0;
	countStringOfSymbols = 0;
}

int TString::Str_Len(const char* str)
{
	int i = 0;
	while (str[i] != '\0')  i++;
	return i;
}

int TString::Find(char c)
{
	for (int i = 0; i < length - 1; i++)	if (string[i] == c) return i;
	return -1;
}

int* TString::Find(TString& p)
{
	int* tmp = new int[length - 1];
	int count = 0;
	int k = 0;
	if (p.length > length)  throw "Word size is too big";
	for (int i = 0; i < length; i++)
	{
		bool flag = 1;
		for (int j = 0; j < p.length - 1; j++)
		{
			if (string[i + j] != p.string[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			tmp[k] = i;
			k++;
			count++;
		}
	}
	if (k == 0) throw "No entry";
	int* ind = new int[count];
	for (int i = 0; i < count; i++)	ind[i] = tmp[i];
	delete[] tmp;
	Set_Count_Of_Find_Indexes(count);
	return ind;
}

TString* TString::Split(char c)
{
	int count = 0;
	for (int i = 0; i < length - 1; i++)	if (string[i] == c)	count++;
	if (count == 0) return this;
	count++;
	TString* strings = new TString[count];
	int start = 0;
	int index = 0;
	for (int i = 0; i < length; i++)
	{
		if (string[i] == c)
		{
			strings[index].length = i - start + 1;
			delete[] strings[index].string;
			strings[index].string = new char[strings[index].length];
			for (int j = 0; j < strings[index].length - 1; j++)  strings[index].string[j] = string[j + start];
			strings[index].string[strings[index].length - 1] = '\0';
			index++;
			start = i + 1;
		}
	}
	strings[index].length = length - start;
	delete[] strings[index].string;
	strings[index].string = new char[strings[index].length];
	for (int k = 0; k < strings[index].length; k++)  strings[index].string[k] = string[k + start];
	index++;
	Set_Count_Of_Split(count);
	return strings;
}

TString& TString::DoubleStr(int k)
{
	if (string == 0) throw "String is empty";
	int length = Str_Len(string) * k + 1;
	char* str = new char[length];
	int start = 0;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < this->length - 1; j++)
		{
			str[j + start] = string[j];
		}
		start = Str_Len(string) * (i + 1);
	}
	str[length - 1] = '\0';
	delete[] string;
	string = str;
	this->length = length;
	return *this;
}

char TString::Most_Popular_Symbol()
{
	if (string == 0) throw "String is empty";
	int symb[128] = { 0 };
	int index = 0;
	int count = 0;
	for (int i = 0; i < length - 1; i++)  symb[int(string[i])]++;
	for (int j = 0; j < 128; j++)
		if (symb[j] > count)
		{
			index = j;
			count = symb[j];
		}

	return index;
}

int** TString::String_Of_Symbols()
{
	if (string == 0) throw "String is empty";
	int symb[128] = { 0 };
	int index = 0;
	int count = 0;

	for (int i = 0; i < length - 1; i++)
	{
		symb[int(string[i])]++;
		if (symb[int(string[i])] == 1)
		{
			count++;
		}
	}
	int** res = new int* [count];
	int k = 0;
	for (int j = 0; j < length; j++)
	{
		if (symb[int(string[j])] > 0)
		{
			res[k] = new int[2];
			res[k][0] = string[j];
			res[k][1] = symb[int(string[j])];
			symb[int(string[j])] = 0;
			k++;
		}
	}
	Set_Count_String_Of_Symbols(count);
	return res;
}
