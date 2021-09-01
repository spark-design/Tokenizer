#include "Tokenizer.h"
#include <fstream>
#include <cmath>

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;


bool processText(istream& is, bool interactive = true)
{
	// implement support for 
	// exit ... exit the program
	// load file ... loads a file containing supported commands
	string line;
	string command;

	int intArg1;
	string strArg1;
	double doubArg1, doubArg2;
	char charArg1;

	Tokenizer tkn;
	
	while (true)
	{
		if (!interactive)
		{
			if (is.eof()) return true;
		}
		else { cout << ">> "; }

		getline(is, line);
		tkn.setString(line);

		tkn.readString(command);
		if (command == "exit")
		{
			cout << "Exiting ...." << endl;
			return false;
		}
		if (command == "load")
		{
			// load expects a filename .. so read one more word
			if (!tkn.readString(strArg1)) {
				cout << "Missing file name" << endl;
				continue; // skip back to the top of the read loop
			}
			ifstream fin;
			bool status = true;
			fin.open(strArg1);
			if (fin.is_open())
			{
				status = processText(fin, false);
			}
			else { cout << "Failed to open the file" << endl; }
			fin.close();
			if (!status) return false;
		}
		if (command == "checkInt")
		{
			if (tkn.readInteger(intArg1))
				cout << "Input is an Integer." << endl;
			else
				cout << "Expected an Integer." << endl;
		}
		if (command == "checkString")
		{
			if (tkn.readString(strArg1))
				cout << "Input is a String." << endl;
			else
				cout << "Expected a String." << endl;
		}
		if (command == "checkDouble")
		{
			if (tkn.readDouble(doubArg1))
				cout << "Input is a Double." << endl;
			else
				cout << "Expected a Double." << endl;
		}
		if (command == "checkChar")
		{
			if (tkn.readChar(charArg1))
				cout << "Input is a Char." << endl;
			else
				cout << "Expected a Char." << endl;
		}

		/* My 3 commands are :
		- doubleDouble: Doubles the double you input
		- sixtyNine: Tells you how far your value is from 69
		- absValue: Gives you the absolute value of your number
		*/

		if (command == "doubleDouble")
		{
			if (tkn.readDouble(doubArg1))
			{
				cout << "Double of your double is: " << doubArg1 + doubArg1 << endl;
			}
		}
		if (command == "sixtyNine")
		{
			if (tkn.readDouble(doubArg1))
			{
				cout << "Your number is " << abs(doubArg1 - 69) << " away from 69. Nice." << endl;
			}
		}
		if (command == "absValue")
		{
			if (tkn.readDouble(doubArg1))
			{
				cout << "The absolute value of your number is: " << abs(doubArg1) << endl;
			}
		}
	}
}


int main()
{

	processText(cin);
	return 0;

}