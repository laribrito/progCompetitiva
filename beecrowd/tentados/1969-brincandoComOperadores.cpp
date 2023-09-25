#include <bits/stdc++.h>
using namespace std;

int calcula(int a, int b, bool ehSoma){
    if(ehSoma){
        return a+b;
    }
    return a-b;
}

bool ehImpar(int num){
    return (abs(num)%2==1);
}

void exibeResultado(int res, bool rusaComecou){
    cout << res;
    if(ehImpar(res) && rusaComecou){
        cout << " Rusa\n";
    } else if(ehImpar(res) && !rusaComecou){
        cout << " Sanches\n";
    } else if(!ehImpar(res) && rusaComecou){
        cout << " Sanches\n";
    } else {
        cout << " Rusa\n";
    }
}

int main(void){
    int qtdCasos, qtdNum, numSubs, num, qtd, qtdNumCopy, l, aux, novoQtd, op1, op2, res, i, k, novoK, w, novoW, posSub, novoValor, pai, filhoE, filhoD;
    vector<int> heap;
    bool opSoma, Rusa = true, encontrou;
    int it, itAux;

    cin >> qtdCasos;
    while(qtdCasos--){
        opSoma = true;
        cin >> qtdNum >> numSubs;
        qtdNumCopy = qtdNum;
        l = qtdNum;
        do{
            for(int y=0; y<l; y++) heap.push_back(0);

            if(ehImpar(l)){
                l = l/2 +1;
            } else {
                l = l/2;
            }
        }while(l!=1);
        heap.push_back(0);

        it = heap.size();
        for(int x=qtdNum, j=1; x>0; x--, j+=2){
            cin >> num;
            heap[--it-(qtdNum-j)] = num;
        }       

        aux = (int) qtdNum/2;
        itAux = heap.size();
        do{
            if(ehImpar(qtdNum)){
                it--; itAux--;
                heap[it] = heap[itAux];
            }
            for(int x=0; x<aux; x++) {
                itAux--;
                op2 = heap[itAux];
                itAux--;
                op1 = heap[itAux];
                res = calcula(op1, op2, opSoma);
                it--;
                heap[it] = res;
            }

            if(ehImpar(qtdNum)){
                qtdNum = aux + 1;
            } else {
                qtdNum = aux;
            }

            aux = (int) qtdNum/2;
            opSoma = !opSoma;
        } while(it>0);


        // imprimir o resultado
        exibeResultado(heap[0], Rusa);

        while(numSubs--){
            cin >> posSub >> novoValor;
            opSoma = true;
            qtd = qtdNumCopy;
            k=heap.size();
            novoK = k-qtd;
            w = novoK+1;
            i = qtd - posSub;
            i = heap.size() - i;
            
            heap[i-1] = novoValor;

            do{
                if(ehImpar(qtd)){
                    novoQtd = (int) qtd/2 + 1;
                } else {
                    novoQtd = (int) qtd/2;
                }
                novoW = w -novoQtd; 

                // acha o pai e seus filhos
                encontrou = false;
                for(int auxPai=novoW, auxFilhos=w; !encontrou; auxPai++, auxFilhos+=2){
                    if(auxFilhos==i||auxFilhos+1==i){
                        pai = auxPai;
                        encontrou = true;
                        filhoE = auxFilhos;
                        filhoD = filhoE + 1;
                    }
                }

                if(ehImpar(qtd) && i==k){
                    // cout << "só repete\n";                    
                    heap[pai-1] = heap[i-1];
                } else {

                    //calcular novamente
                    heap[pai-1] = calcula(heap[filhoE-1], heap[filhoD-1], opSoma);
                }

                k = novoK;
                w = novoW;
                novoK = k - novoQtd;
                i = pai;
                opSoma = !opSoma;
                qtd = novoQtd;
            }while(i!=1);
            exibeResultado(heap[0], Rusa);
        }

        heap.clear();
        Rusa = !Rusa;
    }
    
    return 0;
}