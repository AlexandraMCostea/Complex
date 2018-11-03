#include "pch.h"
#include "complex.hpp"


complex::complex(double Re = 0, double Im = 0) {
	this->Re = Re;
	this->Im = Im; 
}

complex::complex(const complex&C) {
	Re = C.Re;
	Im = C.Im;
}

complex::complex() {
	Re = 0;
	Im = 0;
}


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


complex::~complex() {

}
double complex::get_Re() const{
	return Re;
}

double complex::get_Im() const
{
	return Im;
}

void complex::set_Re(double Re) {
	this->Re = Re;
}

void complex::set_Im(double Im) {
	this->Im = Im;
}


istream& operator>>(istream& in, complex &C)
{
	string s;
	in >> s;
	complex c(s);
	C = c;
	return in;
}


ostream& operator<<(ostream& out, complex &C)
{
	if (C.Re == 0)
	{
		if (C.Im == 0)
			out << "0";
		else
			if (C.Im == 1)
				out << "i";
			else
				if (C.Im == -1)
					out << "-i";
				else {
					if (C.Im > 0)
						out << "i*" << C.Im;
					else
						out << "-i*" <<  -C.Im ;
				}
	}
	else
	{
		if (C.Im == 0)
			out << C.Re;
		else
			if (C.Im == 1)
				out << C.Re << "+i";
			else
				if (C.Im == -1)
					out << C.Re << "-i";
				else {
					if (C.Im > 0)
						out << C.Re << "+" << "i*" << C.Im;
					else
						out << C.Re << "-i*"  << -C.Im;
				}
	}
	return out;
}

void complex::operator= (const complex& c) {
	this->Re = c.get_Re();
	this->Im = c.get_Im();
}