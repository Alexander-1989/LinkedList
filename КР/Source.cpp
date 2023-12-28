/*
��� - ������������ ������ �����������.
������������ ������ ������ ������ � �� ���. ������ � ������ ����� ����������� � ��������
������������ ���������. �� ������� ������������ ������ ������������ � ����, ��� ���� ������,
���������� ��� ������������ ���������, ��������������. ����� ������������ ����� ����� ������
������� ���������� � ������, ���� ��������� ���������� ���������.
*/
#include <iostream>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include "Header.h"
#include <iomanip>
using namespace std;

void help()
{
	cout << "������� 1 - ����� ������� ���� ���������.\n";
	cout << "������� � - ����� �������� ����.\n";
	cout << "������� � - ����� �������� ������ �� �����.\n";
	cout << "������� � - ����� �������� ������ � ����.\n";
	cout << "������� � - ����� �������� ������.\n";
	cout << "������� � - ����� ������� ������.\n";
	cout << "������� � - ����� ������������� ������.\n";
	cout << "������� � - ����� ���������� ���� � ���������� ����������� ���������.\n";
	cout << "������� � - ����� �������� �������.\n";
	cout << "������� � - ����� �����.\n";
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned)time(0));

	List lst;
	char ch;
	bool status = true;

	help();

	while (status)
	{
		ch = _getch();
		switch (ch)
		{
			case '1':
			{
				help();
				break;
			}
			case '�':
			{
				Add(&lst);
				ShowList(&lst); 
				break;
			}
			case '�':
			{
				ReadFromFile(&lst);
				ShowList(&lst);
				break;
			}
			case '�':
			{
				WriteToFile(&lst);
				break;
			}
			case '�':
			{
				ShowList(&lst);
				break;
			}
			case '�':
			{
				Del(&lst);
				break;
			}
			case '�':
			{
				Sort(&lst);
				ShowList(&lst);
				break;
			}
			case '�':
			{
				MaxCount(&lst);
				break;
			}
			case '�':
			{
				system("cls");
				break;
			}
			case '�':
			{
				Del(&lst);
				status = false;
				break;
			}
		}
	}
	return 0;
}