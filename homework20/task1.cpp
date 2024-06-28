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

int main()
{
	char str[80], word[80];
	cout << "Input string: ";
	cin.getline(str, 80);

	cout << "Input word: ";
	cin.getline(word, 80);

	cout << func(str, word);

	return 0;
}