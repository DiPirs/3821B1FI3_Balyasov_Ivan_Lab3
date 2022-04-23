#pragma once
#include <iostream>

class TString
{
public:

	TString();
	TString(char* _string);
	TString(int len, char c);
	TString(const TString& p);
	~TString();

	char* Get_String();
	void Set_String(char* _string);
	int Get_Length();

	int Str_Len(const char* str);
	int Find(char ñ);
	int* Find(TString& p);

	int Get_Count_Of_Split();
	int Get_Count_Of_Find_Indexes();
	int Get_Count_String_Of_Symbols();

	TString* Split(char c);

	TString operator + (const char* s);
	TString operator + (const TString& p);
	TString& operator = (const TString& p);
	TString& operator = (const char* s);
	TString& operator += (const char* s);
	TString& operator += (const TString& p);

	bool operator == (TString& p);
	bool operator < (TString& p);
	bool operator > (TString& p);

	char& operator [] (int n);

	friend std::ostream& operator << (std::ostream& B, TString& A);
	friend std::istream& operator >> (std::istream& B, TString& A);

	TString& DoubleStr(int k);

	char Most_Popular_Symbol();

	int** String_Of_Symbols();

protected:

	char* string;

	int length;
	int countSplit;
	int countFinds;
	int countStringOfSymbols;

	void Set_Count_String_Of_Symbols(int count);
	void Set_Count_Of_Split(int count);
	void Set_Count_Of_Find_Indexes(int count);
};