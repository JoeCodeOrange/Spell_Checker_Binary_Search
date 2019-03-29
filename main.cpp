//Name:Jose A. Elizondo
//Due:03/28/19
//Instructor: Dr. Ayati
//Homework: Create a Spellcheck program using binary search.

#include<iostream>
#include<string>
#include<fstream>
#include <ctime>

using namespace std;

bool spellChecker(string word, int size, string array[])
{
	int i = 0;
	int end = size;
	int middle = (size / 2) - 1;
	bool exists = true;

	while (exists)
	{
		if (array[middle] == word)
		{
			return true;
		}

		if (array[middle] < word)
		{
			i = middle + 1;
			middle = (end + i) / 2;
		}
		else if (array[middle] > word)
		{
			end = middle - 1;
			middle = (i + end) / 2;
		}

		if (i == middle || end == middle)
		{
			if (array[i] == word || array[end] == word)
			{
				return true;
			}
			else
				return false;
		}
	}
	return false;

}


int main()
{

	// Variables
	string word;
	char answer = 'y';
	double duration;

	clock_t start;
	ifstream inFile;
	int size = 202412;

	//Array of strings
	string * array = new string[size];

	//Open File
	inFile.open("largedictionary.txt");


	//Cannot Read File
	if (!inFile)
	{
		cout << "Sorry but we could not read the file." << endl;
	}

	//Load the dictionary into the array
	for (int i = 0; i < size; i++)
	{
		inFile >> array[i];
	}
	//Close the file
	inFile.close();

	////////// Binary Spell Checker //////////

	////Prompt user for word////
	
	while (answer == 'y' || answer == 'Y')
	{
		cout << "Please enter a word to test your spelling" << endl;
		cout << "Enter Word:";
		cin >> word;

		start = clock();
		if (spellChecker(word, size, array))
		{
			cout << "The word " << word << " is spelled correctly!" << endl;
		}

		if (!spellChecker(word, size, array))
		{
			cout << "WHOA! " << word << " is not a word! Bad human! Learn to spell!" << endl;
		}
		
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;

		cout << "RunTime: " << duration << '\n';

		cout << "Would you like to try again? Y/N:";
		cin >> answer;
	}

	cout << "Thank you for spell chacking" << endl;

	
	

	system("pause");
	return 0;
}