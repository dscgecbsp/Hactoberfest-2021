# addition of two complex numbers
#include<iostream>
using namespace std;
class Complex{
public:
	int real;
	int imag;
	void getData(float, float)
	{
		cin>>real;
		cin>>imag;
	}
	void show(void)
	{
		cout<<real<<"+"<<imag<<"i"<<endl;
	}
	void add(Complex c1, Complex c2)
	{
	real = c1.real + c2.real;
	imag = c1.imag + c2.imag;
	}
	};
int main(){
	Complex c1, c2, c3;
	float a, b;
	cout<<"Enter real and imaginary part of first complex number"<<endl;
	c1.getData(a, b);
	cout<<"Enter real and imaginary part of second complex number"<<endl;
	c2.getData(a, b);

	cout<<"Sum of two complex numbers: "<<endl;
	c3.add(c1, c2);
	c3.show();
return 0;
}
