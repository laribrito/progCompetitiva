#include <bits/stdc++.h>
using namespace std;

int main(){
    int qtd, numPessoas, m, posAnterior, posAtual;
    vector<int> vetor;
    cin >> qtd;
    for(int ind=1; ind<=qtd; ind++){
        cin >> numPessoas >> m;
        for(int x=1; x<=numPessoas;x++){
            vetor.push_back(x);
        }

        posAnterior = 0;
        m--;
        while(vetor.size()>1){
            posAtual = (posAnterior+m)%vetor.size();
            vetor.erase(vetor.begin()+posAtual);
            posAnterior = posAtual;
        }
        printf("Case %d: %d\n", ind, vetor.front());
        vetor.clear();
    }
    return 0;
}