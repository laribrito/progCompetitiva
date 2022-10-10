while True:
    m, n = [int(i) for i in input().split()]
    if m==0:
        break
    A={int(i) for i in input().split()}
    B={int(i) for i in input().split()}
    difA=len(A-B)
    difB=len(B-A)
    print(min(difA, difB))
