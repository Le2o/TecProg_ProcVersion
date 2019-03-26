#include "LinkedList.h"

void Filippov::Init(Linked_List &obj)
{
	obj.head = NULL;
	obj.tail = NULL;
	obj.size_list = 0;
}

void Filippov::Clear(Linked_List &obj)
{
	Node *temp = NULL;
	while (obj.tail != NULL)
	{
		temp = obj.tail->prev;
		delete obj.tail;
		obj.tail = temp;
		--obj.size_list;
	}
	obj.head = temp;
}

void Filippov::Linked_List_Input(Linked_List &obj, ifstream &fin)
{
	Node *temp;
	while (!fin.eof())
	{
		temp = new Node;

		temp->language = Language_Input(fin);
		if (temp->language == NULL)
		{
			continue;
		}
		temp->next = NULL;
		++obj.size_list;

		if (obj.head == NULL)//если список пустой
		{
			temp->prev = NULL;
			obj.head = obj.tail = temp;
		}
		else//если в списке есть хотя бы 1 элемент
		{
			temp->prev = obj.tail;
			obj.tail->next = temp;
			obj.tail = temp;
		}
	}
}

void Filippov::Linked_List_Output(Linked_List &obj, ofstream &fout)
{
	Node *current = obj.head;
	fout << "Container contains " << obj.size_list << " elements." << endl;

	for (size_t i = 0; i < obj.size_list; i++)
	{
		fout << i + 1 << ": ";
		Language_Output(*current->language, fout);
		fout << "The number of years that have passed since the year the language was created = "
			<< Past_Years(*current->language) << endl;
		current = current->next;
	}
}

void Filippov::Sort_List(Linked_List &obj)
{
	if (obj.size_list < 2)
	{
		return;
	}

	Node *current = obj.head;
	bool flag = false;

	do
	{
		current = obj.head;
		flag = false;
		for (size_t i = 0; i < (obj.size_list - 1); ++i)
		{
			if (Compare(current->language, current->next->language))
			{
				Swap(obj, current, current->next);
				flag = true;
			}
			else
			{
				current = current->next;
			}
		}
	} while (flag);
}

void Filippov::Swap(Linked_List &obj, Node *first, Node *second)
{
	if ((first->prev == NULL) && (second->next == NULL))//если в списке всего 2 элемента, но нам приспичило поменять их местами
	{
		obj.head = second;
		obj.tail = first;
		first->prev = second;
		second->next = first;
		first->next = NULL;
		second->prev = NULL;
		return;
	}
	//если мы меняем местами первый и второй элемент списка, в котором 3 и более элементов !(first->prev)
	if ((first->prev == NULL) && (second->next != NULL))
	{
		first->next = second->next;
		first->prev = second;
		second->next->prev = first;
		second->next = first;
		second->prev = NULL;
		obj.head = second;
		return;
	}
	//если мы меняем местами предпоследний и последний элемент списка, в котором 3 и более элементов !(second->next)
	if ((first->prev != NULL) && (second->next == NULL))
	{
		second->prev = first->prev;
		first->prev = second;
		first->next = NULL;
		second->next = first;
		second->prev->next = second;
		obj.tail = first;
		return;
	}
	/*
	если мы меняем каких-то два элемента, находящихся в середине списка, в котором 4 и более элемента
	(например второй и третий, если в списке 4 элемента)
	*/
	if ((first->prev != NULL) && (second->next != NULL))
	{
		first->next = second->next;
		second->prev = first->prev;
		second->next = first;
		first->prev = second;
		second->prev->next = second;
		first->next->prev = first;
		return;
	}
}

void Filippov::Only_Procedural(Linked_List &obj, ofstream &fout)
{
	Node *current = obj.head;
	fout << endl << "Only Procedural languages." << endl;

	for (size_t i = 0; i < obj.size_list; i++)
	{
		fout << i + 1 << ": ";
		if (current->language->key == Language::lang::PROCEDURAL)
		{
			Language_Output(*current->language, fout);
		}
		else
		{
			fout << endl;
		}
		current = current->next;
	}
	fout << endl;
}

void Filippov::Multi_Method(Linked_List &obj, ofstream &fout)
{
	Node *current_first = obj.head;
	Node *current_second = current_first->next;

	fout << endl << "Multimethod." << endl;
	for (size_t i = 0; i < obj.size_list - 1; i++)
	{
		for (size_t j = i + 1; j < obj.size_list; j++)
		{
			switch (current_first->language->key)
			{
			case Language::lang::PROCEDURAL:
				switch (current_second->language->key)
				{
				case Language::lang::PROCEDURAL:
					fout << "Procedural and Procedural." << endl;
					break;
				case Language::lang::OOP:
					fout << "Procedural and OOP." << endl;
					break;
				case Language::lang::FUNCTIONAL:
					fout << "Procedural and Functional." << endl;
					break;
				default:
					fout << "Unknown type." << endl;
					break;
				}
				break;
			case Language::lang::OOP:
				switch (current_second->language->key)
				{
				case Language::lang::PROCEDURAL:
					fout << "OOP and Procedural." << endl;
					break;
				case Language::lang::OOP:
					fout << "OOP and OOP." << endl;
					break;
				case Language::lang::FUNCTIONAL:
					fout << "OOP and Functional." << endl;
					break;
				default:
					fout << "Unknown type." << endl;
					break;
				}
				break;
			case Language::lang::FUNCTIONAL:
				switch (current_second->language->key)
				{
				case Language::lang::PROCEDURAL:
					fout << "Functional and Procedural." << endl;
					break;
				case Language::lang::OOP:
					fout << "Functional and OOP." << endl;
					break;
				case Language::lang::FUNCTIONAL:
					fout << "Functional and Functional." << endl;
					break;
				default:
					fout << "Unknown type." << endl;
					break;
				}
				break;
			default:
				fout << "Unknown type." << endl;
				break;
			}
			Language_Output(*current_first->language, fout);
			Language_Output(*current_second->language, fout);
			current_second = current_second->next;
		}
		current_first = current_first->next;
		current_second = current_first->next;
	}
}