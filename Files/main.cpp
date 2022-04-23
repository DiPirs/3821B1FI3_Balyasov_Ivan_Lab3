#include "string.h"

int main()
{
	char a[] = "I'm going to ";
	char A[] = "Lobachevsky University";
	TString str1;
	TString str2(A);
	TString str3(5, 'o');
	TString str4 = str2;
	TString* split;
	int** symbols;
	std::cout << "String: " << str3.Get_String() << "\n" << "Length: " << str3.Get_Length() << "\n";
	std::cout << "\n";

	str1.Set_String(a);
	str3 = A;
	str4 = str1 + str3;
	std::cout << str4;
	std::cout << "\n";

	std::cout << "Index of 't' in '" << str4 << "' == " << str4.Find('t') << "\t";
	std::cout << "\n";

	if (str2 == str3) std::cout << "str2 == str3\n";
	if (str1 < str3) std::cout << "str1 < str3\n";
	if (str2 > str4) std::cout << "str2 > str4\n";
	std::cout << "\n";

	std::cout << "str2.string[0] == " << str2[0] << std::endl;
	std::cout << "\n";

	split = str1.Split(' ');
	for (int i = 0; i < str1.Get_Count_Of_Split(); i++)
	{
		std::cout << split[i] << "\n";
	}
	std::cout << "\n";

	str1 += str3;
	str2 = str1.DoubleStr(2);

	std::cout << str2 << "\n";
	std::cout << "\n";

	int* indexes = str2.Find(str3);
	std::cout << "Indexes of   '" << str3 << "'   in   '" << str2 << "'   ==  ";
	for (int i = 0; i < str2.Get_Count_Of_Find_Indexes(); i++)
		std::cout << indexes[i] << "  ";
	std::cout << "\n";

	std::cout << "Most popular symbol in '" << str3 << "' is: '" << str3.Most_Popular_Symbol() << "'\n";
	std::cout << "\n";

	symbols = str3.String_Of_Symbols();
	std::cout << "String of symbols in '" << str3 << "' is:\n";

	for (int i = 0; i < str3.Get_Count_String_Of_Symbols(); i++)
		std::cout << "'" << char(symbols[i][0]) << "' - " << symbols[i][1] << "\n";
	std::cout << "\n";

	for (int i = 0; i < str3.Get_Count_String_Of_Symbols(); i++)
		delete[] symbols[i];
	delete[] symbols;
	delete[] indexes;
	return 0;
}