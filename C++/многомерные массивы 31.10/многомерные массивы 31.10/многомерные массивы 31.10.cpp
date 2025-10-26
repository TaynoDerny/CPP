
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    const int row = 3;
    const int col = 6;
    int arr_1[row][col];
    int num_1;
    cout << "Введите число: " << endl;
    cin >> num_1;
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++ )
        {
            arr_1[i][j] = num_1;
            cout << arr_1[i][j] << " ";
            num_1 = num_1 * 2;
        }
        cout << endl;
    }
    //Задача  2
    int arr_2[row][col];
    int num_2;
    cout << "Введите число: " << endl;
    cin >> num_2;
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for ( int j = 0; j < col; j++)
        {
            arr_2[i][j] = num_2;
            cout << arr_2[i][j] << " ";
            num_2++;
        }
        cout << endl;
    }
    
   
    //Задача 3
    int arr_3[row][col];
    int shift;
    int sv;
    cout << "Введите сдвиг: " << endl;
    cin >> shift;
    cout << "Введите положения сдвига 1 - влево; 2 - вправо; 3 - вверх; 4 - вниз; : " << endl;
    cin >> sv;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr_3[i][j] = rand() % 9;
            cout << arr_3[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            switch(sv){
            case 1:
                if (j + shift >= col)
                    cout << arr_3[i][j + shift - col] << " ";
                else
                    cout << arr_3[i][j + shift] << " ";
                break;
                
            case 2:
                if (j - shift < 0)
                    cout << arr_3[i][j - shift + col] << " ";
                else
                    cout << arr_3[i][j - shift] << " ";
                break;
            case 3:
                if (i + shift >= row)
                    cout << arr_3[i + shift - row][j] << " ";
                else
                    cout << arr_3[i + shift][j] << " ";
                break;
            case 4:
                if (i - shift < 0)
                    cout << arr_3[i - shift + row][j] << " ";
                else
                    cout << arr_3[i - shift][j] << " ";
                break;

            default:
                return 0;

        }
            
        }
        cout << endl;
    }

}

