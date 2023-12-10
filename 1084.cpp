#include <bits/stdc++.h>

using namespace std;

int maior(string teste, int inicio, int fim){
    char maior = teste[inicio];
    int index = inicio;

    if(teste[inicio]=='9'){
        cout << '9';
        return 0;
    } else {
        for(int x=inicio+1; x<fim+1;x++){
            if(teste[x]=='9'){
                cout << '9';
                return x;
            }

            if(teste[x]>maior){
                maior = teste[x];
                index = x;
            } 
        }

        cout << maior;
        return index;
    }

}

typedef long long int lli;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    lli N, D;

    while(cin >> N && cin >> D && (N != 0 && D != 0)){
        string quadro;
        cin >> quadro;

        int Delete = D, Objetivo = N - D, indFim = D, indInicio = 0, correto, printados = 0;

        while(Delete > 0 && printados < Objetivo){
            correto = maior(quadro, indInicio, indFim);
            Delete -= correto - indInicio;
            indInicio = correto + 1;
            indFim = indInicio + Delete;
            printados++;
        }

        while(correto<quadro.size() && printados < Objetivo){
            cout << quadro[++correto];
        }

        cout << endl;
    }
    return 0;
}