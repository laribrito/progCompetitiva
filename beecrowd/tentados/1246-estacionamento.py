while True:
    try:
        compTotal, eventos =  [int(b) for b in input().split()]
        estacionamento = []
        valor = 0
        while eventos>0:
            entrada = input().split()
            placa = int(entrada[1])
            if entrada[0]=='S':
                eventos-=1
                for i in range(estacionamento.count(placa)):
                    lugar =estacionamento.index(placa)
                    estacionamento[lugar] = 0
                continue
            eventos-=1
            tamanho=int(entrada[2])
            carro = [placa for i in range(tamanho)]

            if len(estacionamento)==0:
                estacionamento.extend(carro)
                valor+=10
            else:
                for i in range(compTotal):
                    if i+tamanho<=compTotal:
                        if max(estacionamento[i:i+tamanho])==0:
                            valor+=10
                            estacionamento[i:i+tamanho]=carro
                            continue
                estacionamento.extend(carro)
                valor+=10
        print(valor)
    except EOFError:
        break