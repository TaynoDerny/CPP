class Book:
    def __init__(self,title,author,year,isbn,pages):
        self.title = title
        self.author = author
        self.year = year
        self.isbn = isbn
        self.pages = pages
        self.is_available = True

    def borrow_book(self):
        if self.is_available:
            self.is_available = False
            print(f'Книга "{self.title}" успешно взята из библиотеки')
            return True
        else:
            print(f'Книга "{self.title}" уже взята, недоступна для выдачи')
            return False
    
    def return_book(self):
        if not self.is_available:
            self.is_available = True
            print(f'Книга "{self.title}" успешно возвращена в библиотеку')
            return True
        else:
            print(f'Книга "{self.title}" уже находится в библиотеке')
            return False
    
    def display_info(self):
        status = "Доступна" if self.is_available else "Выдана"
        print(f"Название: {self.title}")
        print(f"Автор: {self.author}")
        print(f"Год издания: {self.year}")
        print(f"ISBN: {self.isbn}")
        print(f"Количество страниц: {self.pages}")
        print(f"Статус: {status}")
        print("-" * 40)



book1 = Book(
    title="Преступление и наказание",
    author="Фёдор Достоевский",
    year=1866,
    isbn="978-5-17-090879-1",
    pages=608
)

book2 = Book(
    title="Мастер и Маргарита",
    author="Михаил Булгаков",
    year=1967,
    isbn="978-5-389-06204-3",
    pages=480
)

# Тестирование

book1.borrow_book()

book1.return_book()

book2.borrow_book()
book2.borrow_book()

book2.return_book()