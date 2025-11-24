#include <iostream>

using namespace std;


    ///   Задание 1



//Инициализация квадратной матрицы
//////// Инициализация квадратной матрицы int
void input_matrix (int arr[3][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {   
            cout << "Введите целое число: "<<endl;
            cin >> arr[i][j];
        }
    }   
}
//////// Инициализация квадратной матрицы double
void input_matrix (double arr[3][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {   
            cout << "Введите дробное число: "<<endl;
            cin >> arr[i][j];
        }
    }
    
}
//////// Инициализация квадратной матрицы char
void input_matrix (char arr[3][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {   
            cout << "Введите символ: "<<endl;
            cin >> arr[i][j];
        }
    }
    
}
// Вывод матрицы
///////////  Вывод матрицы на экран int
void print_matrix (int arr[3][3]){
   for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j]<<" ";   
        }
        cout <<endl;
    }
}
///////////  Вывод матрицы на экран double
void print_matrix (double arr[3][3]){
   for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j]<<" ";   
        }
        cout <<endl;
    }
}
///////////  Вывод матрицы на экран char
void print_matrix (char arr[3][3]){
   for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j]<<" ";   
        }
        cout <<endl;
    }
}
//Определение максимального и минимального элемента
//на главной диагонали матрицы;
/// int
void max_min (int arr[3][3]){
    int max = arr[0][0];
    int min = arr[0][0];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i==j && max<arr[i][j]){
                max = arr[i][j];
            }
            if (i==j && min>arr[i][j]){
                min = arr[i][j];
            }
        }
    }
    cout << "Минимальный элемент на главной диогонали матрицы  = "<< min<<endl;
    cout << "Максимальный элемент на главной диогонали матрицы  = "<< max<<endl;
}
//Определение максимального и минимального элемента
//на главной диагонали матрицы;
// double
void max_min (double arr[3][3]){
    double max = arr[0][0];
    double min = arr[0][0];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i==j && max<arr[i][j]){
                max = arr[i][j];
            }
            if (i==j && min>arr[i][j]){
                min = arr[i][j];
            }
        }
    }
    cout << "Минимальный элемент на главной диогонали матрицы  = "<< min<<endl;
    cout << "Максимальный элемент на главной диогонали матрицы  = "<< max<<endl;
}
//Определение максимального и минимального элемента
//на главной диагонали матрицы;
/// char
void max_min (char arr[3][3]){
    char max = arr[0][0];
    char min = arr[0][0];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i==j && max<arr[i][j]){
                max = arr[i][j];
            }
            if (i==j && min>arr[i][j]){
                min = arr[i][j];
            }
        }
    }
    cout << "Минимальный элемент на главной диогонали матрицы  = "<< min<<endl;
    cout << "Максимальный элемент на главной диогонали матрицы  = "<< max<<endl;
}

//Сортировка элементов по возрастанию отдельно для
//каждой строки матрицы.
//int
void bubbleSort(int arr[3][3])
{
    int x;
    for (int k = 0; k< 3; k++)
    {
        for (int j = 0; j < 3-1; j++)
        {
            for ( int i = 0; i < 3-j-1; i++)
            {   
                if (arr[k][i]>arr[k][i+1]){
                    x = arr[k][i];
                    arr[k][i] = arr[k][i+1];
                    arr[k][i+1] = x;
                }
            }
        }
    }
}
//Сортировка элементов по возрастанию отдельно для
//каждой строки матрицы.
//double
void bubbleSort(double arr[3][3])
{
    double x;
    for (int k = 0; k< 3; k++)
    {
        for (int j = 0; j < 3-1; j++)
        {
            for ( int i = 0; i < 3-j-1; i++)
            {   
                if (arr[k][i]>arr[k][i+1]){
                    x = arr[k][i];
                    arr[k][i] = arr[k][i+1];
                    arr[k][i+1] = x;
                }
            }
        }
    }
}
//Сортировка элементов по возрастанию отдельно для
//каждой строки матрицы.
//char
void bubbleSort(char arr[3][3])
{
    char x;
    for (int k = 0; k< 3; k++)
    {
        for (int j = 0; j < 3-1; j++)
        {
            for ( int i = 0; i < 3-j-1; i++)
            {   
                if (arr[k][i]>arr[k][i+1]){
                    x = arr[k][i];
                    arr[k][i] = arr[k][i+1];
                    arr[k][i+1] = x;
                }
            }
        }
    }
}
// Задание 2
int task_2(int a,int b){
    if (a!=0 && b!=0){
        if(a>b){
            a= a%b;
        }
        else{
            b=b%a;
        }
        return task_2(a,b);
    }
    else{
        return a+b;
    }
}
/// Задание 3
void cow_bull( int secret,int attempt = 1 ){
    int num;
    cout << "Угадай 4 значное число\nПопытка - "<<attempt<<endl;
    cout << "Введите 4 значное число"<<endl;
    cin >> num;
    if (num>9999 || num<1000){
        cout <<"Ошибка - введите 4 значное число"<<endl;
    }
    else if (num==secret){
        cout << "Число угадано "<<secret<<endl;
        cout << "Количество попыток "<<attempt<<endl;
    }
    else{
        /// нахождения коров
        int bull = 0,cow = 0,cash = -10 ;
        for (int i = 1; i <=1000; i*=10)
        {
            if ((secret/i%10)==(num/i%10)){
                cow++;
            }
            
        }
        /// нахождения быков
        for (int i = 1; i <= 1000; i*=10)
        {
            for (int j = 1; j <=1000; j*=10)
            {
                if ((secret/j%10)==(num/i%10) && (secret/j%10)!=cash) {
                    cash = secret/j%10;
                    bull++;
                }
            }  
        }   
        /// Вывод и рекурсия
        cout <<"Вы угадали "<<bull<<" быков и "<<cow<<" коров"<< endl;
        cow_bull(secret,attempt+1);
    }
    
     
}
///                                     main
int main()
{
    ///   Задание 1
    int choice;
    cout << "какой массив вы хотите создать ?\nЦелочисленный - 0\nС числом с плавывающей точкой - 1\nСимволный - 2"<<endl;
    cin>> choice;
    if (choice==0){
        int arr[3][3];
        input_matrix(arr);
        print_matrix(arr);
        max_min(arr);
        bubbleSort(arr);
        print_matrix(arr);
    }
    else if (choice==1){
        double arr[3][3];
        input_matrix(arr);
        print_matrix(arr);
        max_min(arr);
        bubbleSort(arr);
        print_matrix(arr);
    }
    else {
        char arr[3][3];
        input_matrix(arr);
        print_matrix(arr);
        max_min(arr);
        bubbleSort(arr);
        print_matrix(arr);
    }



///     Задание 2
    int a,b;
    cout << "Введите числа a и b: "<<endl;
    cin >>a>>b;
    cout<<"Нибольший общий делитель "<<a<<" и "<<b<<" = "<<task_2(a,b)<<endl;
///Задание 3
    srand(time(NULL));
    int rand = rand%8999+1000;
    cow_bull(rand);

    return 0;


}