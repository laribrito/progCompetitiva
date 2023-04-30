#include <bits/stdc++.h>

using namespace std;

// exemplo de saída
// 576
// 5 nota(s) de R$ 100,00
// 1 nota(s) de R$ 50,00
// 1 nota(s) de R$ 20,00
// 0 nota(s) de R$ 10,00
// 1 nota(s) de R$ 5,00
// 0 nota(s) de R$ 2,00
// 1 nota(s) de R$ 1,00

int qtdNotas(long int valor, int real){
    return valor/real;
}

long int novoValor(int qtdNotas, int real, int valorAntigo){
    return valorAntigo-qtdNotas*real;
}

int main(void){
    long int valor;
    int real[7] = {100, 50, 20, 10, 5, 2, 1};

    cin >> valor;

    cout << valor << endl;
    for(int x=0; x<7; x++){
        int notas = qtdNotas(valor, real[x]);
        cout << notas << " nota(s) de R$ " << real[x] << ",00" << endl;
        valor = novoValor(notas, real[x], valor);
    }

    return 0;
}