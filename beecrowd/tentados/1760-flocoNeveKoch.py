import math as m
while True:
    try:
        ladoT = int(input())
        formula = (pow(ladoT, 4)*3)/4
        print(f"{m.sqrt(formula):.2f}")
    except EOFError:
        break