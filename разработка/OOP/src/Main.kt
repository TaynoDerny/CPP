fun main() {
    println("Задание 1: ")
    val book1 = Book("Война и мир", "Лев Толстой", 1869, 1200.0)
    val book2 = Book("Преступление и наказание", "Фёдор Достоевский", 1866, 950.0)
    val book3 = Book("Мастер и Маргарита", "Михаил Булгаков", 1967, 1100.0)
    book2.price = 1050.0
    println("Книга: ${book1.title}, Автор: ${book1.author}, Год: ${book1.year}, Цена: ${book1.price}₽")
    println("Книга: ${book2.title}, Автор: ${book2.author}, Год: ${book2.year}, Цена: ${book2.price}₽")
    println("Книга: ${book3.title}, Автор: ${book3.author}, Год: ${book3.year}, Цена: ${book3.price}₽")

    println("\n=== Задание 2: Студенты ===")
    val student1 = Student("Иван", "Петров", "ИС-21")
    val student2 = Student("Анна", "Смирнова", "БИ-32")
    println(student1.fullName)
    println(student2.fullName)

    println("\nЗадание 3: ")
    val account = BankAccount(1000.0)
    println(account.formattedBalance)
    account.balance = -500.0
    account.balance = 2000.0
    println(account.formattedBalance)

    println("\n Задание 4")
    for (status in OrderStatus.values()) {
        println("${status.name} - ${status.description}")
    }

    println("\n Задание 5:")
    val prod1 = Product(1, "Ноутбук", 75000.0, true)
    val prod2 = Product(1, "Ноутбук", 75000.0, true)
    println("product1 == product2: ${prod1 == prod2}")
    val prod3 = prod1.copy(price = 70000.0)
    println("Оригинал: $prod1")
    println("Копия: $prod3")

    ProductCatalog.addProduct(prod1)
    ProductCatalog.addProduct(Product(2, "Мышь", 2500.0, true))
    ProductCatalog.addProduct(Product(3, "Клавиатура", 5000.0, false))

    println("\nВсе товары в каталоге:")
    for (product in ProductCatalog.products) {
        println(product)
    }

    println("\nПоиск товара с id = 2:")
    println(ProductCatalog.findById(2) ?: "Товар не найден")
}

class Book(
    val title: String,
    val author: String,
    var year: Int,
    var price: Double
)

class Student(
    val name: String,
    val surname: String,
    var group: String
) {
    val fullName: String

    init {
        fullName = "$name $surname"
        println("Создан студент: $fullName, группа: $group")
    }
}

class BankAccount(initialBalance: Double) {
    var balance: Double = initialBalance
        get() = field
        set(value) {
            if (value < 0) {
                println("Ошибка: баланс не может быть отрицательным!")
            } else {
                field = value
            }
        }

    val formattedBalance: String
        get() = "Баланс: $balance ₽"
}

enum class OrderStatus(val description: String) {
    NEW("Новый заказ"),
    PROCESSING("Заказ в обработке"),
    SHIPPED("Заказ отправлен"),
    DELIVERED("Заказ доставлен"),
    CANCELLED("Заказ отменён");

    fun isFinished(): Boolean {
        return this == DELIVERED || this == CANCELLED
    }
}

data class Product(
    val id: Int,
    val name: String,
    var price: Double,
    var inStock: Boolean
)

object ProductCatalog {
    private val _products = mutableListOf<Product>()

    val products: List<Product>
        get() = _products.toList()

    fun addProduct(product: Product) {
        _products.add(product)
    }

    fun findById(id: Int): Product? {
        return _products.find { it.id == id }
    }
}

