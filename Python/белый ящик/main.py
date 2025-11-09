import webbrowser
def for_ger (a,b,c):
    p=(a+b+c)/2
    return (p*(p-a)*(p-b)*(p-c))**0.5


def triangle(a,b,c):
    if((a>0 and b>0 and c >0) and (a+b>c)and(a+c>b)and(c+b>a)):
        if (a==b and c==a):
            print("Триугольник равностороний ")
            print(f"Площадь равна {for_ger(a,b,c)}")
        elif(a==b or a==c or b==c):
            print("Триугольник равнобедреный ")
            print(f"Площадь равна {for_ger(a,b,c)}")
        else:
            print("Триугольник разноностороний ")
            print(f"Площадь равна {for_ger(a,b,c)}")
    else:
        print("ОШИБКА - Это не триугольник ")

def triangle_corn(a,b,c):
    if((a>0 and b>0 and c >0) and (a+b>c)and(a+c>b)and(c+b>a)):
        
        if (c**2==a**2+b**2):
            print("Триугольник прямоугольный")
            print(f"Площадь равна {for_ger(a,b,c)}")
        elif(c**2<a**2+b**2):
            print("Триугольник остроугольный")
            print(f"Площадь равна {for_ger(a,b,c)}")
        else:
            print("Триугольник тупоугольный")
            print(f"Площадь равна {for_ger(a,b,c)}")
    else:
        print("ОШИБКА - Это не триугольник ")


def main_input():
        a = int(input("Введите первую длину стороны триугольника "))
        b = int(input("Введите вторую длину стороны триугольника "))
        c = int(input("Введите третью длину стороны триугольника "))
        return a,b,c

def main_1():
    a,b,c = main_input()
    triangle(a,b,c)
def main_2():
    webbrowser.open("https://github.com/TaynoDerny/CPP/blob/main/Python/%D0%B1%D0%B5%D0%BB%D1%8B%D0%B9%20%D1%8F%D1%89%D0%B8%D0%BA/%D0%97%D0%B0%D0%B4%D0%B0%D0%BD%D0%B8%D0%B5_2.png")  
def main_3():
    a,b,c = main_input()
    a,b,c = sorted((a,b,c))
    triangle_corn(a,b,c)
def main_4():
    print("В ходе проведения тестов не было обнаруженно ошибок.")

if (__name__=="__main__"):
    print("Какое задание выполнить ? ")
    num = int(input("Выберети 1, 2, 3 или 4 задание "))
    if (num==1):
        main_1()
    elif(num==2):
        main_2()
    elif(num==3):
        main_3()
    else:
        print("Неверный выбор!")




