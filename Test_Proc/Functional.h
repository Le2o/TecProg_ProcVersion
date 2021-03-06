#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H

#include <fstream>

using namespace std;

namespace Filippov
{
	struct Functional
	{
		enum lang
		{
			PROCEDURAL,
			OOP,
			FUNCTIONAL
		} key;
		unsigned short int year_of_development;
		int reference;
		bool lazy_calculations;
		enum typification
		{
			STRICT,
			DYNAMIC
		} type;
	};

	void Functional_Input(Functional &obj, ifstream &fin);
	void Functional_Output(Functional &obj, ofstream &fout);
}

#endif // !FUNCTIONAL_H