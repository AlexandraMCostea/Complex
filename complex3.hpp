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
	complex& operator= (const complex&);
	complex& operator= (const double&);
	complex& operator+= (const complex&);
	complex& operator+= (const double&);
	complex& operator-= (const complex&);
	complex& operator-= (const double&);
	complex& operator*= (const complex&);
	complex& operator*= (const double&);
	complex& operator/= (const complex&);
	complex& operator/= (const double&);

	//supraincarcarea operatorilor aritmetici unari 
	friend complex operator+ (complex);
	friend complex operator- (complex);

	//supraincarcarea operatorilor aritmetici binari
	friend complex operator+ (complex, complex);
	friend complex operator+ (complex, double);
	friend complex operator+ (double, complex);

	friend complex operator- (complex, complex);
	friend complex operator- (complex, double);
	friend complex operator- (double, complex);

	friend complex operator* (complex, complex);
	friend complex operator* (complex, double);
	friend complex operator* (double, complex);

	friend complex operator/ (complex, complex);
	friend complex operator/ (complex, double);
	friend complex operator/ (double, complex);

	friend complex operator^ (complex, int);


	//supraincarcarea operatorilor relationali
	friend bool operator== (complex, complex);
	friend bool operator== (complex, double);
	friend bool operator== (double, complex);

	friend bool operator!= (complex, complex);
	friend bool operator!= (complex, double);
	friend bool operator!= (double, complex);


	//metodele publice ToString si conjugat
	string ToString();
	complex conjugat();

	//modulul si radacina patrata
	friend double modul(complex);
	friend complex RadacinaPatrata(complex, int);
};