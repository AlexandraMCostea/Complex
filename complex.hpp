#pragma once
class complex{
private:
	double Re, Im;
public:
	complex();
	~complex();
	complex(double Re, double Im); 
	complex(const complex&C); 
	void set_Re(double val);
	int get_Re();
	void set_Im(double val);
	int get_Im();
	

	friend istream& operator>>(istream&, complex &);
	friend ostream& operator<<(ostream&, complex &);

};
