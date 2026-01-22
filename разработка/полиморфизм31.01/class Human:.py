class Human:
    # Базовая инициализация (чтобы класс работал)
    def __init__(self, name, start_money):
        self.name = name
        self.__money = start_money  # Приватное свойство (деньги)
        self.__house = None         # Изначально дома нет

    # --- Задание 6 ---
    # Приватный метод make_deal (начинается с __).
    # Он не проверяет деньги, а просто проводит операцию: списывает средства и присваивает дом.
    def __make_deal(self, house, price):
        self.__money -= price
        self.__house = house

    # --- Задание 7 ---
    # Метод earn_money увеличивает свойство money.
    def earn_money(self, amount):
        self.__money += amount
        print(f"{self.name} заработал {amount}. Теперь на счету: {self.__money}")

    # --- Задание 8 ---
    # Метод buy_house.
    # 1. Принимает объект дома и скидку.
    # 2. Вычисляет цену (вызывая метод дома final_price).
    # 3. Проверяет баланс и либо вызывает __make_deal, либо пишет ошибку.
    def buy_house(self, house, discount):
        # Важно: тут мы предполагаем, что у объекта house есть метод final_price
        price = house.final_price(discount)
        
        if self.__money >= price:
            self.__make_deal(house, price)
            print(f"{self.name} успешно купил дом за {price}!")
        else:
            print(f"{self.name}, не хватает денег! (Нужно {price}, а есть {self.__money})")