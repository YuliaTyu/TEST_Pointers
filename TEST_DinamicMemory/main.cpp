#pragma warning(disable:4326)
#pragma warning(disable:6386)
#include<iostream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;

#define delimeter "\n---------------------------------------\n";

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* Push_back(int arr[], int& n, const int value);       //добавление элемента в конец массива
int* Push_front(int arr[], int& n, const int value);      //добавление элемента в начало массива

int* insert(int arr[], int& n, const int value, int index);//добавление значения в массив по указанному индексу

int* Pop_back(int arr[], int& n);                         //удаляет последний элемент массива(&размер по ссылке)
int* Pop_front(int arr[], int& n);                        //удаляет нулевой элемент массива

int* Erase(int arr[], int& n, const int index);           //удаляет значение из массива по указанному индексу


int** Push_row_back(int** arr, int& rows, const int cols); //добавление строки в конец массива
int** Push_row_front(int** arr, int& rows, int& cols);    //добавляем строку в начало массива
int** Pop_row_back(int** arr, int& rows, const int cols);  //удаляет строку из конца массива
void Push_col_back(int** arr, const int rows, int& cols); //добавляет столбец в конец массива
//?????void Push_col_front(int** arr, const int rows, int& cols); //добавляет столбец в начало массива
void Pop_col_back(int** arr, const int rows, int& cols);    //удалет столбик из конца массива


//#define DINAMIC_MEMORY1
#define DINAMIC_MEMORY2


void main()
{
	setlocale(LC_ALL, "");

#ifdef DINAMIC_MEMORY1


	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);



	int value;
	cout << "ВВедите добавляемое знаение в конец массива"; cin >> value;
	arr = Push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение в начало массива"; cin >> value;
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
#endif // DINAMIC_MEMORY

	int rows;
	int cols;
	cout << "Введите кол-во строк"; cin >> rows;
	cout << "Введите кол-во элементов строки"; cin >> cols;

	//(указатель ** на указатель)создаем массив указателей
	int** arr = new int* [rows];

	//выделяем память под строки двумерного динамич массива
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	cout << endl;

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	
	arr = Push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	
	arr = Push_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	arr = Pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	
	Push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	Push_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	Pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	
	//очистить память
	for (int i = 0; i < rows; i++) // сначала удаляем строки
	{
		delete[] arr[i];
	}
	delete[] arr;                  // удаляем массив укзателей

}


void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
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
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << delimeter;
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
int** Push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int*[rows+1];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];//копируем адреса строк в буфферный массив указателей
	delete[] arr;                                    // удаляем массив укзателей	
	buffer[rows] = new int[cols] {};                 //создаем добавляемую строку и записываем ее адрес в массив указателей 
	rows++;                                         //при добавлении в массив строки количество его строк увеличивается на 1
	return buffer;

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
int** Push_row_front(int** arr, int& rows, int& cols)
{
	int** buffer = new int* [rows+1];
	for (int i = 0; i < rows; i++)buffer[i+1] = arr[i];//копируем адреса строк в буфферный массив указателей
	delete[] arr;                                    // удаляем массив укзателей	
	buffer[0] = new int[cols] {};                 //создаем добавляемую строку и записываем ее адрес в массив указателей 
	rows++;                                         //при добавлении в массив строки количество его строк увеличивается на 1
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
void Push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)                          //память не переопределяем !!!
	{
		int* buffer = new int[cols + 1] {};                   //создаем буфферный массив нужного размера 
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];   // копируем элементы текущей строки
		delete[] arr[i];                                     //удаляем старый массив
		arr[i] = buffer;                                     //делаем новую строку
	}
	cols++;
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

int** Pop_row_back(int** arr, int& rows, const int cols)
{
	delete[] arr[rows - 1];//удалем последнюю строку
	int** buffer = new int* [--rows];           //создеам буфферный массив указателей
	for (int i = 0; i < rows; i++)buffer[i] = arr[i]; // копируем оставшиеся строки в буферный массив указателей
	delete[] arr;        // удаляем массив указателей
	return buffer;
}
void Push_col_front(int** arr, const int rows, int& cols)
{

	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void Pop_col_back(int** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols];
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];    //копируем исходную строку в буффер
		delete[] arr[i];
		arr[i] = buffer;
	}
}


