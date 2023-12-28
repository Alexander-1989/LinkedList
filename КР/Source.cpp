/*
ТИЦ - тематический индекс цитирования.
Пользователь вводит адреса сайтов и их ТИЦ. Данные о каждом сайте сохраняются в элементе
динамической структуры. По команде пользователя данные записываются в файл, при этом память,
выделенная под динамическую структуру, высвобождается. Далее пользователь может снова начать
вводить информацию о сайтах, либо завершить выполнение программы.
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
	cout << "Нажмите 1 - чтобы вызвать меню подсказки.\n";
	cout << "Нажмите д - чтобы добавить сайт.\n";
	cout << "Нажмите ч - чтобы прочесть список из файла.\n";
	cout << "Нажмите з - чтобы записать список в файл.\n";
	cout << "Нажмите п - чтобы показать список.\n";
	cout << "Нажмите у - чтобы удалить список.\n";
	cout << "Нажмите с - чтобы отсортировать список.\n";
	cout << "Нажмите м - чтобы отобразить сайт с наибольшим количеством посещений.\n";
	cout << "Нажчите о - чтобы очистить консоль.\n";
	cout << "Нажмите в - чтобы выйти.\n";
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
			case 'д':
			{
				Add(&lst);
				ShowList(&lst); 
				break;
			}
			case 'ч':
			{
				ReadFromFile(&lst);
				ShowList(&lst);
				break;
			}
			case 'з':
			{
				WriteToFile(&lst);
				break;
			}
			case 'п':
			{
				ShowList(&lst);
				break;
			}
			case 'у':
			{
				Del(&lst);
				break;
			}
			case 'с':
			{
				Sort(&lst);
				ShowList(&lst);
				break;
			}
			case 'м':
			{
				MaxCount(&lst);
				break;
			}
			case 'о':
			{
				system("cls");
				break;
			}
			case 'в':
			{
				Del(&lst);
				status = false;
				break;
			}
		}
	}
	return 0;
}