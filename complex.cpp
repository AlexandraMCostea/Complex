#include "pch.h"
#include <iostream>
#include "complex.hpp"

complex::complex(double Re = 0, double Im = 0) { Re = Re; Im = Im; } 

complex::complex(const complex&C) { 
	Re = C.Re;
	Im = C.Im;
}



istream& operator>>(istream& in, complex &C)
{
	in >> C.Re >> C.Im;
	return in;
}

ostream& operator<<(ostream& out, complex &C)
{
	if (Re == 0)
	{
		if (Im == 0)
			out << "0";
		else
			if (Im == 1)
				out << "i";
			else
				if (Im == -1)
					out << "-i";
				else {
					if (Im > 0)
						out << "i*" << Im;
					else
						out << "i*" << (Im);
				}
	}
	else
	{
		if (Im == 0)
			out << Re;
		else
			if (Im == 1)
				out << Re << "+i";
			else
				if (Im == -1)
					out << Re << "-i";
				else {
					if (Im > 0)
						out << Re << "+" << "i*" << Im ;
					else
						out << Re << "i*" << (Im) ;
				}
	}
	return out;
}


int main()
{

}
