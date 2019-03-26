#include "LinkedList.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace Filippov;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}

	ifstream fin(argv[1]);
	if (!fin.is_open())
	{
		cout << "No input file found or could not open!" << endl;
		system("pause");
		return 1;
	}
	ofstream fout(argv[2]);
	if (!fin.is_open())
	{
		cout << "No output file found or could not open!" << endl;
		system("pause");
		return 1;
	}

	cout << "Start" << endl;

	Linked_List list;
	Init(list);
	Linked_List_Input(list, fin);
	fout << "Filled container." << endl;
	Linked_List_Output(list, fout);

	fout << endl << "Sorted Linked List." << endl;
	Sort_List(list);
	Linked_List_Output(list, fout);

	Multi_Method(list, fout);

	Only_Procedural(list, fout);

	Clear(list);
	fout << "Empty container." << endl;
	Linked_List_Output(list, fout);

	cout << "Stop" << endl;
	return 0;
}