#ifndef PROCEDURAL_H
#define PROCEDURAL_H

#include <fstream>

using namespace std;

namespace Filippov
{
	struct Procedural
	{
		enum lang
		{
			PROCEDURAL,
			OOP,
			FUNCTIONAL
		} key;
		unsigned short int year_of_development;
		int reference;
		bool abstract_type;
	};

	void Procedural_Input(Procedural &obj, ifstream &fin);
	void Procedural_Output(Procedural &obj, ofstream &fout);
}

#endif // !PROCEDURAL_H