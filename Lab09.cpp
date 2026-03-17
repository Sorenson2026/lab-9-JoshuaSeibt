// Joshua Seibt, 3/172026
// This program recieves the name of a file full of names from the user, reads the file, and outputs the alphabetically first and last names included in the file, as well as the number of names. 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Main is where the program deposites priority upon program start. Main includes the whole of this program's code, which is to recieve the name of a file full of names from the user, read the file, 
// and output the alphabetically first and last names included in the file, as well as the number of names. 

int main()
{
	// Greeting
	cout << "This program recieves the name of a file full of names from the user, reads the file, and outputs the alphabetically first and last names included in the file, as well as the number of names." << endl;
	string filename;
	cout << "Enter the file name: ";
	cin >> filename;

	ifstream inputFile;

	// tries to open the file, if it can't find it returns an error message
	inputFile.open(filename);

	if (!inputFile)
	{
		cout << "Error, file does not exist." << endl;
		return 0;
	}

	string name;
	string firstName, lastName;
	int count = 0;

	// Reads first name separately to initialize
	if (getline(inputFile, name))
	{
		firstName = name;
		lastName = name;
		count = 1;
	}

	// reads remaining names
	while (getline(inputFile, name))
	{
		count++;

		if (name < firstName)
			firstName = name;

		if (name > lastName)
			lastName = name;
	}

	inputFile.close();

	if (count == 0)
	{
		cout << "The file is empty." << endl;
	}
	else
	{
		cout << "First name alphabetically: " << firstName << endl;
		cout << "Last name alphabetically: " << lastName << endl;
		cout << "Total number of names: " << count << endl;
	}

	return 0;
}
