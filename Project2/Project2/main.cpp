/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   main.cpp
* Author: brickr
*
* Created on February 18, 2017, 11:32 PM
*/


#include <iostream>
#include <string> //for string handling
#include <cstdlib> //for string conversion
#include <fstream> //for advanced file operations - ifstream
#include <vector> //for vector operations
#include <new> //for bad_alloc error
#include <list> //for list operations
//#include <iomanip>

#include "Polynomial.h"
//#include "Polynomial.cpp"

using namespace std;

/*
*
*/
int openFile(ifstream &inputFile)
{
	string fileIn;

	cout << "Enter the name of the file you wish to use: ";
	//cin >> fileIn;
	fileIn = "file1.txt";
	cout << fileIn << endl;

	inputFile.open(fileIn);

	/*
	//void showState(fstream &file)
	{
		cout << "File Status:\n";
		cout << " eof bit: " << inputFile.eof() << endl;
		cout << " fail bit: " << inputFile.fail() << endl;
		cout << " bad bit: " << inputFile.bad() << endl;
		cout << " good bit: " << inputFile.good() << endl;
		//inputFile.clear(); // Clear any bad bits
	}
	*/

	if (inputFile.fail())
	{
		cerr << "File error. Either the file could not be opened or could not "
			<< "be found with the path specified.\nThe program will now close.\n";

		//Temp testing
		int FAIL;
		cout << "FAIL!\n";
		cin >> FAIL;

		//void showState(fstream &file)
		{
			cout << "File Status:\n";
			cout << " eof bit: " << inputFile.eof() << endl;
			cout << " fail bit: " << inputFile.fail() << endl;
			cout << " bad bit: " << inputFile.bad() << endl;
			cout << " good bit: " << inputFile.good() << endl;
			inputFile.clear(); // Clear any bad bits
		}
		//end temp testing

		return 0;
	}
	else
	{
		return 1;
	}
}

int readFile(ifstream &inputFile1, string dataIn1, int &primaryIndex1)
{
	//string dataIn1;

	if (dataIn1 == "print")
	{
		return 1;
	}
	else if (dataIn1 == "eval")
	{
		return 2;
	}
	else
	{
		//int primaryIndex;
		char symbol;
		primaryIndex1 = atoi(dataIn1.c_str());
		//cout << "\nprimaryIndex: " << primaryIndex1 << endl;

		inputFile1 >> symbol;

		if (symbol == ':') //Form expected is k : c1 e1 c2 e2...cn en
		{
			return 3;
		}
		else //symbol is =, therefore form expected is n = m * k
		{
			return 4;
		}
	}
	return 0;
}
void processPrint(ifstream &inputFile)
{
	int primaryIndex;

	inputFile >> primaryIndex;
	cout << "PRINT " << primaryIndex << endl;
	//Do Print func call here
}
void processEval(ifstream &inputFile)
{
	int primaryIndex1;
	string dataInput1;
	double evalArgument;

	inputFile >> primaryIndex1;

	while (inputFile.peek() != '\n')
	{
		inputFile >> dataInput1;

		if (dataInput1 == "(")
		{
			inputFile.ignore();
			//inputFile.clear();
		}
		else if (dataInput1 == ")")
		{
			break;
		}
		else
		{
			evalArgument = atof(dataInput1.c_str());
		}
	}
	//Do eval Func call here
	cout << "EVAL " << primaryIndex1 << " ( " << evalArgument << " )\n";
}
void processCreatePoly(ifstream &inputFile, int primaryIndex1)
{
	bool passTest = true;
	double coefficientIn;
	int exponentIn;

	int count = 1;
	//polyV[index];
	//Polynomial poly1 = Polynomial(coefficientIn, exponentIn);

	cout << primaryIndex1 << " : ";

	while (inputFile.peek() != '\n')
	{
		inputFile >> coefficientIn;
		inputFile >> exponentIn;

		if (passTest)
		{
			Polynomial poly1 = Polynomial(coefficientIn, exponentIn);
			passTest = false;
			//cout << "in passTest/constructor call\n";
			cout << "poly1: " << poly1 << endl;
		}
		else
		{
			//cout << "In passTest else\n";
			//call insertion next call
		}
		cout << " " << coefficientIn << " " << exponentIn;
		//Need insert next here ! insertPolysymbol is =, therefore form expected is n = m * k
		//term1.exponent = exponentIn;
		/*
		if (count == 15)
		{
			cout << "In endless loop ender!\n";
			break;
		}
		count++;
		*/
	}
	cout << endl;
}
void processMultiPoly(ifstream &inputFile, int primaryIndex1)
{
	int kIndex = NULL,
		mIndex = NULL;
	bool passTest = true;
	string dataIn1;

	int count = 0;

	//symbol is =, therefore form expected is n = m * k
	
		//while (inputFile.peek() != '\n')
			//while(dataIn1 != "\n")
	for(int i = 0; i < 3; i++)
	{
		//inputFile.peek()
		inputFile >> dataIn1;
		if (dataIn1 == "*")
		{
			//out << "in passTest if\n";
			inputFile.ignore();
			inputFile.clear();
		}
		else if (passTest)
		{
			//cout << "in passTest else if\n";
			mIndex = atoi(dataIn1.c_str());
			passTest = false;
		}
		else
		{
			//cout << "in passTest else\n";
			kIndex = atoi(dataIn1.c_str());
		}
		

		if (count == 4)
		{
			cout << "In endless loop ender!\n";
			break;
		}
		count++;
	}
	//populate call here
	cout << primaryIndex1 << " = " << mIndex << " * " << kIndex << endl;
}

int main(/*int argc, char** argv*/)
{
	ifstream inputFile;
	string dataIn;

	//Polynomial<PolyTerm> first;
	//Polynomial poly1, poly2;

	if (!openFile(inputFile))
	{
		return 0;
	}
	else
	{
		cout << "File Open\n";
		while (inputFile >> dataIn)
		{
			int primaryIndex = 0;
			vector <Polynomial> polyV(100);
			
			switch (readFile(inputFile, dataIn, primaryIndex))
			{
				case 1: // print
					cout << "\nCase1\n";
					processPrint(inputFile);
					break;
				case 2: // eval
					cout << "\nCase2\n";
					processEval(inputFile);
					break;
				case 3: // create poly
					cout << "\nCase3\n";
					processCreatePoly(inputFile, primaryIndex);
					//populate vector with poly series - may need to add param to function call
					break;
				case 4: // multi polys
					cout << "\nCase4\n";
					processMultiPoly(inputFile, primaryIndex);
					//need to add vector to function call
					break;
				default:
					cout << "\nCase Default\n";
			}
		}
	}
	inputFile.close();

	//Temp testing
	int done;
	cout << "\nDone! Press any key and hit enter\n";
	cin >> done;
	//end temp testing

	return 0;
}

