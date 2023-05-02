def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        L = arr[:mid]
        R = arr[mid:]

        merge_sort(L)
        merge_sort(R)

        i = j = k = 0

        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1

        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1


contador = 1
while True:
    numMarmore, numBuscas = [int(x) for x in input().split()]
    if numMarmore == 0:
        break

    vetor = []
    for i in range(numMarmore):
        vetor.append(int(input()))
    merge_sort(vetor)

    print(f"CASE# {contador}:")
    contador+=1
    while numBuscas:
        busca = int(input())
        for i, x in enumerate(vetor):
            if i == busca:
                print(f"{busca} found at {x+1}")
                break
        else:
            print(f"{busca} not found")
        numBuscas-=1