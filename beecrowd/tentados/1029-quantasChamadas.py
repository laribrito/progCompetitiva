def fibonacci(a, lista):
    lista[0] +=1
    if (a == 0):
        return 0
    elif(a==1):
        return 1
    else:
        return fibonacci(a-1, lista)+fibonacci(a-2, lista)

def main():
    qtd = int(input())
    for i in range(qtd):
        chamadas=[0];
        num = int(input())
        fib = fibonacci(num, chamadas);
        chamadas[0]-=1
        print(f"fib({num}) = {chamadas[0]} calls = {fib}") 
    
main()