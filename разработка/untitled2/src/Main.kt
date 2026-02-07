fun main() {
    while (true) {
        println("\n========================================")
        println("Выберите номер задания (1-12) или 0 для выхода:")
        println("1. Динамические диапазоны")
        println("2. Работа с массивом и условиями")
        println("3. Конвертер систем счисления")
        println("4. Поиск простых чисел")
        println("5. Шифр Цезаря")
        println("6. Статистика текста")
        println("7. Игра «Угадай число»")
        println("8. Работа с матрицей")
        println("9. Фибоначчи с условиями")
        println("10. Валидатор пароля")
        println("11. Конвертер времени")
        println("12. Мини-калькулятор выражений")
        print("Ваш выбор > ")

        val input = readlnOrNull() ?: "0"
        val choice = input.toIntOrNull()

        if (choice == 0) {
            println("Выход.")
            return
        }

        if (choice == 1) task1()
        else if (choice == 2) task2()
        else if (choice == 3) task3()
        else if (choice == 4) task4()
        else if (choice == 5) task5()
        else if (choice == 6) task6()
        else if (choice == 7) task7()
        else if (choice == 8) task8()
        else if (choice == 9) task9()
        else if (choice == 10) task10()
        else if (choice == 11) task11()
        else if (choice == 12) task12()
        else println("Неверный ввод, попробуйте снова.")
    }
}

fun task1() {
    println("\n--- Задание 1 ---")
    print("Введите начальное число: ")
    val startStr = readln()
    if (startStr == "") return
    val start = startStr.toInt()

    print("Введите конечное число: ")
    val endStr = readln()
    if (endStr == "") return
    val end = endStr.toInt()

    println("Числа в диапазоне [$start, $end] с шагом 2, которые делятся на 3:")
    for (i in start..end step 2) {
        if (i % 3 == 0) {
            print("$i ")
        }
    }
    println()
}

fun task2() {
    println("\n--- Задание 2 ---")
    val array = IntArray(10)
    for (i in 0 until 10) {
        array[i] = (1..100).random()
    }

    print("Сгенерированный массив: ")
    for (i in 0 until 10) {
        print("${array[i]}")
        if (i < 9) print(", ")
    }
    println()

    var max = array[0]
    var min = array[0]
    var sum = 0.0
    var evenCount = 0

    for (num in array) {
        if (num > max) max = num
        if (num < min) min = num
        sum += num
        if (num % 2 == 0) evenCount++
    }

    val average = sum / 10

    println("Максимальный элемент: $max")
    println("Минимальный элемент: $min")
    println("Среднее арифметическое: $average")
    println("Количество чётных чисел: $evenCount")
}

fun task3() {
    println("\n--- Задание 3 ---")
    print("Введите целое число: ")
    val numStr = readln()
    if (numStr == "") return
    val number = numStr.toInt()

    print("Выберите систему счисления (2, 8, 16): ")
    val baseStr = readln()
    if (baseStr == "") return
    val base = baseStr.toInt()

    if (base != 2 && base != 8 && base != 16) {
        println("Только 2, 8 или 16.")
        return
    }

    val shift = if (base == 2) 1 else if (base == 8) 3 else 4
    val mask = base - 1

    var tempNum = number
    var result = ""
    val hexChars = "0123456789ABCDEF"

    if (tempNum == 0) result = "0"

    while (tempNum > 0) {
        val digitVal = tempNum and mask
        result = "${hexChars[digitVal]}$result"
        tempNum = tempNum shr shift
    }

    println("Результат: $result")
}

fun task4() {
    println("\n--- Задание 4 ---")
    println("Простые числа от 2 до 100:")

    for (i in 2..100) {
        var isPrime = true
        for (j in 2 until i) {
            if (j * j > i) break

            if (i % j == 0) {
                isPrime = false
                break
            }
        }

        if (isPrime) {
            print("$i ")
        }
    }
    println()
}

fun task5() {
    println("\n--- Задание 5 ---")
    print("Введите строку: ")
    val input = readln()
    var output = ""

    for (char in input) {
        if (char >= 'a' && char <= 'z') {
            val originalPos = char - 'a'
            val newPos = (originalPos + 3) % 26
            output += ('a' + newPos)
        } else if (char >= 'A' && char <= 'Z') {
            val originalPos = char - 'A'
            val newPos = (originalPos + 3) % 26
            output += ('A' + newPos)
        } else if (char >= 'а' && char <= 'я') {
            val originalPos = char - 'а'
            val newPos = (originalPos + 3) % 32
            output += ('а' + newPos)
        } else if (char >= 'А' && char <= 'Я') {
            val originalPos = char - 'А'
            val newPos = (originalPos + 3) % 32
            output += ('А' + newPos)
        } else {
            output += char
        }
    }
    println("Зашифрованная строка: $output")
}

fun task6() {
    println("\n--- Задание 6 ---")
    println("Введите текст:")
    val text = readln()

    val charCount = text.length

    var wordCount = 0
    var isWord = false
    var maxLen = 0
    var currentWordLen = 0
    var currentWordObj = ""
    var maxWordObj = ""

    for (c in text) {
        if (c != ' ' && c != '.' && c != ',' && c != '!' && c != '?') {
            if (!isWord) {
                isWord = true
                wordCount++
            }
            currentWordLen++
            currentWordObj += c
        } else {
            isWord = false
            if (currentWordLen > maxLen) {
                maxLen = currentWordLen
                maxWordObj = currentWordObj
            }
            currentWordLen = 0
            currentWordObj = ""
        }
    }
    if (currentWordLen > maxLen) {
        maxWordObj = currentWordObj
    }

    var sentenceCount = 0
    for (c in text) {
        if (c == '.' || c == '!' || c == '?') {
            sentenceCount++
        }
    }

    println("Символов: $charCount")
    println("Слов: $wordCount")
    println("Предложений: $sentenceCount")
    println("Самое длинное слово: $maxWordObj")
}

