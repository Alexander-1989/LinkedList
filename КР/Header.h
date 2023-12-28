#include <iostream>
#include <fstream>
using namespace std;

const char* fileName = "info.dat";

struct info
{
	char name[50];
	int count;
	int index;
};

struct Node
{
	info val;
	Node *next;
};

struct List
{
	Node *Head = 0;
	Node *Tail = 0;
};

int Random(const int &min, const int &max)
{
	return (rand() % (max - min)) + min;
}

template<typename T> void Swap(T &a, T &b)
{
	T t = move(a);
	a = move(b);
	b = move(t);
}

void ShowList(List *lst)
{
	const Node *node = lst->Head;
	if (node == NULL)
	{
		cout << "Список пуст.\n";
		return;
	}
	while (node)
	{
		cout << "Адрес сайта: " << node->val.name << endl;
		cout << "Количество посещений за сегодня: " << node->val.count << endl;
		cout << "ТИЦ сайта: " << node->val.index << endl;
		node = node->next;
	}
	cout << '\n';
}

void Add(List *lst)
{
	char ch = 'д';
	while (strchr("дДyY", ch))
	{
		Node *node = new Node();
		node->next = 0;

		cout << "Введите адрес сайта: ";
		cin.getline(node->val.name, 50);
		cout << "Введите ТИЦ сайта: ";
		cin >> node->val.index;
		node->val.count = Random(0, 500);

		if (!lst->Head && !lst->Tail)
		{
			lst->Head = node;
			lst->Tail = node;
		}
		else
		{
			lst->Tail->next = node;
			lst->Tail = node;
		}

		system("cls");
		cout << "Чтобы добавить еще один сайт введите д или Д или y или Y. Для завершения ввода любой другой символ.\t";
		cin >> ch;
		cin.ignore();
	}
}

void Del(List *lst)
{
	if (!lst->Head)
	{
		cout << "Нельзя удалить пустой список.\n";
		return;
	}

	Node *node;
	while (lst->Head)
	{
		node = lst->Head;
		lst->Head = lst->Head->next;
		delete node;
	}

	if (lst->Head == NULL)
	{
		cout << "Список удален.\n";
	}

	lst->Head = 0;
	lst->Tail = 0;
	lst = 0;
}

void Sort(List *lst)
{
	if (lst->Head == NULL)
	{
		cout << "Нельзя отсортировать пустой список.\n";
		return;
	}

	cout << "Нажмите 'т' чтобы отсортировать список по индексу ТИЦ,\n";
	cout << "'к' чтобы отсортировать список по количеству посещений за сегодня,\n";
	cout << "или любой другой символ, чтобы отсортировать список по названию сайта.\n";
	char ch = _getch();

	cout << "Вы выбрали " << ch << "\n";
	Node *currentNode = lst->Head;
	Node *nextNode = NULL;

	while (currentNode)
	{
		nextNode = currentNode->next;
		while (nextNode)
		{
			if (ch == 'т')
			{
				if (nextNode->val.index > currentNode->val.index)
				{
					Swap(nextNode->val, currentNode->val);
				}
			}
			else if (ch == 'к')
			{
				if (nextNode->val.count > currentNode->val.count)
				{
					Swap(nextNode->val, currentNode->val);
				}
			}
			else
			{
				if (strcmp(nextNode->val.name, currentNode->val.name) < 0)
				{
					Swap(nextNode->val, currentNode->val);
				}
			}
			nextNode = nextNode->next;
		}
		currentNode = currentNode->next;
	}
}

void MaxCount(List *lst)
{
	if (lst->Head == NULL)
	{
		cout << "Нельзя посчитать максимум, если список пуст.\n";
		return;
	}

	const Node *node = lst->Head;
	info value = lst->Head->val;

	while (node)
	{
		if (node->val.count > value.count)
		{
			value = node->val;
		}
		node = node->next;
	}

	cout << "Максимальное посещение за сегодня у сайта:\n";
	cout << "Адрес сайта: " << value.name << endl;
	cout << "Количество посещений за сегодня: " << value.count << endl;
	cout << "ТИЦ сайта: " << value.index << endl;
}


bool WriteToFile(List *lst)
{
	FILE *f = fopen(fileName, "wb");
	if (!lst->Head || f == NULL)
	{
		cout << "Список пуст или файл для записи не может быть создан.\n";
		return false;
	}

	info value;
	while (lst->Head)
	{
		value = lst->Head->val;
		fwrite(&value, sizeof(value), 1, f);
		lst->Head = lst->Head->next;
	}

	fclose(f);
	cout << "Файл записан.\n";
	return true;
}

bool ReadFromFile(List *lst)
{
	FILE *f = fopen(fileName, "rb");
	if (f == NULL)
	{
		cout << "Файл для чтения не найден.\n";
		return false;
	}

	Node *node;
	info value;

	while (fread(&value, sizeof(value), 1, f))
	{
		node = new Node();
		node->val = value;
		node->next = 0;

		if (lst->Head == NULL)
		{
			lst->Head = node;
			lst->Tail = node;
		}
		else
		{
			lst->Tail->next = node;
			lst->Tail = node;
		}
	}

	fclose(f);
	cout << "Файл прочтен.\n";
	return true;
}