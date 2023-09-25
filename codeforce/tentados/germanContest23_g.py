num = int(input())

if num<10:
    print(num+1)
else:
    numList = list(str(num))
    qtd = 10
    penultimo = num%10
    num = num //10
    while num>=10:
        penultimo = num%10
        num = num //10
        qtd+=10
    qtd+=num
    
    if penultimo<num:
        qtd-=1

    print(qtd)