#include <bits/stdc++.h>
 
using namespace std;

#define limiteCanal 100000

int buscaCanal(bool* canais, int o, int d) {
    //valor e altura
    queue<pair<int, int>> fila;

    fila.push(make_pair(o, 0));

    while(!fila.empty()){
        int atual = fila.front().first;
        int altura = fila.front().second;
        fila.pop();

        if(atual==d) return altura;

        altura++;
        if(atual>1 && canais[atual-2]){
            canais[atual-2] = false;
            fila.push(make_pair(atual-1, altura));
        }

        if(atual+1<=limiteCanal && canais[atual]){
            canais[atual] = false;
            fila.push(make_pair(atual+1, altura));
        }

        if(atual*2<=limiteCanal && canais[atual*2-1]){
            canais[atual*2-1] = false;
            fila.push(make_pair(atual*2, altura));
        }

        if(atual*3<=limiteCanal && canais[atual*3-1]){
            canais[atual*3-1] = false;
            fila.push(make_pair(atual*3, altura));
        }

        if(atual%2==0 && atual/2>=1 && canais[atual/2-1]){
            canais[atual/2-1] = false;
            fila.push(make_pair(atual/2, altura));
        }
    }
    return -1;
}

int main() {
    int o, d, k, prod;

    while(cin >> o >> d >> k && o!=0){
        bool canais[limiteCanal];
        fill(canais, canais + limiteCanal, true);  
        while(k--){
            cin >> prod;
            canais[prod-1] = false;
        }
        cout << buscaCanal(canais, o, d) << endl;
    }
    return 0;
}