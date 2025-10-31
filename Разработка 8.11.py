#1.1
def nod(a,b):
    
    print("a = ",a,"b = ",b,"a%b = ",a%b)
    if (a%b==0):
        return print(f"Наименьший общий делитель {b}")
    else:
        return nod(b, a%b)
nod(48,18)
#1.2
def fibonacci(a,b):
    print(f"{a}+{b} = {a+b}     ")
    if (13<=a+b):
        return a+b
    else:
        c = a+b
        return fibonacci(b,c) 
fibonacci(0,1)
#1.3
def natural(a):
    if (a%10!=0):
        print(a%10)
        return natural(a//10)
natural(123)
#2.1
def factorial (a):
    if (a==0 or a==1):
        return 1
    return a * factorial(a-2)
print(f"Двойной факториал  = {factorial(8)}")

print(f"0 = {format(10,'b')}")
#2.2
def bin (number):
    number_bin = int(format(number,'b'))
    def couter_bin_1(number_bin,couter = 0 ):
        
        if (number_bin%10==1):
            couter+=1
        if (number_bin//10!=0):
            return couter_bin_1(number_bin//10,couter)
        else:
            print(couter)
    couter_bin_1(number_bin)
bin(10)
#2.3
def number_23 (a,b,cout=0):
    if (cout!=b):
        a+=1
        cout+=1
        return number_23(a,b,cout)
    else:
        return print(a)
number_23(3,2)
#2.4
def number_24 (a,b,cout=0,sum=0):
    if (cout!=b):
        sum+=a
        cout+=1
        return number_24(a,b,cout,sum)
    else:
        return print(sum)
number_24(2,3)
#2.5
def palindrome(s,i,j):
    if i>=j:
        return print("Палендром")
    if s[i]!=s[j]:
        return print("Не палендром")
    return palindrome(s,i+1,j-1)

palindrome("казак",1,3)
#2.6
def counter_number(num,cout=0):
    if (num!=0):
        num = num//10
        cout+=1
        return counter_number(num,cout)
    else:
        print(f"Количество цифр в числе = {cout}")
counter_number(123)
