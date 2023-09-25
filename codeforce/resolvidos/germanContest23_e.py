palavra = input().lower()
print(palavra)

for i in range(len(palavra)-1):
    if palavra[i] == palavra[i+1] == 's':
        outra = palavra[:i]+ 'B' + palavra[i + 2:]
        print(outra)