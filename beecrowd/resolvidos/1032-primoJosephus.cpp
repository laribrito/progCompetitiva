#include <bits/stdc++.h>
using namespace std;

bool ehPrimo(int n){
    int div=0;
    for(int aux=2 ; aux<=sqrt(n) ; aux++){
        if(n%aux==0) div++;
        if(div==1) return false;
    }
    return true;
}

int main(void){
    int qtdPessoas, numCalculados, numero, posAnterior, m, posAtual, ind;
    vector<int> primos, pessoas;
    while(cin >> qtdPessoas && qtdPessoas!=0){
        numCalculados=0;
        numero = 2;
        // calcula os primos necessários
        for(ind=1; numCalculados<qtdPessoas; ind++){
            if(ehPrimo(numero)){
                primos.push_back(numero);
                numCalculados++;
            }
            numero++;
            if (ind<=qtdPessoas) pessoas.push_back(ind);
        }

        posAnterior = 0;
        for(int x=0; pessoas.size()>1; x++){
            m = primos[x]-1;
            posAtual = (posAnterior+m)%pessoas.size();
            pessoas.erase(pessoas.begin()+posAtual);
            posAnterior = posAtual;
        }
        cout << pessoas.front() << endl;
        pessoas.clear();
        primos.clear();
    }

    return 0;
}
