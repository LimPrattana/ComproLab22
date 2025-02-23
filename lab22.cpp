#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		friend ComplexNumber operator+(double,const ComplexNumber &);
		friend ComplexNumber operator-(double,const ComplexNumber &);
		friend ComplexNumber operator*(double,const ComplexNumber &);
		friend ComplexNumber operator/(double,const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		friend bool operator==(double,const ComplexNumber &);
		double abs();
		double angle();
		friend ostream & operator<<(ostream &,const ComplexNumber &);
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}
//complex
ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}
ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}
ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber((real*c.real)-(imag*c.imag),(real*c.imag)+(imag*c.real));
}
ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
    double denom = c.real * c.real + c.imag * c.imag;
    return ComplexNumber((real * c.real + imag * c.imag) / denom, 
                         (imag * c.real - real * c.imag) / denom);
}

//real
ComplexNumber operator+(double d,const ComplexNumber &c){
	return ComplexNumber(d+c.real,c.imag);
}
ComplexNumber operator-(double d,const ComplexNumber &c){
	return ComplexNumber(d-c.real,-c.imag);
}
ComplexNumber operator*(double d,const ComplexNumber &c){
	return ComplexNumber(d*c.real,d*c.imag);
}
ComplexNumber operator/(double d, const ComplexNumber &c){
    double denom = c.real * c.real + c.imag * c.imag;
    return ComplexNumber((d * c.real) / denom, (-d * c.imag) / denom);
}

bool ComplexNumber::operator==(const ComplexNumber &c){
	return (real==c.real)&&(imag==c.imag) ;
}
bool operator==(double d,const ComplexNumber &c){
	return (d==c.real)&&(c.imag==0) ;
}

double ComplexNumber::abs(){
	return sqrt(pow(real,2)+pow(imag,2));
}
double ComplexNumber::angle(){
	double pi = 3.141592653589793;
	return atan2(imag,real)*180 /pi;
}
ostream & operator<<(ostream &os,const ComplexNumber &c){
	if(c.imag==0) return os<<c.real;
	if(c.real==0) return os<<c.imag<<"i";
	if(c.imag>0) return os<<c.real<<"+"<<c.imag<<"i";
	else return os<<c.real<<c.imag<<"i";
}


int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}





