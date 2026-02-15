from calculator_with_history import CalculatorWithHistory
from calculator_service import CalculatorService
from history_service import HistoryService


# Тест 1: Сложение и сохранение в истории
def test_addition():
    calculator = CalculatorWithHistory()

    result = calculator.perform_addition(5, 3)
    assert result == 8, "Результат сложения должен быть 8"

    history = calculator.get_operation_history()
    assert len(history) == 1, "В истории должна быть одна запись"
    assert history[0] == "5 + 3 -> 8", "Неверная запись в истории"

    print("Тест 1 пройден: сложение работает корректно")


# Тест 2: Вычитание и сохранение в истории
def test_subtraction():
    calculator = CalculatorWithHistory()

    result = calculator.perform_subtraction(10, 4)
    assert result == 6, "Результат вычитания должен быть 6"

    history = calculator.get_operation_history()
    assert len(history) == 1, "В истории должна быть одна запись"
    assert history[0] == "10 - 4 -> 6", "Неверная запись в истории"

    print("Тест 2 пройден: вычитание работает корректно")


# Тест 3: Несколько операций в истории
def test_multiple_operations():
    calculator = CalculatorWithHistory()

    calculator.perform_addition(1, 1)
    calculator.perform_subtraction(5, 2)

    history = calculator.get_operation_history()
    expected = ["1 + 1 -> 2", "5 - 2 -> 3"]

    assert history == expected, f"Ожидалось {expected}, получено {history}"
    print("Тест 3 пройден: история сохраняет несколько операций")


# Дополнительное задание: Сломанный сервис истории
class BrokenHistoryService(HistoryService):
    def save_record(self, operation: str, result: int) -> None:
        raise Exception("Database error")


class CalculatorWithBrokenHistory(CalculatorWithHistory):
    def __init__(self):
        self.calculator = CalculatorService()
        self.history = BrokenHistoryService()


# Тест 4: Поведение со сломанным сервисом истории
def test_broken_history():
    calculator = CalculatorWithBrokenHistory()

    try:
        calculator.perform_addition(5, 3)
        assert False, "Должно было возникнуть исключение"
    except Exception as e:
        assert str(e) == "Database error", "Неверное сообщение об ошибке"

    print("Тест 4 пройден: сломанный сервис вызывает исключение")


# Запуск всех тестов
if __name__ == "__main__":
    print("Запуск интеграционных тестов...")
    print("-" * 30)

    test_addition()
    test_subtraction()
    test_multiple_operations()
    test_broken_history()

    print("-" * 30)
    print("Все тесты пройдены успешно!")