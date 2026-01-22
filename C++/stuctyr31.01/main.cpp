#include <iostream>
#include <string>

using namespace std;

struct VIDEO_SHOP {
    string movie_name;
    string director;
    string genre;
    int popularity_rating;
    double disk_price;
};

// Функция для добавления записи
void add_record(VIDEO_SHOP* &shop, int &size) {
    VIDEO_SHOP* new_shop = new VIDEO_SHOP[size + 1];
    
    for (int i = 0; i < size; i++) {
        new_shop[i] = shop[i];
    }
    
    cout << "\n=== Добавление новой записи ===" << endl;
    cout << "Название фильма: ";
    cin.ignore();
    getline(cin, new_shop[size].movie_name);
    
    cout << "Режиссер: ";
    getline(cin, new_shop[size].director);
    
    cout << "Жанр: ";
    getline(cin, new_shop[size].genre);
    
    cout << "Рейтинг популярности (1-10): ";
    cin >> new_shop[size].popularity_rating;
    
    cout << "Цена диска: ";
    cin >> new_shop[size].disk_price;
    
    delete[] shop;
    shop = new_shop;
    size++;
    
    cout << "Запись успешно добавлена!" << endl;
}

// Функция для показа всех записей
void show_all(const VIDEO_SHOP* shop, int size) {
    if (size == 0) {
        cout << "\nКаталог пуст!" << endl;
        return;
    }
    
    cout << "\n=== ВСЕ ЗАПИСИ В КАТАЛОГЕ ===" << endl;
    for (int i = 0; i < size; i++) {
        cout << "\nЗапись #" << i + 1 << endl;
        cout << "Название фильма: " << shop[i].movie_name << endl;
        cout << "Режиссер: " << shop[i].director << endl;
        cout << "Жанр: " << shop[i].genre << endl;
        cout << "Рейтинг популярности: " << shop[i].popularity_rating << "/10" << endl;
        cout << "Цена диска: " << shop[i].disk_price << " руб." << endl;
    }
    cout << "\nВсего записей: " << size << endl;
}

// Функция поиска по названию
void search_name(const VIDEO_SHOP* shop, int size) {
    if (size == 0) {
        cout << "\nКаталог пуст!" << endl;
        return;
    }
    
    string name;
    cout << "\nВведите название фильма для поиска: ";
    cin.ignore();
    getline(cin, name);
    
    bool found = false;
    cout << "\n=== РЕЗУЛЬТАТЫ ПОИСКА ПО НАЗВАНИЮ ===" << endl;
    for (int i = 0; i < size; i++) {
        if (shop[i].movie_name.find(name) != string::npos) {
            found = true;
            cout << "\nНайден фильм #" << i + 1 << endl;
            cout << "Название: " << shop[i].movie_name << endl;
            cout << "Режиссер: " << shop[i].director << endl;
            cout << "Жанр: " << shop[i].genre << endl;
            cout << "Рейтинг: " << shop[i].popularity_rating << "/10" << endl;
            cout << "Цена: " << shop[i].disk_price << " руб." << endl;
        }
    }
    
    if (!found) {
        cout << "Фильмы с названием \"" << name << "\" не найдены." << endl;
    }
}

// Функция поиска по жанру
void search_genre(const VIDEO_SHOP* shop, int size) {
    if (size == 0) {
        cout << "\nКаталог пуст!" << endl;
        return;
    }
    
    string genre;
    cout << "\nВведите жанр для поиска: ";
    cin.ignore();
    getline(cin, genre);
    
    bool found = false;
    cout << "\n=== РЕЗУЛЬТАТЫ ПОИСКА ПО ЖАНРУ ===" << endl;
    for (int i = 0; i < size; i++) {
        if (shop[i].genre.find(genre) != string::npos) {
            found = true;
            cout << "\nНайден фильм #" << i + 1 << endl;
            cout << "Название: " << shop[i].movie_name << endl;
            cout << "Режиссер: " << shop[i].director << endl;
            cout << "Жанр: " << shop[i].genre << endl;
            cout << "Рейтинг: " << shop[i].popularity_rating << "/10" << endl;
            cout << "Цена: " << shop[i].disk_price << " руб." << endl;
        }
    }
    
    if (!found) {
        cout << "Фильмы жанра \"" << genre << "\" не найдены." << endl;
    }
}

