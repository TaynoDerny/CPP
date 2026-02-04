
#  Базовый класс
class LibraryItem:
    _id_counter = 1# Счетчик ID
    def __init__(self, title, author, year):
        self._title = title # Название
        self._author = author# Автор
        self._year = year# Год
        self.__item_id = f"ID-{LibraryItem._id_counter}"# ID
        LibraryItem._id_counter += 1
        self.__is_checked_out = False# Статус выдачи

    def get_title(self): return self._title
    def get_item_id(self): return self.__item_id
    def get_is_checked_out(self): return self.__is_checked_out
    
    def set_is_checked_out(self, status):# Изменение статуса
        if isinstance(status, bool):
            self.__is_checked_out = status
#  Книга 
class Book(LibraryItem):
    def __init__(self, title, author, year, genre, page_count):
        super().__init__(title, author, year) # Родительский конструктор
        self.genre = genre  # Жанр
        self.set_page_count(page_count)# Страницы

    def set_page_count(self, count):
        if int(count) >= 1: self.__page_count = count
        else: self.__page_count = 1

    def __str__(self):
        status = "Выдана" if self.get_is_checked_out() else "В наличии"
        return f"[Книга] {self.get_title()} | Автор: {self._author} | Страниц: {self.__page_count} | {status} | {self.get_item_id()}"
# Журнал 
class Magazine(LibraryItem):
    def __init__(self, title, author, year, issue_number):
        super().__init__(title, author, year)# Родительский конструктор
        self._issue_number = issue_number# Номер выпуска

    def get_magazine_info(self):# Информация о журнале
        status = "Выдана" if self.get_is_checked_out() else "В наличии"
        return f"[Журнал] {self._title} | Выпуск №{self._issue_number} | {status} | {self.get_item_id()}"
# DVD 
class DVD(LibraryItem):
    def __init__(self, title, author, year, duration, rating):
        super().__init__(title, author, year)# Родительский конструктор
        self.set_duration(duration) # Длительность
        self.set_rating(rating)# Рейтинг

    def set_duration(self, d): # Установить длительность
        self.__duration = d if 1 <= int(d) <= 300 else 120

    def set_rating(self, r):# Установить рейтинг
        valid = ["G", "PG", "PG-13", "R", "NC-17"]
        self.__rating = r if r in valid else "G"

    def __str__(self):
        status = "Выдана" if self.get_is_checked_out() else "В наличии"
        return f"[DVD] {self.get_title()} | Рейтинг: {self.__rating} | {self.__duration} мин | {status} | {self.get_item_id()}"

# Меню

library_storage = [] # Список объектов

def main_menu():
    while True:
        print("\n=== ЦЕНТРАЛЬНАЯ БИБЛИОТЕКА ===")
        print("1. Добавить книгу")
        print("2. Добавить журнал")
        print("3. Добавить DVD")
        print("4. Показать все предметы")
        print("5. Выдать/Вернуть предмет (по ID)")
        print("0. Выход")
        
        choice = input("\nВыберите действие: ")

        if choice == "1": 
            t = input("Название: ")
            a = input("Автор: ")
            y = input("Год: ")
            g = input("Жанр: ")
            p = input("Кол-во страниц: ")
            new_book = Book(t, a, y, g, p)
            library_storage.append(new_book)
            print("Книга добавлена!")

        elif choice == "2":
            t = input("Название: ")
            a = input("Издатель: ")
            y = input("Год: ")
            n = input("Номер выпуска: ")
            new_mag = Magazine(t, a, y, n)
            library_storage.append(new_mag)
            print("Журнал добавлен!")

        elif choice == "3":
            t = input("Название: ")
            a = input("Режиссер: ")
            y = input("Год: ")
            d = input("Длительность (мин): ")
            r = input("Рейтинг (G, PG, PG-13, R): ")
            new_dvd = DVD(t, a, y, d, r)
            library_storage.append(new_dvd)
            print("DVD добавлен!")

        elif choice == "4":# Показать все
            print("\n--- Список предметов ---")
            if not library_storage:
                print("Библиотека пуста.")
            for item in library_storage:
                if isinstance(item, Magazine):
                    print(item.get_magazine_info())
                else:
                    print(item)

        elif choice == "5":# Изменить статус
            search_id = input("Введите ID предмета: ")
            found = False
            for item in library_storage:
                if item.get_item_id() == search_id:
                    current_status = item.get_is_checked_out()
                    item.set_is_checked_out(not current_status)
                    new_status = "выдан" if not current_status else "возвращен"
                    print(f"Предмет {item.get_title()} успешно {new_status}!")
                    found = True
                    break
            if not found:
                print("Предмет с таким ID не найден.")

        elif choice == "0": # Выход
            print("Программа завершена.")
            break
        else:
            print("Неверный ввод, попробуйте снова.")

if __name__ == "__main__":
    main_menu()