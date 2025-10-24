
#include <iostream>
#include <ctime>


using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	
    const int row = 2;
    const int col = 4;
	int arr[row][col];
	int sum_arr = 0;
	int min_element = NULL;
	int max_element = NULL;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = rand() % 10;
			cout << arr[i][j] << " ";
			sum_arr += arr[i][j];
			if (arr[i][j] < min_element)
				min_element = arr[i][j];
			if (arr[i][j] > max_element)
				max_element = arr[i][j];
		}
		cout << endl;
	}
	cout << "Сумму всех элементов массива = " <<sum_arr<< endl;
	cout << "Среднее арифметическое всех элементов массива = " << sum_arr/(row+ col) << endl;
	cout << "Минимальный элемент = " << min_element << endl;
	cout << "Максимальный элемент = " << max_element << endl;
	//Задача 2
	for (int i = 0; i < row; i++)
	{
		int sum_arr = 0;
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = rand() % 10;
			cout << arr[i][j] << " ";
			sum_arr += arr[i][j];
			if (j == col - 1)
				cout << " | " << sum_arr;
		}
		cout << endl;
	}
	
	
	//Задача 3
	const int row_1 = 5;
	const int col_1 = 10;
	int arr_1[row_1][col_1];

	const int row_2 = 5;
	const int col_2 = 5;
	int arr_2[row_2][col_2];
	
	for (int i = 0; i < row_1; i++)
	{
		for (int j = 0; j < col_1; j++)
		{
			arr_1[i][j] = rand() % 50;
			cout << arr_1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	for (int i = 0; i < row_2; i++)
	{
		
		for (int j = 0; j < col_2; j++)
		{
			arr_2[i][j] = arr_1[i][j*2] + arr_1[i][j*2+1];
			cout << arr_2[i][j] << " ";
			
		}   

		cout << endl;
	}
}	

