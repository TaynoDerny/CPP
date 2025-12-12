#include <iostream>

using namespace std;
int lenght(char str[]){
    int size = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        size++;
    }
    return size;
}


void erase(char str[], int pozit, int col_symb=1) {
    int i = pozit;
    int j = pozit + col_symb;
    
    while (str[j] != '\0') {
        str[i] = str[j];
        i++;
        j++;
    }
    
    str[i] = '\0';


}
void removeChar(char str[],char symb){
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == symb) {
            erase(str, i);
        }
        else {
            i++; 
        }
    }
}

void replace(char str[],char symb,char tosymb){
    for (int i = 0; i < str[i] != '\0'; i++)
    {
        if (str[i]==symb){
            str[i] == tosymb;
        }
    }
    
}
void past(char str[],int pSymb,char symb){
    for (int i = lenght(str); i >=pSymb; i--)
    {
        str[i+1] = str[i];
    }
    str[pSymb]=symb;
    
}
int countSymb(char str[], char symb){
    int count = 0;
    for (int i = 0; i < str[i] != '\0'; i++)
    {
        if (str[i]==symb){
            count++;
        }
    }
    return count;
}
void Symb_col(char str[]){
    int letters=0,digits=0,others=0;
    for (int i = 0; str[i]!='\0'; i++)
    {   
        
        if((str[i]>='A' && str[i]<='Z')||(str[i]>='a' && str[i]<='z'))letters++;
        else if(str[i]>='0' && str[i]<='9')digits++;
        else others++;
    }

    cout << "Количество букв = "<<letters<<endl;
    cout << "Количество цифр = "<<digits<<endl;
    cout << "Количество остальных символов = "<<others<<endl;
    
}
void strPrint(char arr[]){
    for (int i = 0; arr[i]!='\0'; i++)
    {
        cout <<arr[i];
    }
    cout <<endl;
    
}



int main(){
    char str[] = "Hello word.";
    char str_2[]="Hello word.";char str_3[]="Hello word.";char str_4[]="Hello word.";char str_5[]="Hello word.";char str_6[]="1.Hello word.";
    /// Задание 1
    strPrint(str);
    int nSymbol;
    cout << "Введите какой символ строки удалить от 0 до "<<lenght(str)-1<<" (пробелы включены): "<<endl;
    cin>> nSymbol;
    erase(str,nSymbol);
    strPrint(str);
    


    // Задание 2
    strPrint(str_2);
    cout << "Введите какой символ удалить из всей строки : "<<endl;
    char symb;
    cin >>symb;
    removeChar(str_2,symb);
    strPrint(str_2);


    
    /// Задача 3
    strPrint(str_3);
    char pasteSymb;
    int numberSymb;
    cout<< "Введите символ который хотите вставить:"<<endl;
    cin>>pasteSymb;
    cout << "Введите перед каким символ строки вставить от 0 до "<<lenght(str_3)-1<<" (пробелы включены): "<<endl;
    cin >>numberSymb;
    past(str_3,numberSymb,pasteSymb);
    strPrint(str_3);


    // Задача 4
    strPrint(str_4);
    replace(str_4,'.','!');
    strPrint(str_4);

    // Задача 5
    strPrint(str_5);
    Symb_col(str_5);
    


    return 0 ;
}