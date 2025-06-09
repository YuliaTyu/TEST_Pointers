#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* Push_back(int arr[], int& n, const int value);       //добавление элемента в конец массива
int* Push_front(int arr[], int& n, const int value);      //добавление элемента в начало массива

int* insert(int arr[], int& n, const int value, int index);//добавление значения в массив по указанному индексу

int* Pop_back(int arr[], int& n);                         //удаляет последний элемент массива(&размер по ссылке)
int* Pop_front(int arr[], int& n);                        //удаляет нулевой элемент массива

int* Erase(int arr[], int& n, const int index);           //удаляет значение из массива по указанному индексу






void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);



	int value;
	cout << "ВВедите добавляемое знаение"; cin >> value;

	arr = Push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение"; cin >> value;
	arr = Push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите индекс добавляемого значение"; cin >> index;
	cout << "Введите значение добавляемого значение"; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	cout << "Массив после уладения последнего элемента" << endl;
	Print(arr = Pop_back(arr, n), n);
	cout << "Массив после удаления нулевого элемента" << endl;
	Print(arr = Pop_front(arr, n), n);


	cout << "Введите индекс удаляемого значение"; cin >> index;
	cout << "Массив после удаления элемента по индексу" << endl;
	Print(arr = Erase(arr, n, index), n);

	delete[] arr;

}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
int* Push_back(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];                 //переопределить память - создаем буфферный массив нужного массива
	for (int i = 0; i < n; i++)buffer[i] = arr[i];//копируем все содежимое исходного массива в буфферный массив
	delete[] arr;                                 //удаляем исходный массив 
	arr = buffer;                                 //подменяем адрес в указателе arr адресом нового массива
	buffer = nullptr;
	arr[n] = value;                               //только после этого в конце массива появляется элемент, в которое можно сохранить добавляемое значение
	n++;                                          //после того как в массив дбавился элемент количество его элементов увеличивается на 1
	return arr;
}
int* Push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];                     //выделяем память нужного размера +1
	for (int i = 0; i < n; i++)buffer[i + 1] = arr[i];//копируем в буфер со смещением вправо
	delete[] arr;                                     //удаляем исходный массив
	buffer[0] = value;                                // добавляем значение в нулевой элемент!!!!!!!!!!!!
	n++;                                              // кол-во элементов в массиве увеличивается
	return buffer;
}
int* insert(int arr[], int& n, const int value, int index)
{
	int* buffer = new int[n + 1];                      //выделяем память нужного элемента   
	for (int i = 0; i < index; i++)buffer[i] = arr[i]; //копируем в буффер до индекса!

	for (int i = index; i < n; i++)buffer[i + 1] = arr[i];//копируем после индекса
	delete[] arr;                                         //удаляем исходный массив 
	buffer[index] = value;                                //в элемент добавляем значение по индексу!
	n++;
	return buffer;
}
int* Pop_back(int arr[], int& n)
{
	cout << arr << endl;
	int* buffer = new int[--n];                        //память выделится в первую очередь из-за --
	for (int i = 0; i < n; i++)buffer[i] = arr[i];     //копируем массив в буффер
	delete[] arr;                                      //удаляем исходный
	return buffer;
}
int* Pop_front(int arr[], int& n)
{
	cout << arr << endl;
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

int* Erase(int arr[], int& n, const int index)
{
	int* buffer = new int[--n];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
	return buffer;
}



