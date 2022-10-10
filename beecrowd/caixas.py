while True:
    def volume(dimensoes):
        return dimensoes[0]*dimensoes[1]*dimensoes[2]

    def caixasValidas(estoque, caixa):
        listaAux=[x for x in range(3) if estoque[x]-caixa[x]>=0]
        if len(listaAux)==3:
            return True
        return False

    # recebe primeira linha
    quantPedidas, quantEstoque = [int(i) for i in input().split()]
    if quantPedidas == 0:
        break
    # recebe as dimensões 
    requerido = [int(i) for i in input().split()]
    requerido.sort()
    estoque=[]
    estoqueQuants=[]

    # recebe o estoque (estilo lee-vai)
    for i in range(quantEstoque):
        disponivel = [int(i) for i in input().split()]
        disponivel.sort()
        quant = 1
        if caixasValidas(disponivel, requerido):
            try:
                # verifica se já existe no estoque
                estoqueQuants[estoque.index(disponivel)]+=1
            except ValueError:
                # adiciona como novo item no estoque
                estoque.append(disponivel)
                estoqueQuants.append(quant)
        
    # verifica se há caixas com a quantidade pedida
    requeridoVol = volume(requerido)
    menor = -1
    for index,j in enumerate(estoqueQuants):
        if j < quantPedidas:
            estoqueQuants[index] = -1
        else:
            menor = estoque[index] = volume(estoque[index])-requeridoVol

    if not len(estoque) or max(estoqueQuants)==-1:
        print("impossible")
    else: 
        # buscar a caixa com menor diferença 
        caixasValidas=[]
        for index, caixa in enumerate(estoque):
            if estoqueQuants[index]!=-1 and caixa<menor:
                menor=caixa
            
        print(menor)