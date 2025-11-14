#include <iostream>

using namespace std;

int sum_pc = 0;//Задание 2
int sum_player = 0;//Задание 2
int counter_pc = 0;
int counter_player = 0;

//Задание 1
void convert_number(int num,int sysNum ){
    if (num<0 ||sysNum<2||sysNum>36){
        cout<<"ОШИБКА - сило не должно быть отрицательным, а система счисления привыщать 36"<<endl;
    }
    else
    {
    const int size = 100;
    char digits[size];
    int index = 0;
    while (num!=0){
    if (num%sysNum<10){
        digits[index++]='0'+(num%sysNum);
    }
    else if (num%sysNum>=10){
        digits[index++]=char('A' +(num%sysNum-10));
    }
    num = num/sysNum;
    }
    for (int i = index-1; i >= 0; i--)
    {   
        cout << digits[i];
    }
    cout<<endl;
    }
}
//Задание 2 Задание 2 Задание 2 Задание 2 Задание 2  Задание 2 Задание 2 Задание 2 Задание 2 Задание 2
void game_player(){
    int r = rand()%5+1;
    char player_throw;
    cout<<"Кидай кубик...\n## Что бы кинуть кубик введите - W ##"<<endl;
    cin >> player_throw;
    //     Кубики отображаются с помощью символов.    
    switch (r){
    case 1:
    cout << "┌─────────┐\n│         │\n│    ●    │\n│         │\n└─────────┘";
    break;
    case 2:
    cout << "┌─────────┐\n│ ●       │\n│         │\n│       ● │\n└─────────┘";
    break;
    case 3:
    cout << "┌─────────┐\n│ ●       │\n│    ●    │\n│       ● │\n└─────────┘";
    break;
    case 4:
    cout << "┌─────────┐\n│ ●     ● │\n│         │\n│ ●     ● │\n└─────────┘";
    break;
    case 5:
    cout << "┌─────────┐\n│ ●     ● │\n│    ●    │\n│ ●     ● │\n└─────────┘";
    break;
    case 6:
    cout << "┌─────────┐\n│ ●     ● │\n│ ●     ● │\n│ ●     ● │\n└─────────┘";
    break;
    }              
    cout << "Тебе выпало: "<< r <<endl;
    sum_player+=r;
    counter_player++;
}
void game_pc(){
    int r = rand()%5+1;
    char pc_throw;
    cout<<"Я кидаю кубик...\n## Что бы продолжить введите  - W ##"<<endl;
    cin >> pc_throw;
    switch (r){
    case 1:
    cout << "┌─────────┐\n│         │\n│    ●    │\n│         │\n└─────────┘";
    break;
    case 2:
    cout << "┌─────────┐\n│ ●       │\n│         │\n│       ● │\n└─────────┘";
    break;
    case 3:
    cout << "┌─────────┐\n│ ●       │\n│    ●    │\n│       ● │\n└─────────┘";
    break;
    case 4:
    cout << "┌─────────┐\n│ ●     ● │\n│         │\n│ ●     ● │\n└─────────┘";
    break;
    case 5:
    cout << "┌─────────┐\n│ ●     ● │\n│    ●    │\n│ ●     ● │\n└─────────┘";
    break;
    case 6:
    cout << "┌─────────┐\n│ ●     ● │\n│ ●     ● │\n│ ●     ● │\n└─────────┘";
    break;
    }
    cout << "Мне выпало: "<< r <<endl;
    sum_pc+=r;
    counter_pc++;
}
void game_cub(){
    char choice;
    cout << "=====Правила игры======\n Имеется два игральных кубика со значениями от 1 до 6"<<endl;
    cout << "Кубики бросаются поочередно Побеждает тот, у кого сумма выпавших очков по итогам пяти бросков больше."<<endl;
    cout << "Хочешь сходить первым ?\n## Введите Y - если да и N - если нет. ##"<<endl;
    cin >> choice;
    if (choice=='Y'){
        cout <<"Ты ходишь первым."<<endl;
        for (int i = 0; i < 5; i++)
        {
            if(i%2==0)game_player();
            else game_pc();
        }
        
    }
    else if (choice=='N'){
        cout << "Хорошо я хожу первым."<<endl;
        for (int i = 0; i < 5; i++)
        {
            if(i%2==0)game_pc();
            else game_player();
        }
    }
    cout <<"За 5 игры средняя сумма по броскам\nТвоя: "<<sum_player/counter_player<<"\nМоя: " <<sum_pc/counter_pc<<endl;
    if (sum_pc/counter_pc>sum_player/counter_player)
        cout<<"Я победил!!"<<endl;
    else if (sum_pc/counter_pc<sum_player/counter_player)
        cout<<"Ты победил!!"<<endl;
    else 
        cout<<"Ничья"<<endl;
}
//Задание 2 конец Задание 2 конец Задание 2 конец Задание 2 конец Задание 2 конец Задание 2 конец Задание 2 конец
//Задание 3
void rectangle(int n,int k){
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout<<endl;
    }
    
}
//Задание 4
int fact(int num)
{   int fact = 1;
    for (int i = 1; i <=num; i++)
    {
        fact*=i;
    }
    return fact;
    
}
//Задание 5
void numP (int num){
    if (num==1){
        cout << num << " Простое число"<<endl;
    }
    else{
        for (int i = 2; i < num; i++)
        {   
            
            if (num%i!=0){
                cout << num << " Простое число"<<endl;
                break;
            }
            else{
                cout << num << " Не простое число"<<endl;
                break;
            }

        }
    }
}
/// Функция рандомного массива
void rand_arr(int arr[],const int size ){
    cout <<"\nРандомный список:\n";
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i]=rand()%49+1;
        cout << arr[i]<<" ";
    }
}
//Задание 6
void max_min_arr(int arr[],int size){
    
    int max =  arr[0],elem_max=0;
    int min = arr[0],elem_min=0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]>max){
            max = arr[i];
            elem_max = i;
        }
        if (arr[i]<min){
            min = arr[i];
            elem_min = i;
        }
    }
    cout <<endl;
    cout << "Max: "<< max <<" Min: "<< min<<endl;
    cout << "Elment = "<<elem_max<< " Element = "<< elem_min<<endl;  
}
//Задание 7
void revers(int arr[],int size){
    for (int i = size-1; i >= 0; i--)
    {   
        cout << arr[i]<<" "; 
    }
    
}
int main(){
    int num,sysNum;
    int n,k;
    int fact_num;
    int number;
    const int size = 8;
    int arr[size];
    //Задание 1
    cout << "Введите число и систему счисления: "<<endl;
    cin >> num >> sysNum;
    convert_number(num,sysNum);
    //Задание 2
    game_cub();
    //Задание 3
    cout << "Введите высоту и ширину прямоугольника"<<endl;
    cin >> n >> k;
    rectangle(n,k);
    //Задание 4
    cout << "Ввидите число которого хотите получить факторал"<<endl;
    cin >> fact_num;
    cout <<fact_num<<"! = "<<fact(fact_num)<<endl;
    //Задание 5
    cout << "Ввидите число :"<<endl;
    cin >> number;
    numP(number);

    //Задание 6
    rand_arr(arr,size);
    max_min_arr(arr,size);
    //Задание 7-
    cout<< "развернутый массив"<<endl;
    revers(arr,size);
    return 0;
}