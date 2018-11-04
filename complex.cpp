#include "pch.h"
#include "complex.hpp"

//constructor initializare cu parametri
complex::complex(double Re, double Im) {
	this->Re = Re;
	this->Im = Im; 
}

//constructor copiere
complex::complex(const complex&C) {
	Re = C.Re;
	Im = C.Im;
}

//constructor initializare fara parametri
complex::complex() {
	Re = 0;
	Im = 0;
}

//constructor parametrizat care primeste string
complex::complex(string s) {
	int i=0;
	if (s[0] == 'i' || s[1] == 'i')
		Re = 0;
	else
		{
			for (i = 1; i < s.size(); i++)
				if (s[i] == '+' || s[i] == '-')
					break;
			Re = stod(s.substr(0, i));
		}
	if (i == s.size())
		Im = 0;
	else if (s[i] == '-')
		Im = -1;
	else Im = 1;
		
	if (s[i] != 'i' && i+3<s.size() )
		Im *= stod(s.substr(i + 3, s.size()));
	else if(i + 3 < s.size())
		Im = stod(s.substr(i + 2, s.size()));
}


//destructor
complex::~complex() {

}

//getter
double complex::get_Re() const{
	return Re;
}

double complex::get_Im() const
{
	return Im;
}

//setter
void complex::set_Re(double Re) {
	this->Re = Re;
}

void complex::set_Im(double Im) {
	this->Im = Im;
}


//supraincarcare operator >> citire
istream& operator>> (istream& in, complex &c)
{
	string s;
	in >> s;
	complex c1(s);
	c = c1;
	return in;
}


//supraincarcare operator << afisare
ostream& operator<< (ostream& out, complex &c)
{
	out << c.ToString();
	return out;
}

//supraincarcare operatori de atribuire
complex& complex::operator= (const complex& c) {
	this->Re = c.get_Re();
	this->Im = c.get_Im();
	return *this;
}

complex& complex::operator= (const double& x) {
	this->Re = x;
	return *this;
}


complex& complex::operator+= (const complex& c) {
	this->Re = this->Re + c.get_Re();
	this->Im = this->Im + c.get_Im();
	return *this;
}

complex& complex::operator+= (const double& x) {
	this->Re = this->Re + x;
	return *this;
}


complex& complex::operator-= (const complex& c) {
	this->Re = this->Re - c.get_Re();
	this->Im = this->Im - c.get_Im();
	return *this;
}

complex& complex::operator-= (const double& x) {
	this->Re = this->Re - x;
	return *this;
}


complex& complex::operator*= (const complex& c) {
	double x = this->Re;
	this->Re = this->Re * c.get_Re()-this->Im*c.get_Im();
	this->Im = this->Im * c.get_Re() + x * c.get_Im();
	return *this;
}

complex& complex::operator*= (const double& x) {
	this->Re = this->Re * x;
	this->Im = this->Im * x;
	return *this;
}


complex& complex::operator/= (const complex& c) {
	if (c == 0)
		throw "eroare impartire la 0";
	else {
		double x = this->Re;
		this->Re = (this->Re*c.get_Re() + this->Im*c.get_Im()) / (c.get_Re()*c.get_Re() + c.get_Im()*c.get_Im());
		this->Im = (this->Im*c.get_Re() - x * c.get_Im()) / (c.get_Re()*c.get_Re() + c.get_Im()*c.get_Im());
		return *this;
	}
}

complex& complex::operator/= (const double& x) {
	if (x == 0)
		throw "eroare impartire la 0";
	else {
		this->Re = this->Re / x;
		this->Im = this->Im / x;
		return *this;
	}
}



//Supraincarcarea operatorilor aritmetici unari
complex operator+ (complex c) {
	return c;
}

complex operator- (complex c) {
	complex obj(c);
	obj.Re = -obj.Re;
	obj.Im = -obj.Im;
	return obj;
}


//Supraincarcarea operatorilor aritmetici binari
complex operator+ (complex c1, complex c2) {
	complex obj;
	obj.Re = c1.Re + c2.Re;
	obj.Im = c1.Im + c2.Im;
	return obj;
	}

complex operator+ (complex c1, double d) {
	complex obj;
	obj.Re = c1.Re + d;
	obj.Im = c1.Im;
	return obj;
}

complex operator+ (double d, complex c2) {
	complex obj;
	obj.Re = d + c2.Re;
	obj.Im = c2.Im;
	return obj;
}


complex operator- (complex c1, complex c2) {
	complex obj;
	obj.Re = c1.Re - c2.Re;
	obj.Im = c1.Im - c2.Im;
	return obj;
}

