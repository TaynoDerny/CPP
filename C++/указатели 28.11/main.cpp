#include <iostream>

using namespace std;

// Задача 1
int task_1(int a,int b){
    int *ptr_a,*ptr_b;
    ptr_a = &a;
    ptr_b = &b;
    if (*ptr_a>*ptr_b) return *ptr_a;
    else return *ptr_b;

} 
// Задача 2
void task_2(int* a){
    if (*a==0) cout << "Вы ввели ноль оно не положительно не отрицательно"<<endl;
    else if (*a>0) cout <<"Вы ввели число с положительным знаком " <<endl;
    else cout << "Вы ввели число с отрицательным знаком"<<endl;
}
// Задача 3
void exc(int *ptr1, int *ptr2){
   int temp = *ptr1;
   *ptr1 = *ptr2;
   *ptr2 = temp;

}
// Задача 4
void calculator (int *a,char op,int *b){

        switch (op) {
        case '+':
            cout<<"Ответ: " << *a+*b <<endl;
            break;
        case '-':
            cout<<"Ответ: "<< *a-*b<<endl;
            break;
        case '*':
            cout<<"Ответ: " << *a * *b<<endl;
            break;
        case '/':
            if (*b==0){
                 cout << "На ноль делить нельзя"<<endl;
                 break;
            }
            else{
                cout<<"Ответ: " << *a / *b <<endl;
            }
        default:
            cout << "Введите операци: / * - + "<<endl;
    }
}
// Задача 5
void sum_arr(int *arr,int size){
    int sum =0;
    for (int i = 0; i < size; i++)
    {
        sum+=*arr+i;
    }
    cout << "Cумма массива = "<<sum<<endl;
    
}
int main(){
    // Задача 1
    int num_a,num_b;
    cout << "Введите число a и b"<<endl;
    cin >> num_a>>num_b;
    cout << "Большое из чисел число "<<task_1(num_a,num_b)<<endl;
// Задача 2
    int num;
    int *ptr = &num;
    cout << "Введите число"<<endl;
    cin >> *ptr;
    task_2(ptr);
// Задача 3
    cout << "Введите число a и b"<<endl;
    cin >> num_a>>num_b;
    cout <<"a = "<<num_a<<" b = "<<num_b<<endl;
    exc(&num_a,&num_b);
    cout <<"a = "<<num_a<<" b = "<<num_b<<endl;
// Задача 4
    char op;
    cout << "Введите число a, операцию и b"<<endl;
    cin >> num_a>>op>>num_b;
    calculator(&num_a,op,&num_b);
// Задача 5
    const int size = 5;
    int arr[size]{1,2,3,4,5};
    sum_arr(arr,size);



    


}