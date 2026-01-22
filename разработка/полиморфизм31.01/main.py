class Human:
    def __init__(self, name, start_money):
        self.name = name
        self.__money = start_money  # количество денег
        self.__house = None         

    
    def __make_deal(self, house, price):
        self.__money -= price
        self.__house = house

    
    def earn_money(self, amount):
        self.__money += amount
        print(f"Пополнение счета на {amount}. Баланс: {self.__money}")

    
    def buy_house(self, house, discount):
        price = house.final_price(discount)
        
        if self.__money >= price:
            self.__make_deal(house, price)
            print(f"Сделка совершена! {self.name} купил дом за {price}")
        else:
            print(f"Внимание: недостаточно средств! Цена со скидкой: {price}")

class House:
    def __init__(self, area, price):
        self._area = area
        self._price = price

    # 3. Расчет финальной стоимости
    def final_price(self, discount):
        return self._price - discount

if __name__ == "__main__":
    # Создание объекта дома
    village_house = House(120, 65000)

    # Создание объекта человека
    citizen = Human("Александр", 15000)

    # Попытка покупки 
    citizen.buy_house(village_house, 5000)

    # Заработок денег
    citizen.earn_money(60000)

    # Успешная покупка
    citizen.buy_house(village_house, 5000)