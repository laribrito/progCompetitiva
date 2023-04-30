while True:
    h1, m1, h2, m2 = [int(i) for i in input().split()]
    if h1==0 and m1==0 and h2==0 and m2==0:
        break

    if m1==m2 and m2==h1 and h1==h2:
        print(1440)
    elif m1==m2:
        if h1>h2:
            hAux=24-h1+h2
        else:
            hAux=h2-h1
        print(hAux*60)
    elif h1==h2 and m2>m1:
        print(m2-m1)
    else:
        mAux=60-m1
        h1+=1
        if h1==24:
            h1=0
        if h1>h2:
            hAux=24-h1+h2
        else:
            hAux=h2-h1
        mAux+=m2
        print(hAux*60+mAux)
        