fun task7() {
    println("\n--- Задание 7 ---")
    val target = (1..100).random()
    var attempts = 0
    var guess: Int = -1

    println("Число загадано (1-100).")

    do {
        print("Ваш вариант: ")
        val str = readln()
        if (str == "") continue

        guess = str.toInt()
        attempts++

        when {
            guess < target -> println("Больше")
            guess > target -> println("Меньше")
            guess == target -> println("Верно! Попыток: $attempts")
        }

    } while (guess != target)
}

fun task8() {
    println("\n--- Задание 8 ---")
    val matrix = Array(3) { IntArray(3) }

    println("Матрица:")
    for (i in 0 until 3) {
        for (j in 0 until 3) {
            matrix[i][j] = (1..9).random()
            print("${matrix[i][j]} ")
        }
        println()
    }

    for (i in 0 until 3) {
        var rowSum = 0
        for (j in 0 until 3) {
            rowSum += matrix[i][j]
        }
        println("Сумма строки ${i + 1}: $rowSum")
    }

    for (j in 0 until 3) {
        var colSum = 0
        for (i in 0 until 3) {
            colSum += matrix[i][j]
        }
        println("Сумма столбца ${j + 1}: $colSum")
    }

    var diagSum = 0
    for (i in 0 until 3) {
        diagSum += matrix[i][i]
    }
    println("Сумма главной диагонали: $diagSum")
}

fun task9() {
    println("\n--- Задание 9 ---")
    print("Количество чисел N: ")
    val nStr = readln()
    if (nStr == "") return
    val n = nStr.toInt()

    val fib = LongArray(n)
    if (n > 0) fib[0] = 0
    if (n > 1) fib[1] = 1

    for (i in 2 until n) {
        fib[i] = fib[i - 1] + fib[i - 2]
    }

    println("Числа Фибоначчи (четные ИЛИ ( >50 и <200 )):")

    for (num in fib) {
        val cond1 = (num % 2 == 0L)
        val cond2 = (num > 50 && num < 200)

        if (!(cond1 || cond2)) {
            continue
        }
        print("$num ")
    }
    println()
}

fun task10() {
    println("\n--- Задание 10 ---")
    print("Пароль: ")
    val password = readln()

    var isValid = true

    if (password.length < 8) {
        println("Ошибка: Минимум 8 символов.")
        isValid = false
    }

    var hasDigit = false
    var hasUpper = false
    var hasSpecial = false
    val specialChars = "!@#$%^&*"

    for (c in password) {
        if (c >= '0' && c <= '9') hasDigit = true
        if (c >= 'A' && c <= 'Z') hasUpper = true

        for (s in specialChars) {
            if (c == s) hasSpecial = true
        }
    }

    if (!hasDigit) {
        println("Ошибка: Нужна цифра.")
        isValid = false
    }
    if (!hasUpper) {
        println("Ошибка: Нужна заглавная буква.")
        isValid = false
    }
    if (!hasSpecial) {
        println("Ошибка: Нужен спецсимвол (!@#$%^&*).")
        isValid = false
    }

    if (isValid) {
        println("Пароль принят.")
    }
}

fun task11() {
    println("\n--- Задание 11 ---")
    var active = true

    while (active) {
        println("\n1. Сек -> Ч:М:С")
        println("2. Ч:М:С -> Сек")
        println("0. Выход")
        print("> ")

        val choice = readln()
        if (choice == "1") {
            print("Секунды: ")
            val sStr = readln()
            if (sStr != "") {
                val total = sStr.toLong()
                val h = total / 3600
                val m = (total % 3600) / 60
                val s = total % 60
                println("$h:$m:$s")
            }
        } else if (choice == "2") {
            print("Время (Ч:М:С): ")
            val tStr = readln()
            val parts = tStr.split(":")
            if (parts.size == 3) {
                val h = parts[0].toLong()
                val m = parts[1].toLong()
                val s = parts[2].toLong()
                println("Секунд: ${h * 3600 + m * 60 + s}")
            }
        } else if (choice == "0") {
            active = false
        }
    }
}

fun task12() {
    println("\n--- Задание 12 ---")
    println("Выражение (через пробелы, например 12 + 34 * 2):")
    val input = readln()

    val parts = input.split(" ").toMutableList()

    var i = 0
    while (i < parts.size) {
        val token = parts[i]
        if (token == "*" || token == "/") {
            val left = parts[i-1].toDouble()
            val right = parts[i+1].toDouble()
            var res = 0.0

            if (token == "*") res = left * right
            else {
                if (right == 0.0) {
                    println("Ошибка: деление на 0")
                    return
                }
                res = left / right
            }

            println("$left $token $right = $res")
            parts[i-1] = res.toString()
            parts.removeAt(i)
            parts.removeAt(i)
            i--
        }
        i++
    }

    i = 0
    while (i < parts.size) {
        val token = parts[i]
        if (token == "+" || token == "-") {
            val left = parts[i-1].toDouble()
            val right = parts[i+1].toDouble()
            var res = 0.0

            if (token == "+") res = left + right
            else res = left - right

            println("$left $token $right = $res")
            parts[i-1] = res.toString()
            parts.removeAt(i)
            parts.removeAt(i)
            i--
        }
        i++
    }

    if (parts.isNotEmpty()) {
        println("Итог: ${parts[0]}")
    }
}