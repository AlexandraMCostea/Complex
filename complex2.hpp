#pragma once
#pragma once

#include <iostream>
#include <string>
using namespace std;
class complex {
private:
	double Re, Im;
public:
	complex(); //constructor implicit
	~complex(); //destructor
	complex(double Re, double Im); //constructor parametrizat
	complex(const complex&C); //constructor copiere
	complex(string); //constructor string

	//getter si setter
	void set_Re(double val); 
	double get_Re() const;
	void set_Im(double val);
	double get_Im() const;


	//functii citire si afisare
	friend istream& operator>>(istream&, complex &);
	friend ostream& operator<<(ostream&, complex &);

	//supraincarcarea operatorilor compusi de atribuire
	void operator= (const complex&);
}