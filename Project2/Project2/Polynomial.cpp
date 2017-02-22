/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   polynomial.cpp
* Author: brickr
*
* Created on February 18, 2017, 11:35 PM
*/

#include <iostream>
#include <list>//for lists
#include <vector> //for vectors
#include <new> //for bad_alloc error
#include <iterator> //alledgedly for iterator... a little suspicious about that
//#include <cstdlib>
#include "Polynomial.h"

using namespace std;

ostream& operator<<(ostream& out, Polynomial& polyIn)
{
	//out << polyIn.coefficient << "x^" << polyIn.exponent;

	/*
	for (int i = 0; i < polyIn.size(); i++)
	{
		if (polyIn.coefficient > 0 && polyIn.exponent == 0)
		{
			//cout << polyIn.coefficient << "x^" << polyIn.exponent << " ";
			cout << polyIn.coefficient << " ";
			//cout << "x^" << polyIn.exponent << " ";
		}
		else if (polyIn.exponent > 0)
		{
			//cout << polyIn.coefficient << "x^" << polyIn.exponent << " ";
			//cout << polyIn.coefficient << " ";
			//cout << "x^" << polyIn.exponent << " ";
		}
		else
		{
			//cout << polyIn.coefficient << "x^" << polyIn.exponent << " ";
			//cout << polyIn.coefficient << " ";
			//cout << "x^" << polyIn.exponent << " ";
		}
	}
	*/
	return out;
}

//a default constructor that creates a zero polynomial, which is defined to 
//be the number 0 (meaning it has one term with c = 0 and e = 0);

Polynomial::Polynomial()
{
	try
	{
		//Create new term
		PolyTerm firstTerm {0, 0};

		// Add term to the list.
		polyList.push_back(firstTerm);
		//Create iterators, front & back
		//iterFront = polyList.begin;
	}
	catch (bad_alloc)
	{
		//mem alloc error statement
		cerr << "bad alloc\n";
	}
}

//a constructor that takes a coefficient c and an exponent e and constructs 
//a polynomial with the single term cx^e, e.g., Polynomial p(c,e);
Polynomial::Polynomial(double c, int e)
{
	PolyTerm nextTerm;
	nextTerm.coefficient = c;
	nextTerm.exponent = e;

	//check term @ iterator & populate if zero?
	polyList.push_back(nextTerm);
}
//a copy constructor that takes a polynomial q and makes a new polynomial 
//that is a copy of q, e.g. Polynomial p(q);
template <class iterator>
Polynomial::Polynomial(const Polynomial& orig)
{
	list<PolyTerm>::iterator iterF;
	//list<PolyTerm>::iterator iterB;
	//this loop might  be F'ed up - fix it!!
	for(iterF = orig.end; iterF > orig.polyList.end; iterF++)
	{
		polyList.push_back(*iterFront);
	}
	
	Polynomial temp;
	/*
	nextTerm.coefficient = orig.coefficient;
	nextTerm.exponent = orig.exponent;
	*/
}
//a destructor, which deletes the polynomial.
Polynomial::~Polynomial()
{

}
/*
//template <class list>
PolyTerm Polynomial::getPolyTerm()
{

}
*/
double Polynomial::getCoefficient()
{
	PolyTerm tempTerm;
	tempTerm = *iterFront;
	iterFront++;
	return tempTerm.coefficient;
}

int Polynomial::getExponent()
{
	PolyTerm tempTerm;
	tempTerm = *iterFront;
	return tempTerm.exponent;
}
void Polynomial::iterBackToFront(int)
{

}
void Polynomial::iterFrontToBack(int)
{

}
void Polynomial::iterFrontReset()
{

}
void Polynomial::iterBackReset()
{

}
int Polynomial::getFrontPosition()
{
	int temp = 1;
	return temp;
}
int Polynomial::getBackPosition()
{
	int temp = 1;
	return temp;
}
//dunno if we're going to need this...
void Polynomial::defineIterators(const Polynomial& orig)
{
	//orig.iterFront = orig.polyList.begin();
	//orig.iterBack = orig.polyList.end();
}
//Evaluate the polynomial using argument x and return the value. This should 
//be implemented as an overloaded function call operator().
double Polynomial::eval(double x)
{
	for (list<PolyTerm>::iterator iterTemp = polyList.begin(); iterTemp != polyList.end(); iterTemp++)
	{
		//x *= x; //
	}
	/*
	if (*iterFront.coefficient > 0)
	{
		x *= polyList.coefficient;
	}
	*/
	return x;
}

void Polynomial::print(Polynomial polyIn)
{

}
//Given polynomials p and q, return p * q.
Polynomial Polynomial::operator* (const Polynomial& otherPoly)
{
	Polynomial tempPoly;
	/*
	tempPoly.coefficient = (coefficient * otherPoly.coefficient);
	tempPoly.exponent = (exponent + otherPoly.exponent);
	*/
	return tempPoly;
}
//Given polynomials p and q, return p + q.
Polynomial Polynomial::operator+ (const Polynomial& otherPoly)
{
	Polynomial tempPoly;
	/*
	tempPoly.coefficient = (coefficient + otherPoly.coefficient);
	*/
	return tempPoly;
}
//Given polynomials p and q, return p - q.
Polynomial Polynomial::operator- (const Polynomial& otherPoly)
{
	Polynomial tempPoly;
	/*
	tempPoly.coefficient = (coefficient - otherPoly.coefficient);
	*/
	return tempPoly;
}
//an operator= for the class that will (copy) assign a polynomial to an 
//existing polynomial
void Polynomial::operator= (const Polynomial& otherPoly)
{
	/*
	coefficient = otherPoly.coefficient;
	exponent = otherPoly.exponent;
	*/
}
