#include <iostream>
using namespace std;


// Функция возврашающая длину массива char 
int strLong(char str[]){
    int size = 0;
    for (int i = 0; str[i]!='\0'; i++)
    {
        size++;
    }
    return size;
}
// Функция выводящая массив char
void strPrint(char arr[]){
    for (int i = 0; arr[i]!='\0'; i++)
    {
        cout <<arr[i];
    }
    cout <<endl;
    
}

/// Ввод массива символов пользователем 
int input_str(char arr[]) {

    cout << "Введите предложение на англиском (максимальное количество символов 99): ";
    
    int max_size = 100; 
    int i = 0;
    char ch;
    ch = cin.get();
    if (ch == '\n') {
        ch = cin.get();
    }
    /// Ввод предложения 
    while (i < max_size - 1 && ch != '\n' ) {
        arr[i++] = ch;
        ch = cin.get();
    }
    arr[i] = '\0';
    
    
    // если больше 99 символ
    if (ch != '\n' ) {
        while (cin.get() != '\n' ) {

        }
        cout << "ОШИБКА: введено больше " << max_size-1 << " символов!" << endl;
    }
    
    return i; // Возвращаем длину строки
}



int polindrom(char offer[], int size) {
    for (int i = 0; i < size / 2; i++) {
        if (offer[i] != offer[size - i - 1]) {
            return 0;  // Не палиндром
        }
    }
    return 1;  // Палиндром
}

int main(){

    ////////////// Задание 1
    char words[100];
    int longe = input_str(words);
    words[longe];

    for (int i = 0; words[i]!='\0'; i++){
        if(words[i]==' '){
            words[i]='\t';
        }
    }
    cout << "Предложения в котором пробелы заменены на табуляцию:"<<endl;
    strPrint(words);


    /////////////////////////// задание 2
    
    char offer[100];
    
    
    int len = input_str(offer);
    offer[len];
    int letters=0,digits=0,others=0;
    for (int i = 0; offer[i]!='\0'; i++)
    {   
        
        if((offer[i]>='A' && offer[i]<='Z')||(offer[i]>='a' && offer[i]<='z'))letters++;
        else if(offer[i]>='0' && offer[i]<='9')digits++;
        else others++;
    }

    cout << "Количество букв = "<<letters<<endl;
    cout << "Количество цифр = "<<digits<<endl;
    cout << "Количество остальных символов(русская буква занимает 2 символа) = "<<others<<endl;
    
    ////////////////// Задание 3
    int word=0;
    for (int i = 0; offer[i]!='\0'; i++)
    {
        if(offer[i]==' ')word++;
        
    }
    cout << "Количество слов = "<<word+1<<endl;

    /////////////////// Задание 4
    if (polindrom(offer,len)==1){
        cout << "Палиндром"<<endl;
    }
    else{
        cout << "Не палиндром"<<endl;
    }
    





    return 0;
}