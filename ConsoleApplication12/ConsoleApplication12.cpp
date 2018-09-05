// ConsoleApplication12.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>

using namespace std;

void delete_K(int **&p, int &n, int m, int k)
{
	delete[] p[k];

	for (int i = k; i < n; i++)
	{
		p[i] = p[i + 1];
	}
	n--;

	/*int **t = new int*[n - 1];

	for (int i = 0; i < k; i++)
	{
		t[i] = p[i];
	}
	for (int i = k + 1; i < n; i++)
	{
		t[i + 1] = p[i];
	}
	delete[]p[n - 1];
	n--;*/
}
int* fore_array(int **p, int n, int m, int &new_size)
{
	new_size = n * m;
	int index = 0;
	int* tmp = new int[new_size];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp[index++] = p[i][j];
		}
	}
	return tmp;
}
void add_row(int **&p, int &n, int m)
{
	int **t = new int*[n + 1];
	for (int i = 0; i < n; i++)
	{
		t[i] = p[i];
	}
	delete[]p;

	p = t;
	p[n] = new int[m];
	n++;
}


//1.	Напишите функцию для обращения одномерного массива в N - мерный.Должны выполняться соответствующие проверки.

void arr(int *a, int size) {

	int n, m;
	cout << "podelit' na N strok, N = ";
	cin >> n;
	int **tmp;

	if (size % n == 0) {

		tmp = new int*[n];

		m = size / n;
		
		for (int i = 0; i < n; i++)
		{
			tmp[i] = new int[m];
		}

		int k = 0;

		for (int i = 0; i < size; i++)
		{
			
			cout << a[i] << " ";
		}
		cout << endl;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				tmp[i][j] = a[k++];
				cout << tmp[i][j] << " ";
			}
			cout << endl;
		}

		delete[] a;

		for (int i = 0; i < n; i++)
		{
			delete[] tmp[i];
		}

		delete tmp;
	}
}



//2.	Транспонирование матрицы – это операция, после которой столбцы прежней матрицы становятся строками, а строки столбцами. Напишите функцию транспонирования матрицы.
void add(int **a, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = rand() % 10 + 0;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
void tr(int **&a, int &n, int &m) {

	int **tmp = new int*[m];

	for (int i = 0; i < m; i++)
	{
		tmp[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp[j][i] = a[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;

	a = tmp;
	
}
void print(int **a, int n, int m) {

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}


int main()
{
	srand(time(NULL));

	//1.
	int *z, size;
	cout << "array size = ";
	cin >> size;

	z = new int[size];

	for (int i = 0; i < size; i++)
	{
		*(z+i) = rand() % 10 + 0;
		cout << *(z+i) << " ";
	}

	cout << endl;

	arr(z, size);


	//2.
	int **p;
	int n=3, m=4;
	cin >> n >> m;

	p = new int*[n];
	for (int i = 0; i < n; i++)
		{
			p[i] = new int[m];
		}

	add(p, n, m);
	tr(p, n, m);
	cout << endl;
	print(p, n, m);

	for (int i = 0; i < m; i++)
	{
		delete[] p[i];
	}

	delete p;
	//cin >> n >> m;
	
	
	/////////////////////////////////////////////////////////
	//int **p /* , arr */ ;
	//int n = 4, m = 5 /* , arr_size */ ;
	///* cin >> n >> m; */
	//	p = new int*[n];

	//for (int i = 0; i < n; i++)
	//{
	//	p[i] = new int[m];
	//}

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		p[i][j] = rand() % 20 + 1;
	//		/* cout << setw(3) << p[i][j]; */
	//	}
	//	cout << endl;
	//}
	//cout << endl;
	//p[0][0] = 100;
	//add_row(p, n, m);
	//p[4][0] = 200;
	//delete_K(p, n, m, 2);

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		cout << setw(3) << p[i][j];
	//	}
	//	cout << endl;
	//}
	//cout << endl;
	///*arr = fore_array(p, n, m, arr_size);

	//for (int i = 0; i < arr_size; i++)
	//{
	//cout << setw(3)<<arr[i];
	//}
	//cout << endl;
	//delete[]arr;*/

	//for (int i = 0; i < n; i++)
	//{
	//	delete[] p[i];
	//}
	//delete[]p;







	system("pause");
	return 0;
}

