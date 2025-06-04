#pragma warning (disable:4326)
#include<iostream>
using namespace std;


void Exchange(int* a, int* b);
void Exchange(int& a, int& b);


void main()
{
	setlocale(LC_ALL, "");

	int a = 2;                // оригиналы переменных
	int b = 3;

	cout << a << "\t" << b << endl;
	Exchange(&a, &b);
	cout << a << "\t" << b << endl;

	Exchange(a, b);
	cout << a << "\t" << b << endl;
}

//передача по указателю
void Exchange(int* a, int* b)  
{
	int buffer = *a;
	*a = *b;
	*b = buffer;
}

//передача по ссылке
void Exchange(int& a, int& b)  
{
	int buffer = a;
	a = b;
	b = buffer;
}