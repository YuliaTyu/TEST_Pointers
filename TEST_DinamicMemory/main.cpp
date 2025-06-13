#pragma warning(disable:4326)
#pragma warning(disable:6386)
#include<iostream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;

#define delimeter "\n---------------------------------------\n";

template<typename T>T** Allocate(const int rows, const int cols);             //выделыем память 
template<typename T>void Clear(T**& arr, const int rows, const int cols=0);   //удаляем из памяти

void FillRand(int arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

template<typename T> void Print(T arr[], const int n);
template<typename T> void Print(T** arr, const int rows, const int cols);

template<typename T> T* Push_back(T arr[], int& n, const T value);       //добавление элемента в конец массива
template<typename T> T* Push_front(T arr[], int& n, const T value);      //добавление элемента в начало массива

template<typename T> T* insert(T arr[], int& n, const T value, T index);//добавление значения в массив по указанному индексу

template<typename T>T* Pop_back(T arr[], int& n);                         //удаляет последний элемент массива(&размер по ссылке)
template<typename T>T* Pop_front(T arr[], int& n);                        //удаляет нулевой элемент массива

template<typename T>T* Erase(T arr[], int& n, const T index);           //удаляет значение из массива по указанному индексу


template<typename T>T** Push_row_back(T** arr, int& rows, const int cols); //добавление строки в конец массива
template<typename T>T** Push_row_front(T** arr, int& rows, int& cols);    //добавляем строку в начало массива

template<typename T>T** Pop_row_back(T** arr, int& rows, const int cols);  //удаляет строку из конца массива

template<typename T>void Push_col_back(T** arr, const int rows, int& cols); //добавляет столбец в конец массива
template<typename T>void Push_col_front(T** arr, const int rows, int& cols); //добавляет столбец в начало массива

template<typename T>void Pop_col_back(T** arr, const int rows, int& cols);    //удалет столбик из конца массива
template<typename T>T** Pop_col_front(T** arr, const int rows, int& cols);    //удалет столбик из начала массива
template<typename T>T** Erase_row(T** arr, int& rows, const int cols, T index); // удаляет строку по указаному индексу
template<typename T>T** Erase_col(T** arr, const int rows, int& cols, T index_3);


template<typename T>T** Insert_row(T** arr, int& rows, const int cols, const T index_2);                 //доб строку в массив по указателю

//#define DINAMIC_MEMORY1
#define DINAMIC_MEMORY2
//#define DATATYPE int
//typedef int DataType;


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


#ifdef DINAMIC_MEMORY2


	int rows;
	int cols;
	cout << "Введите кол-во строк"; cin >> rows;
	cout << "Введите кол-во элементов строки"; cin >> cols;

	int** arr = Allocate<int>(rows, cols); //- ПАМЯТЬ ВЫДЕЛИТЬ


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

	Pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	int index;
	cout << "Введите индекс строки котрую удаляем"; cin >> index;
	arr = Erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	
	int index_2;
	cout << "Введите индекс добавляемогозначения"; cin >> index_2;
	arr = Insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	
	int index_3;
	cout << "Введите индекс удаляемого столбца значения"; cin >> index_3;
	arr = Erase_col(arr, rows, cols, index_3);
	Print(arr, rows, cols);

	Clear(arr, rows, cols); // - УДАЛИТЬ ИЗ ПАМЯТИ

#endif // DINAMIC_MEMORY2

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

template<typename T> void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T> void Print(T** arr, const int rows, const int cols)
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

template<typename T>T** Allocate(const int rows, const int cols)
{
	//(указатель ** на указатель)создаем массив указателей
	T** arr = new T* [rows];

	//выделяем память под строки двумерного динамич массива
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
	}
	cout << endl;
	return arr;
}
template<typename T>void Clear(T**& arr, const int rows, const int cols)
{
	//очистить память
	for (int i = 0; i < rows; i++) // сначала удаляем строки
	{
		delete[] arr[i];
	}
	delete[] arr;                  // удаляем массив укзателей
	arr = nullptr;                 // зануляем указатель на массив
}

template<typename T> T* Push_back(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];                 //переопределить память - создаем буфферный массив нужного массива
	for (int i = 0; i < n; i++)buffer[i] = arr[i];//копируем все содежимое исходного массива в буфферный массив
	delete[] arr;                                 //удаляем исходный массив 
	arr = buffer;                                 //подменяем адрес в указателе arr адресом нового массива
	buffer = nullptr;
	arr[n] = value;                               //только после этого в конце массива появляется элемент, в которое можно сохранить добавляемое значение
	n++;                                          //после того как в массив дбавился элемент количество его элементов увеличивается на 1
	return arr;
}
template<typename T> T** Push_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T*[rows+1];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];//копируем адреса строк в буфферный массив указателей
	delete[] arr;                                    // удаляем массив укзателей	
	buffer[rows] = new int[cols] {};                 //создаем добавляемую строку и записываем ее адрес в массив указателей 
	rows++;                                         //при добавлении в массив строки количество его строк увеличивается на 1
	return buffer;

}

