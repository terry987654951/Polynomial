/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   polynomial.h
* Author: brickr
*
* Created on February 18, 2017, 11:35 PM
*/

#include <iostream>
#include <list>
#include <iterator>
using namespace std;

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H



class Polynomial 
{

	//Given an output stream out and polynomial p, write p in symbolic form on out.    
	friend ostream& operator<<(ostream&, Polynomial&);
private:
	//struct?
	//template<PolyTerm>
	struct PolyTerm
	{
		double coefficient; //what am I
		int exponent; //what am I
	};
	list <PolyTerm> polyList;

protected:
	list<PolyTerm>::iterator iterFront = polyList.begin();
	list<PolyTerm>::iterator iterBack = polyList.end();

public:
	//a default constructor that creates a zero polynomial, which is defined to 
	//be the number 0 (meaning it has one term with c = 0 and e = 0);
	Polynomial();
	//a constructor that takes a coefficient c and an exponent e and constructs 
	//a polynomial with the single term cx^e, e.g., Polynomial p(c,e);
	Polynomial(double, int);
	//a copy constructor that takes a polynomial q and makes a new polynomial 
	//that is a copy of q, e.g. Polynomial p(q);
	template <class iterator>
	Polynomial(const Polynomial&);
	//a destructor, which deletes the polynomial.
	virtual ~Polynomial();
	//Maybe yes, maybe no
	void defineIterators(const Polynomial&);
	//Evaluate the polynomial using argument x and return the value. This should 
	//be implemented as an overloaded function call operator().
	double eval(double x);

	void print(Polynomial);

	//PolyTerm getPolyTerm();

	double getCoefficient();

	int getExponent();

	//NEED ITERATOR POSITION GETS and insert/remove etc in list stuff
	void iterBackToFront(int);
	void iterFrontToBack(int);
	void iterFrontReset();
	void iterBackReset();
	int getFrontPosition();
	int getBackPosition();


	/* Overloated Operators */
	//Given polynomials p and q, return p * q.
	Polynomial operator* (const Polynomial& otherPoly);
	//Given polynomials p and q, return p + q.
	Polynomial operator+ (const Polynomial& otherPoly);
	//Given polynomials p and q, return p - q.
	Polynomial operator- (const Polynomial& otherPoly);
	//an operator= for the class that will (copy) assign a polynomial to an 
	//existing polynomial
	void operator= (const Polynomial& otherPoly);
};

#endif /* POLYNOMIAL_H */

