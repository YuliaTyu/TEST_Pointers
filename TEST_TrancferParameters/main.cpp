#include<iostream>
using namespace std;

void Exchange(int& c, int& f);

void main()
{
	setlocale(LC_ALL, "");

	int a = 2;                // ��������� ����������
	int b = 3;
	cout << a << "\t" << b << endl;
	Exchange(a, b);
	cout << a << "\t" << b << endl;
}
void Exchange(int& c, int& f) //����� �������� ����������(��� ����������) 
{
	int buffer = c;
	c = f;
	f = buffer;
}