template<typename T>T* Push_front(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];                     //выделяем память нужного размера +1
	for (int i = 0; i < n; i++)buffer[i + 1] = arr[i];//копируем в буфер со смещением вправо
	delete[] arr;                                     //удаляем исходный массив
	buffer[0] = value;                                // добавляем значение в нулевой элемент!!!!!!!!!!!!
	n++;                                              // кол-во элементов в массиве увеличивается
	return buffer;
}
template<typename T>T** Push_row_front(T** arr, int& rows, int& cols)
{
	T** buffer = new T* [rows+1];
	for (int i = 0; i < rows; i++)buffer[i+1] = arr[i];//копируем адреса строк в буфферный массив указателей
	delete[] arr;                                    // удаляем массив укзателей	
	buffer[0] = new int[cols] {};                 //создаем добавляемую строку и записываем ее адрес в массив указателей 
	rows++;                                         //при добавлении в массив строки количество его строк увеличивается на 1
	return buffer;
}

template<typename T>T* insert(T arr[], int& n, const T value, T index)
{
	T* buffer = new T[n + 1];                      //выделяем память нужного элемента   
	for (int i = 0; i < index; i++)buffer[i] = arr[i]; //копируем в буффер до индекса!

	for (int i = index; i < n; i++)buffer[i + 1] = arr[i];//копируем после индекса
	delete[] arr;                                         //удаляем исходный массив 
	buffer[index] = value;                                //в элемент добавляем значение по индексу!
	n++;
	return buffer;
}

template<typename T>T* Pop_back(T arr[], int& n)
{
	cout << arr << endl;
	T* buffer = new T[--n];                        //память выделится в первую очередь из-за --
	for (int i = 0; i < n; i++)buffer[i] = arr[i];     //копируем массив в буффер
	delete[] arr;                                      //удаляем исходный
	return buffer;
}
template<typename T>void Push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)                          //память не переопределяем !!!
	{
		T* buffer = new T[cols + 1] {};                   //создаем буфферный массив нужного размера 
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];   // копируем элементы текущей строки
		delete[] arr[i];                                     //удаляем старый массив
		arr[i] = buffer;                                     //делаем новую строку
	}
	cols++;
}

template<typename T>T* Pop_front(T arr[], int& n)
{
	cout << arr << endl;
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

template<typename T>T* Erase(T arr[], int& n, const T index)
{
	T* buffer = new T[--n];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
	return buffer;
}

template<typename T>T** Pop_row_back(T** arr, int& rows, const int cols)
{
	delete[] arr[rows - 1];//удалем последнюю строку
	T** buffer = new T* [--rows];           //создеам буфферный массив указателей
	for (int i = 0; i < rows; i++)buffer[i] = arr[i]; // копируем оставшиеся строки в буферный массив указателей
	delete[] arr;        // удаляем массив указателей
	return buffer;
}
template<typename T>void Push_col_front(T** arr, const int rows, int& cols)
{

	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T>void Pop_col_back(T** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols];
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];    //копируем исходную строку в буффер
		delete[] arr[i];
		arr[i] = buffer;
	}
}
template<typename T>T** Pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols];
		for (int j = 1; j < cols; j++)
		{
			buffer[j - 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
	return arr;
}
template<typename T>T** Erase_row(T** arr, int& rows, const int cols, T index)
{
	T** buffer = new T* [rows - 1];
	for (int i = 0; i < rows - 1; i++)i < index ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	delete[] arr;
	rows--;
	return buffer;
}
template<typename T>T** Erase_col(T** arr, const int rows, int& cols, T index_3)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
		for (int j = 0; j < index_3; j++)buffer[j] = arr[i][j];
		for (int j = index_3; j < cols - 1; j++)buffer[j] = arr[i][j + 1];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols--;
	return arr;
}
template<typename T>T** Insert_row(T** arr, int& rows, const int cols, const T index_2)
{
	if (index_2<0||index_2>rows)
	{
		cout << "Error" << endl;
		return arr;
	}
	T** buffer = new T* [rows + 1] {};
	for (int i = 0; i < index_2; i++)buffer[i] = arr[i];
	for (int i = index_2; i < rows; i++)buffer[i + 1] = arr[i];
	delete[]arr;
	buffer[index_2] = new T[cols] {};
	rows++;
	return buffer;
}
