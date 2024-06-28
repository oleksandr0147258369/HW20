#include<iostream>
#include<string.h>

using namespace std;

int func(char* str, char* word)
{
	int s_str = strlen(str), s_word = strlen(word);

	if (s_str < s_word) return 0;

	int n = 0;
	bool cont = 1;

	for (int i = 0; i <= s_str - s_word; i++)
	{
		cont = 1;
		for (int j = 0; j < s_word; j++)
		{
			cout << str[i + j] << " " << word[j] << endl;
			if (str[i + j] != word[j])
			{
				cont = 0;
				break;
			}
		}
		if (cont)
		{
			n++;
			i += s_word - 1;
		}
	}
	return n;
}

void func2(char* str)
{
	int s_str = strlen(str) + 1;
	cout << "Зайнято (враховуючи \\0): " << s_str << endl;
	cout << "Вильно: " << 500 - s_str << endl;
}


void CreateArr(char* str, int* size, char*& string)
{
	*size = strlen(str) + 1;
	string = new char[*size];

	for (int i = 0; i < *size; i++) string[i] = str[i];
}

bool needToDel(char symb, char* symbs)
{
	int size_symbs = strlen(symbs);
	for (int i = 0; i < size_symbs; i++) if (symbs[i] == symb) return true;
	return false;
}

void func3(char*& string, int* size, char* symbs)
{
	int new_size = 0;
	for (int i = 0; i < *size; i++) if (!needToDel(string[i], symbs)) new_size++;
	char* temp = new char[new_size];
	for (int i = 0, j = 0; i < *size; i++)
	{
		if (!needToDel(string[i], symbs))
		{
			temp[j] = string[i];
			j++;
		}
	}

	delete[] string;
	*size = new_size;
	string = temp;
}

int main()
{
	// Task 1
	/*char str[80], word[80];
	cout << "Input string: ";
	cin.getline(str, 80);

	cout << "Input word: ";
	cin.getline(word, 80);

	cout << func(str, word);*/

	// Task 2
	/*setlocale(LC_ALL, "RU");
	char str[500] = "";
	cout << "Введить рядок: ";
	cin.getline(str, 500);
	func2(str);*/

	// Task 3
	setlocale(LC_ALL, "RU");
	char str[500], symbs[500];
	char* string = NULL;
	int size = 0;

	cout << "Введiть рядок: ";
	cin.getline(str, 500);

	cout << "Введить символи, що треба видалити, пiдряд: ";
	cin.getline(symbs, 500);

	CreateArr(str, &size, string);

	func3(string, &size, symbs);
	cout << string;

	delete[] string;
	return 0;
}