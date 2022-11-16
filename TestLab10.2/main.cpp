#include "pch.h"
#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>

using namespace std;
void CreateTXT(char* fname) // створення файлу з введених рядків
{
	ofstream fout(fname); // відкрили файл для запису
	char ch; // відповідь користувача – чи продовжувати введення
	string s; // введений користувачем рядок
	do
	{
		cin.get(); // очищуємо буфер клавіатури – щоб не було символу
		cin.sync(); // "кінець рядка", який залишився після вводу числа
		cout << "enter line: "; getline(cin, s); // ввели рядок
		fout << s << endl; // записали його у файл
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}
int ProcessTXT3(char* fname)
{
	ifstream fin(fname); 
	char s[100];
	char* w;
	int k = 0;
	while (fin.getline(s, sizeof(s)))
	{
		w = strtok(s, " .,:;!?-'");
		while (w != NULL)
		{
			k++;
			cout << k << ": " << w << endl; 
			w = strtok(NULL, " .,:;!?-'");
		}
	}
	return k;
}
void PrintTXT(char* fname) // виведення файлу на екран
{
	ifstream fin(fname); // відкрили файл для зчитування
	string s; // прочитаний рядок
	while (getline(fin, s)) // поки можна прочитати рядок
	{
		if (s == "a")
		cout << s << endl; // виводимо його на екран
	}
	cout << endl;
}
int main()
{
	char fname[100];
	cout << "enter file name 1: "; cin >> fname;
	CreateTXT(fname); // ввели рядки файлу з клавіатури
	PrintTXT(fname); // вивели вміст першого файлу на екран
	return 0;
}
