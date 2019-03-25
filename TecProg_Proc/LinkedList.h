#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Language.h"

namespace Filippov
{
	struct Node
	{
		Language *language;
		Node *next;//��������� �� ��������� ������� � ������
		Node *prev;//��������� �� ���������� ������� � ������
	};

	struct LinkedList
	{
		Node *first;//��������� �� ������ ������� � ������� ������
		Node *last;//��������� �� ��������� ������� � ������� ������
		size_t size_list;
	};

	void Init(LinkedList &obj);
	void Clear(LinkedList &obj);
	void LinkedList_Input(LinkedList &obj, ifstream &fin);
	void LinkedList_Output(LinkedList &obj, ofstream &fout);

	void Multi_Method(LinkedList &obj, ofstream &fout);
}

#endif