

fun main() {
    println("=== Базовый уровень ===\n")

    // 1. Простые функции
    println("1. greetUser:")
    greetUser("Анна")
    greetUser("Борис")
    greetUser("Виктория")

    // 2. Функции с возвращаемым значением
    println("\n2. calculateCircleArea:")
    println("Радиус 5.0 -> ${calculateCircleArea(5.0)}")
    println("Радиус 10.0 -> ${calculateCircleArea(10.0)}")
    println("Радиус 2.5 -> ${calculateCircleArea(2.5)}")

    // 3. Параметры по умолчанию
    println("\n3. printPersonInfo:")
    printPersonInfo("Дмитрий", 25, "Москва")
    printPersonInfo("Елена", 30)
    printPersonInfo("Жанна")

    // 4. Именованные аргументы
    println("\n4. Именованные аргументы (другой порядок):")
    printPersonInfo(city = "Казань", name = "Игорь", age = 28)

    println("\n=== Средний уровень ===\n")

    // 5. Vararg-параметры
    println("5. calculateAverage:")
    println("Среднее (1, 2, 3) = ${calculateAverage(1, 2, 3)}")
    println("Среднее (10, 20, 30, 40, 50) = ${calculateAverage(10, 20, 30, 40, 50)}")
    println("Среднее (5, 5, 5, 5) = ${calculateAverage(5, 5, 5, 5)}")

    // 6. Однострочные функции
    println("\n6. Однострочные функции:")
    println("Квадрат 7 = ${square(7)}")
    println("Число 4 чётное? ${isEven(4)}")
    println("Число 5 чётное? ${isEven(5)}")
    println("Максимум из 10 и 20 = ${maxOf(10, 20)}")

    // 7. Локальные функции
    println("\n7. validatePassword:")
    println("Пароль 'Pass123' -> ${validatePassword("Pass123")}")
    println("Пароль 'Password123' -> ${validatePassword("Password123")}")
    println("Пароль 'password123' -> ${validatePassword("password123")}")
    println("Пароль 'PASSWORD' -> ${validatePassword("PASSWORD")}")

    println("\n=== Продвинутый уровень ===\n")

    // 8. Перегрузка функций calculateArea
    println("8. calculateArea (перегрузка):")
    println("Площадь круга (r=3.0) = ${calculateArea(3.0)}")
    println("Площадь прямоугольника (4.0 x 5.0) = ${calculateArea(4.0, 5.0)}")
    println("Площадь треугольника (основание 4.0, высота 3.0) = ${calculateArea(4.0, 3.0, true)}")

    // 9. Функции высшего порядка
    println("\n9. filterList:")
    val numbers = listOf(1, 5, 8, 12, 15, 20, 3, 7, 18)
    println("Исходный список: $numbers")
    println("Чётные: ${filterList(numbers) { it % 2 == 0 }}")
    println("Больше 10: ${filterList(numbers) { it > 10 }}")
    println("В диапазоне 5..15: ${filterList(numbers) { it in 5..15 }}")

    // 10. Замыкания
    println("\n10. createCounter:")
    val counterFrom5 = createCounter(5)
    println("Счётчик (нач. 5): ${counterFrom5()}") // 6
    println("Счётчик (нач. 5): ${counterFrom5()}") // 7
    println("Счётчик (нач. 5): ${counterFrom5()}") // 8
    val counterFrom0 = createCounter(0)
    println("Счётчик (нач. 0): ${counterFrom0()}") // 1
    println("Счётчик (нач. 0): ${counterFrom0()}") // 2
}

// 1.
fun greetUser(name: String) {
    println("Привет, $name!")
}

// 2.
fun calculateCircleArea(radius: Double): Double {
    val pi = 3.141592653589793
    return pi * radius * radius
}

// 3.
fun printPersonInfo(name: String, age: Int = 18, city: String = "Неизвестно") {
    println("Имя: $name, Возраст: $age, Город: $city")
}

// 5.
fun calculateAverage(vararg numbers: Int): Double {
    if (numbers.isEmpty()) return 0.0

    var sum = 0
    for (num in numbers) {
        sum += num
    }
    return sum.toDouble() / numbers.size
}

// 6. Однострочные функции
fun square(n: Int) = n * n
fun isEven(n: Int) = n % 2 == 0
fun maxOf(a: Int, b: Int) = if (a > b) a else b

// 7. Локальные функции
fun validatePassword(password: String): Boolean {
    fun hasMinLength(): Boolean {
        var length = 0
        for (c in password) {
            length++
        }
        return length >= 8
    }

    fun hasDigit(): Boolean {
        for (c in password) {
            if (c in '0'..'9') return true
        }
        return false
    }

    fun hasUpperCase(): Boolean {
        for (c in password) {
            if (c in 'A'..'Z') return true
        }
        return false
    }

    return hasMinLength() && hasDigit() && hasUpperCase()
}

// 8. Перегруженные функции calculateArea
fun calculateArea(radius: Double): Double {
    val pi = 3.141592653589793
    return pi * radius * radius
}

fun calculateArea(width: Double, height: Double): Double = width * height

fun calculateArea(base: Double, height: Double, isTriangle: Boolean): Double = 0.5 * base * height

// 9.
fun filterList(list: List<Int>, predicate: (Int) -> Boolean): List<Int> {
    val result = mutableListOf<Int>()
    for (i in 0 until list.size) {
        val item = list[i]
        if (predicate(item)) {
            result.add(item)
        }
    }
    return result
}

// 10. Замыкания
fun createCounter(start: Int): () -> Int {
    var count = start
    return {
        count++
        count
    }
}