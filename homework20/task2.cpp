#include<iostream>
#include<string.h>

using namespace std;

void func(char* str)
{
	int s_str = strlen(str);
	cout << "�������: " << s_str << endl;
	cout << "������: " << 500 - s_str << endl;
}

int main()
{
	setlocale(LC_ALL, "RU");
	char str[500] = "";
	cout << "������� �����: ";
	cin.getline(str, 500);
	cout << str << endl;
	func(str);

	return 0;
}