// Функция поиска по режиссеру
void search_director(const VIDEO_SHOP* shop, int size) {
    if (size == 0) {
        cout << "\nКаталог пуст!" << endl;
        return;
    }
    
    string director;
    cout << "\nВведите режиссера для поиска: ";
    cin.ignore();
    getline(cin, director);
    
    bool found = false;
    cout << "\n=== РЕЗУЛЬТАТЫ ПОИСКА ПО РЕЖИССЕРУ ===" << endl;
    for (int i = 0; i < size; i++) {
        if (shop[i].director.find(director) != string::npos) {
            found = true;
            cout << "\nНайден фильм #" << i + 1 << endl;
            cout << "Название: " << shop[i].movie_name << endl;
            cout << "Режиссер: " << shop[i].director << endl;
            cout << "Жанр: " << shop[i].genre << endl;
            cout << "Рейтинг: " << shop[i].popularity_rating << "/10" << endl;
            cout << "Цена: " << shop[i].disk_price << " руб." << endl;
        }
    }
    
    if (!found) {
        cout << "Фильмы режиссера \"" << director << "\" не найдены." << endl;
    }
}

// Функция поиска самого популярного фильма в жанре
void most_popular_genre(const VIDEO_SHOP* shop, int size) {
    if (size == 0) {
        cout << "\nКаталог пуст!" << endl;
        return;
    }
    
    string genre;
    cout << "\nВведите жанр для поиска самого популярного фильма: ";
    cin.ignore();
    getline(cin, genre);
    
    int max_rating = -1;
    int index = -1;
    
    for (int i = 0; i < size; i++) {
        if (shop[i].genre.find(genre) != string::npos) {
            if (shop[i].popularity_rating > max_rating) {
                max_rating = shop[i].popularity_rating;
                index = i;
            }
        }
    }
    
    if (index != -1) {
        cout << "\n=== САМЫЙ ПОПУЛЯРНЫЙ ФИЛЬМ В ЖАНРЕ \"" << genre << "\" ===" << endl;
        cout << "Название: " << shop[index].movie_name << endl;
        cout << "Режиссер: " << shop[index].director << endl;
        cout << "Жанр: " << shop[index].genre << endl;
        cout << "Рейтинг популярности: " << shop[index].popularity_rating << "/10" << endl;
        cout << "Цена диска: " << shop[index].disk_price << " руб." << endl;
    } else {
        cout << "Фильмы жанра \"" << genre << "\" не найдены." << endl;
    }
}

//  меню
void show_menu() {
    cout << "\n=== ВИДЕОМАГАЗИН ===" << endl;
    cout << "1. Показать все записи" << endl;
    cout << "2. Добавить запись" << endl;
    cout << "3. Поиск по названию" << endl;
    cout << "4. Поиск по жанру" << endl;
    cout << "5. Поиск по режиссеру" << endl;
    cout << "6. Самый популярный фильм в жанре" << endl;
    cout << "7. Выход" << endl;
    cout << "Выберите действие: ";
}

int main() {
    VIDEO_SHOP* shop = nullptr;
    int size = 0;
    int choice;
    

    shop = new VIDEO_SHOP[2];
    size = 2;
    
    shop[0] = {"Побег из Шоушенка", "Фрэнк Дарабонт", "Драма", 9, 799.99};
    shop[1] = {"Крестный отец", "Фрэнсис Форд Коппола", "Криминал", 10, 899.99};
    
    do {
        show_menu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                show_all(shop, size);
                break;
            case 2:
                add_record(shop, size);
                break;
            case 3:
                search_name(shop, size);
                break;
            case 4:
                search_genre(shop, size);
                break;
            case 5:
                search_director(shop, size);
                break;
            case 6:
                most_popular_genre(shop, size);
                break;
            default:
                cout << "\nНеверный выбор! Попробуйте снова." << endl;
        }
    } while (choice != 7);
    
    delete[] shop;
    
    return 0;
}