#include <iostream>

using namespace std;

int pow(int a,int n){
    if(n==1){
        return a;
    }
    else if (n==0){
        return 1;
    }
    else{
        return a * pow(a,n-1);
    }
    
}
void pain(int n){
    if (n==1)
        cout<<"*";
    else{
        cout <<"*";
        pain(n-1);
    }
}
int sum_range(int a,int b,int sum=0){
    if (a==b-1){
        return sum;
    }
    else{
        a++;
        sum+=a;
        return sum_range(a,b,sum);
    }
}
void rand_arr(int arr[],int size){
    srand(time(NULL));
    cout<<"Рандомный массив"<<endl;
    for (int i = 0; i < size; i++)
    {
        arr[i]=rand()%99;
        cout << arr[i]<<" ";
    }
}
void task_4(int arr[],int size,int min=991,int a = 0,int element=0){
    int sum=0;
    if(a+10<=100){
        for (int i = 0+a; i < 10+a; i++)
        {
            sum+=arr[i];
        }
        if(sum<min){
            min=sum;
            element=a;
        }
        task_4(arr,size,min,a+1,element);
    }
    else{
        cout << "Элемент: "<<element<<endl;
        cout<< "мин "<<min<<endl;
    }
}
int max_arr(int arr[3]){
    int max = arr[0];
    for (int i = 0; i < 3; i++)
    {
        if (arr[i]>max){
            max=arr[i];
        }   
    }
    return max;
}
int max_arr(int arr[3][3]){
    int max = arr[0][0];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j]>max){
                max=arr[i][j];
            }
        }   
    }
    return max;
}
int max_arr(int arr[3][3][3]){
    int max = arr[0][0][0];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int g = 0; g < 3; g++)
            {
                if (arr[i][j][g]>max){
                max=arr[i][j][g];
                }
            }  
        }   
    }
    return max;
}
int max (int a, int b, int c){
    if(a>b && a>c){
        return a;
    }
    else if (b>a && b>c){
        return b;
    }
    else
        return c;
}   

int main(){
    int a_1,n_1;
    cout << "Введите основание степени и степень"<<endl;
    cin >> a_1>> n_1;
    cout<<pow(a_1,n_1)<<endl;
    int stars;
    cout<<"Введите количесвто звездочек"<<endl;
    cin>> stars;
    pain(stars);
    cout<<endl;
    int range_a,range_b;
    cout <<"Введите границы a и b"<<endl;
    cin >> range_a>>range_b;
    cout<<sum_range(range_a,range_b)<<endl;

    int size =100;
    int arr[size];
    rand_arr(arr,size);
    cout<<endl;
    task_4(arr,size);

     //Задача 5
    int arr_4[3] = {1,3,2};
    int arr_4_2[3][3] = {{1,3,-1},{4,12,3}};
    int arr_4_3[3][3][3] = {{4,29,92},{99,-13,12},{991,1,1}};
    cout <<"Максимальное число в 1 мерном массиве "<<max_arr(arr_4)<<endl;
    cout <<"Максимальное число в 2 мерном массиве "<<max_arr(arr_4_2)<<endl;
    cout <<"Максимальное число в 3 мерном массиве "<<max_arr(arr_4_3)<<endl;

    int choice_5;
    int a_5,b_5,c_5;
    cout << "Сколько целых числе вы хотите ввести 2 или 3"<<endl;
    cin >> choice_5;
    if (choice_5==2){
        cin>>a_5>>b_5;
        cout <<"Максимальное число  = "<<max(a_5,b_5)<<endl;
    }
    else if (choice_5==3){
        cin >>a_5>>b_5>>c_5;
        cout <<"Максимальное число  = "<<max(a_5,b_5,c_5)<<endl;
    }
    else{
        cout << "Ошибка - введите либо 3 либо 3"<<endl;
    }
    return 0;
}