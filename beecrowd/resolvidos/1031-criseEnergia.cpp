#include <bits/stdc++.h>
using namespace std;

int main(){
    int qtd, m, posAnterior, posAtual;
    vector<int> vetor, clone;
    while(cin >> qtd && qtd!=0){
        for(int x=2; x<=qtd;x++){
            vetor.push_back(x);
        }

        m=0;
        do{
            clone = vetor;
            posAnterior = 0;
            while(clone.size()>1){
                posAtual = (posAnterior+m)%clone.size();
                clone.erase(clone.begin()+posAtual);
                posAnterior = posAtual;
            }
            m++;
        }while(clone.front()!=13);
        cout << m << endl;
        vetor.clear();
    }
    return 0;
}