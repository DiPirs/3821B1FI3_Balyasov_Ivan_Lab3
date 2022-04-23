#include "string.h"

TString TString::operator+(const char* s)
{
	if (s == 0) return *this;
	TString A;
	int len = length + Str_Len(s);
	A.string = new char[len];
	A.length = len;
	for (int i = 0; i < length - 1; i++)	A.string[i] = string[i];
	for (int j = length - 1; j < len; j++)  A.string[j] = s[j - length + 1];
	return A;
}

TString TString::operator+(const TString& p)
{
	if (p.string == 0) return *this;
	TString A;
	int len = length + p.length - 1;
	A.string = new char[len];
	A.length = len;
	for (int i = 0; i < length - 1; i++)	A.string[i] = string[i];
	for (int j = length - 1; j < len; j++)  A.string[j] = p.string[j - length + 1];
	return A;
}

TString& TString::operator=(const TString& p)
{
	if (this == &p) return *this;
	if (string != 0)  delete[] string;
	length = p.length;
	string = new char[length];
	for (int i = 0; i < length; i++)	string[i] = p.string[i];
	return *this;
}

TString& TString::operator=(const char* s)
{
	if (string != 0) delete[] string;
	length = Str_Len(s) + 1;
	string = new char[length];
	for (int i = 0; i < length; i++)	string[i] = s[i];
	return *this;
}

TString& TString::operator+=(const char* s)
{
	if (Str_Len(s) == 0) return *this;
	int len = length + Str_Len(s);
	char* c = new char[len];
	for (int i = 0; i < length - 1; i++)	c[i] = string[i];
	for (int j = length; j < len; j++)  c[j] = s[j - length + 1];
	if (string != 0)  delete[] string;
	string = c;
	length = len;
	return *this;
}

TString& TString::operator+=(const TString& p)
{
	if (Str_Len(p.string) == 0) return *this;
	int len = length + p.length - 1;
	char* c = new char[len];
	for (int i = 0; i < length - 1; i++)	c[i] = string[i];
	for (int j = length - 1; j < len; j++)  c[j] = p.string[j - length + 1];
	if (string != 0)  delete[] string;
	string = c;
	length = len;
	return *this;
}

bool TString::operator==(TString& p)
{
	if (length != p.length) return false;
	for (int i = 0; i < length; i++)
	{
		if (string[i] != p.string[i]) return false;
	}
	return true;
}

bool TString::operator<(TString& p)
{
	int len = length > p.length ? p.length : length;
	for (int i = 0; i < len; i++)
	{
		if (string[i] < p.string[i]) return true;
		else if (string[i] > p.string[i]) return false;
	}
	if (length >= p.length) return false;
	else return true;
}

bool TString::operator>(TString& p)
{
	int len = length > p.length ? p.length : length;
	for (int i = 0; i < len; i++)
	{
		if (string[i] < p.string[i]) return false;
		else if (string[i] > p.string[i]) return true;
	}
	if (length >= p.length) return true;
	else return false;
}

std::ostream& operator<<(std::ostream& B, TString& A)
{
	for (int i = 0; i < A.length; i++)  B << A.string[i];
	return B;
}

std::istream& operator>>(std::istream& B, TString& A)
{
	B >> A.length;
	A.length++;
	if (A.string != 0) delete[] A.string;
	A.string = new char[A.length];
	for (int i = 0; i < A.length - 1; i++)  B >> A.string[i];
	A.string[A.length - 1] = '\0';
	return B;
}

char& TString::operator[](int n)
{
	if (string == 0) throw "String is empty";
	if (n > length - 1 || n < 0) throw "Out of range";
	return string[n];
}