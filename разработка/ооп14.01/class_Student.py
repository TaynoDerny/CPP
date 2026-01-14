
class Student:
    def __init__(self,name,age,course,gpa,student_id):
        self.name = name
        self.age = age 
        self.course = course
        self.gpa = gpa
        self.student_id = student_id

    def increase_course(self):
        if(self.course<5):
            self.course = self.course+1
            print(f"Курс студента увеличен на один: {self.course}")
    
    def update_gpa(self,num):
        if (num>=0 and num<=5):
            self.gpa = num
        else:
            print('ОШИБКА -введите число от 0 до 5')

    def display_info(self):
        print("=" * 40)
        print("ИНФОРМАЦИЯ О СТУДЕНТЕ:")
        print("=" * 40)
        print(f"ФИО: {self.name}")
        print(f"Возраст: {self.age} лет")
        print(f"Курс: {self.course}")
        print(f"Средний балл (GPA): {self.gpa}")
        print(f"Номер студенческого: {self.student_id}")
        print("=" * 40)
    


student1 = Student(
    name="Иван Петров",
    age=19,
    course=1,
    gpa=4.2,
    student_id="ST001"
)

student2 = Student(
    name="Мария Сидорова",
    age=20,
    course=2,
    gpa=4.7,
    student_id="ST002"
)

#         ТЕстирование
print("1 - Тест:\n")
student1.increase_course() 

print("2 - Тест:\n")
student1.display_info()
student1.update_gpa(4.5)
print("\n")
student1.display_info()

print("3 - Тест:\n")
student2.display_info()
student2.update_gpa(4.5)
print("\n")
student2.display_info()

print("4 - Тест:\n")
student2.display_info()
student2.update_gpa(6.0)
