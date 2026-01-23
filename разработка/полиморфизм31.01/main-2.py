class House:
    def __init__(self, area, price):
        self._area = area
        self._price = price

    def final_price(self, discount):
        # Возвращение цены с вычетом скидки
        return self._price - discount


# Наследование (Класс SmallHouse) 
class SmallHouse(House): 
    def __init__(self, price):
        super().__init__(40, price)



class Human:
    default_name = None
    default_money = 0

    def __init__(self, name=default_name, money=default_money):
        self.name = name
        self.__money = money  # Приватное свойство
        self.__house = None   

    def default_info(): # Справочный метод класса
        print(f"Дефолтное имя: {Human.default_name}, Деньги: {Human.default_money}")

    def info(self): # Справочный метод объекта
        print(f"Имя: {self.name}, Баланс: {self.__money}, Дом: {self.__house}")

    def __make_deal(self, house, price): # Приватный метод сделки
        self.__money -= price
        self.__house = house

    def earn_money(self, amount): # Метод заработка
        self.__money += amount
        print(f"--- {self.name} заработал {amount} ---")

    def buy_house(self, house, discount): # Метод покупки
        price = house.final_price(discount)
        if self.__money >= price:
            self.__make_deal(house, price)
            print(f"Дом куплен за {price}!")
        else:
            print("ПРЕДУПРЕЖДЕНИЕ: Недостаточно денег!") 



if __name__ == "__main__":
    Human.default_info()

    #  Создание объект человека
    mr_smith = Human("Андрей", 10000)

    #  Информация об объекте
    mr_smith.info()

    # создания дома ценной 150000
    small_flat = SmallHouse(15000)

    # Попытка покупки
    mr_smith.buy_house(small_flat, 2000)

    #  Добавление денег (заработок)
    mr_smith.earn_money(5000)

    #  покупка
    mr_smith.buy_house(small_flat, 2000)

    #  Информация об объекте
    mr_smith.info()