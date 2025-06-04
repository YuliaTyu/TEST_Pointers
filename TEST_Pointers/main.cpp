#include<iostream>
using namespace std;

//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");

#ifdef POINTERS_BASICS


	int a = 2;
	int* pa = &a;
	cout << a << endl;//вывод переменной
	cout << &a << endl;//взятие адреса
	cout << pa << endl;//вывод адреса
	cout << *pa << endl;//разименование указателя ра и вывод на экран значения по адресу

	int* pb;
	int b = 3;
	pb = &b;
	cout << pb << endl;
	cout << *pb << endl;

#endif // POINTERS_BASICS

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;// адрес нулевого элемента
	cout << *arr << endl; // вывод 0 элемента
	for (int i = 0; i < n; i++)
	{
		cout << arr + i << "\t";//вывод адреса массива - 4 байта занимает  
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";//сначала адрес элемента - потом разыменовали  - вывод значения массива по указателм
	}
	cout << endl;
}