complex operator- (complex c1, double d) {
	complex obj;
	obj.Re = c1.Re - d;
	obj.Im = c1.Im;
	return obj;
}

complex operator- (double d, complex c2) {
	complex obj;
	obj.Re = d + c2.Re;
	obj.Im = c2.Im;
	return obj;
}


complex operator* (complex c1, complex c2) {
	complex obj;
	obj.Re = c1.Re * c2.Re - c1.Im * c2.Im;
	obj.Im = c1.Im * c2.Re + c1.Re * c2.Im;
	return obj;
}

complex operator* (complex c1, double d) {
	complex obj;
	obj.Re = c1.Re * d;
	obj.Im = c1.Im * d;
	return obj;
}

complex operator* (double d, complex c2) {
	complex obj;
	obj.Re = d * c2.Im;
	obj.Im = d * c2.Im;
	return obj;
}


complex operator/ (complex c1, complex c2) {
	complex obj;
	if (c2 == 0)
		throw "eroare impartire la 0";
	else {
		obj.Re = (c1.Re*c2.Re + c1.Im*c2.Im) / (c2.Re*c2.Re + c2.Im*c2.Im);
		obj.Im = (c1.Im*c2.Re - c1.Re * c2.Im) / (c2.Re*c2.Re + c2.Im*c2.Im);
		return obj;
	}
}

complex operator/ (complex c1, double d) {
	complex obj;
	if (d == 0)
		throw ("eroare impartire la 0");
	else {
		obj.Re = c1.Re / d;
		obj.Im = c1.Im / d;
		return obj;
	}
}

complex operator/ (double d, complex c2) {
	complex obj;
	if (c2 == 0)
		throw "eroare impartire la 0";
	else {
		obj.Re = d*c2.Re / (c2.Re*c2.Re + c2.Im*c2.Im);
		obj.Im = -d*c2.Im / (c2.Re*c2.Re + c2.Im*c2.Im);
		return obj;
	}
}


complex operator^ (complex c, int n) {
	complex obj(c);
	if (n == 0)
		obj = 0;
	else
		for (int i = 1; i < n; i++)
			obj *= c;
	return obj;
}



//supraincarcarea operatorilor relationali
bool operator== (complex c1, complex c2) {
	if (c1.Re == c2.Re && c1.Im == c2.Im)
		return true;
	else return false;
}

bool operator== (complex c1, double d) {
	if (c1.Re == d && c1.Im == 0)
		return true;
	else return false;
}

bool operator== (double d, complex c2) {
	if (d == c2.Re && c2.Im == 0)
		return true;
	else return false;
}


bool operator!= (complex c1, complex c2) {
	return !(c1 == c2);
}

bool operator!= (complex c1, double d) {
	return !(c1 == d);
}

bool operator!= (double d, complex c2) {
	return !(d == c2);
}


//metoda publica ToString 
string complex::ToString() {
	string s="";
	if (this->Re == 0)
	{
		if (this->Im == 0)
			s += "0";
		else
			if (this->Im == 1)
				s += "i";
			else
				if (this->Im == -1)
					s += "-i";
				else {
					if (this->Im > 0)
						s += "i*" + to_string(this->Im);
					else
						s += "-i*" + to_string(-(this->Im));
				}
	}
	else
	{
		if (this->Im == 0)
			s += to_string(this->Re);
		else
			if (this->Im == 1)
				s += to_string(this->Re) + "+i";
			else
				if (this->Im == -1)
					s += to_string(this->Re) + "-i";
				else {
					if (this->Im > 0)
						s += to_string(this->Re) + "+i*" + to_string(this->Im);
					else
						s += to_string(this->Re) + "-i*" + to_string(-(this->Im));
				}
	}
	return s;
}


//metoda publica conjugat
complex complex::conjugat() {
	this->Im = - this->Im;
	return *this;
}


//functia prieten modul
double modul(complex c) {
	double x;
	x = sqrt(c.Re*c.Re + c.Im*c.Im);
	return x;
}


//functia prieten radacina patrata
complex RadacinaPatrata(complex c, int n) {
	complex x;
	x.Re = sqrt((c.Re + sqrt(c.Re * c.Re + c.Im * c.Im)) / 2);
	x.Im = (c.Im > 0 ? 1 : -1) * sqrt((-c.Re + sqrt(c.Re * c.Re + c.Im * c.Im)) / 2);
	if (n == 1) {
		return x;
	}
	else if(n == 2) {
		return (-x);
	}
	else cout << "Numarul radacinii dorite este invalid. Incercati din nou alegand intre 1 si 2";
} 


