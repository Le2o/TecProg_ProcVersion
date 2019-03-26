#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Language.h"

namespace Filippov
{
	struct Node
	{
		Language *language;//указатель на объект списка
		Node *next;//указатель на следующий элемент в списке
		Node *prev;//указатель на предыдущий элемент в списке
	};

	struct Linked_List
	{
		Node *head;//указатель на первый элемент в связном списке
		Node *tail;//указатель на последний элемент в связном списке
		size_t size_list;//размер списка
	};

	void Init(Linked_List &obj);
	void Clear(Linked_List &obj);
	void Linked_List_Input(Linked_List &obj, ifstream &fin);
	void Linked_List_Output(Linked_List &obj, ofstream &fout);
	void Sort_List(Linked_List &obj);
	void Swap(Linked_List &obj, Node *first, Node *second);
	void Only_Procedural(Linked_List &obj, ofstream &fout);
	void Multi_Method(Linked_List &obj, ofstream &fout);
}

#endif