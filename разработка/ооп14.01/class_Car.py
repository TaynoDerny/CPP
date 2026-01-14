
class Car:
    def __init__(self, brand, model, year, color, mileage):
        self.brand = brand        
        self.model = model        
        self.year = year          
        self.color = color      
        self.mileage = mileage   
    
    def drive(self, distance):
        self.mileage += distance
        print(f"Автомобиль проехал {distance} км. Общий пробег: {self.mileage} км")
    
    def repaint(self, new_color):
        print(f"Цвет автомобиля изменен с {self.color} на {new_color}")
        self.color = new_color
    
    def display_info(self):
        print(f"Автомобиль: {self.brand} {self.model}")
        print(f"Год выпуска: {self.year}")
        print(f"Цвет: {self.color}")
        print(f"Пробег: {self.mileage} км")
        print("-" * 40)


car1 = Car(
    brand="Toyota",
    model="Camry",
    year=2020,
    color="черный",
    mileage=35000
)

car2 = Car(
    brand="BMW",
    model="X5",
    year=2022,
    color="белый",
    mileage=15000
)


print("Информация об автомобилях:")
car1.display_info()
car2.display_info()


print("\nТестирование методов:")
car1.drive(500)
car1.repaint("синий")
car1.display_info()


car2.drive(200)
car2.display_info()