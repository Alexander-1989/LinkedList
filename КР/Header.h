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
		cout << "������ ����.\n";
		return;
	}
	while (node)
	{
		cout << "����� �����: " << node->val.name << endl;
		cout << "���������� ��������� �� �������: " << node->val.count << endl;
		cout << "��� �����: " << node->val.index << endl;
		node = node->next;
	}
	cout << '\n';
}

void Add(List *lst)
{
	char ch = '�';
	while (strchr("��yY", ch))
	{
		Node *node = new Node();
		node->next = 0;

		cout << "������� ����� �����: ";
		cin.getline(node->val.name, 50);
		cout << "������� ��� �����: ";
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
		cout << "����� �������� ��� ���� ���� ������� � ��� � ��� y ��� Y. ��� ���������� ����� ����� ������ ������.\t";
		cin >> ch;
		cin.ignore();
	}
}

void Del(List *lst)
{
	if (!lst->Head)
	{
		cout << "������ ������� ������ ������.\n";
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
		cout << "������ ������.\n";
	}

	lst->Head = 0;
	lst->Tail = 0;
	lst = 0;
}

void Sort(List *lst)
{
	if (lst->Head == NULL)
	{
		cout << "������ ������������� ������ ������.\n";
		return;
	}

	cout << "������� '�' ����� ������������� ������ �� ������� ���,\n";
	cout << "'�' ����� ������������� ������ �� ���������� ��������� �� �������,\n";
	cout << "��� ����� ������ ������, ����� ������������� ������ �� �������� �����.\n";
	char ch = _getch();

	cout << "�� ������� " << ch << "\n";
	Node *currentNode = lst->Head;
	Node *nextNode = NULL;

	while (currentNode)
	{
		nextNode = currentNode->next;
		while (nextNode)
		{
			if (ch == '�')
			{
				if (nextNode->val.index > currentNode->val.index)
				{
					Swap(nextNode->val, currentNode->val);
				}
			}
			else if (ch == '�')
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
		cout << "������ ��������� ��������, ���� ������ ����.\n";
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

	cout << "������������ ��������� �� ������� � �����:\n";
	cout << "����� �����: " << value.name << endl;
	cout << "���������� ��������� �� �������: " << value.count << endl;
	cout << "��� �����: " << value.index << endl;
}


bool WriteToFile(List *lst)
{
	FILE *f = fopen(fileName, "wb");
	if (!lst->Head || f == NULL)
	{
		cout << "������ ���� ��� ���� ��� ������ �� ����� ���� ������.\n";
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
	cout << "���� �������.\n";
	return true;
}

bool ReadFromFile(List *lst)
{
	FILE *f = fopen(fileName, "rb");
	if (f == NULL)
	{
		cout << "���� ��� ������ �� ������.\n";
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
	cout << "���� �������.\n";
	return true;
}