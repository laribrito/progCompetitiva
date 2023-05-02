#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    int contador = 1, qtdMoradores, consumoTotal, consumoPorPessoa;
    while(cin >> n && n!=0){
        // map para fazer o par quantidadeConsumida:quantidadePessoas;
        // set para organizar as quantidadesConsumidas em ordem crescente
        set<int> qtdConsumidasAproximadas;
        map<int, int> dados;
        int qtdConsumidasReal=0, qtdTotalPessoas=0;

        while(n--){
            cin >> qtdMoradores >> consumoTotal;
            consumoPorPessoa = consumoTotal/qtdMoradores;
            if(qtdConsumidasAproximadas.find(consumoPorPessoa) == qtdConsumidasAproximadas.end()) {
                qtdConsumidasAproximadas.insert(consumoPorPessoa);
                dados[consumoPorPessoa] = qtdMoradores;
            } else dados[consumoPorPessoa] +=qtdMoradores;
            qtdConsumidasReal += consumoTotal;
            qtdTotalPessoas += qtdMoradores;

        }

        cout << "Cidade# " << contador++ << ":" << endl;
        for(auto x=begin(qtdConsumidasAproximadas); x!=end(qtdConsumidasAproximadas); x++){
            cout << dados[*x] << "-" << *x;
            auto y = x;
            if(++y != end(qtdConsumidasAproximadas)) cout << " ";
        }
        float aux = (float) qtdConsumidasReal/qtdTotalPessoas;
        int valorMedio = aux * 100;
        printf("\nConsumo medio: %.2f m3.\n\n", (float) valorMedio/100);
    }
    return 0;
}