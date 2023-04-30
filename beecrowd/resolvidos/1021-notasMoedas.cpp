#include <bits/stdc++.h>

using namespace std;

// exemplo de saída
// NOTAS:
// 5 nota(s) de R$ 100.00
// 1 nota(s) de R$ 50.00
// 1 nota(s) de R$ 20.00
// 0 nota(s) de R$ 10.00
// 1 nota(s) de R$ 5.00
// 0 nota(s) de R$ 2.00
// MOEDAS:
// 1 moeda(s) de R$ 1.00
// 1 moeda(s) de R$ 0.50
// 0 moeda(s) de R$ 0.25
// 2 moeda(s) de R$ 0.10
// 0 moeda(s) de R$ 0.05
// 3 moeda(s) de R$ 0.01

int qtd(int valor, int real){
    return valor/real;
}

double novoValor(int qtdNotas, double real, double valorAntigo){
    return valorAntigo-qtdNotas*real;
}

int main(void){
    double valor;
    int centavos;
    const int QTD_NOTAS = 6;
    double real[QTD_NOTAS] = {100, 50, 20, 10, 5, 2};
    const int QTD_MOEDAS = 6;
    double moedas[QTD_MOEDAS] = {1, 0.5, 0.25, 0.1, 0.05, 0.01};

    cin >> valor;
    centavos = valor*100;

    cout << "NOTAS:" << endl;
    for(int x=0; x<QTD_NOTAS; x++){
        int notas = qtd(centavos, real[x]*100);
        printf("%d nota(s) de R$ %.2f\n", notas, real[x]);
        centavos = novoValor(notas, real[x]*100, centavos);
    }

    cout << "MOEDAS:" << endl;
    for(int x=0; x<QTD_MOEDAS; x++){
        int moeds = qtd(centavos, moedas[x]*100);
        printf("%d moeda(s) de R$ %.2f\n", moeds, moedas[x]);
        centavos = novoValor(moeds, moedas[x]*100, centavos);
    }

    return 0;
}