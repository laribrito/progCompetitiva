// Larissa, Davi e Estêvão
#include <bits/stdc++.h>
 
using namespace std;

struct Rodada{
    long long alberto;
    long long wanderley;
};

long long escolheMelhorOpcao(vector<Rodada> rodadas, vector<int> mesa){
    //par a par
    bool ehAlberto = true;
    for(int x=0; x<rodadas.size()-1; x++){
        rodadas[x].alberto = max(mesa[x], mesa[x+1]);
    }

    //aumenta o intervalo de teste
    for(int tam=4; tam<=mesa.size(); tam+=2){
        ehAlberto = !ehAlberto;
        for(int cartaInicio=0, cartaFim=tam-1; cartaFim<mesa.size(); cartaInicio++, cartaFim++){
            if(!ehAlberto) {
                rodadas[cartaInicio].wanderley = max(
                        mesa[cartaInicio] + min(rodadas[cartaInicio + 1].alberto, rodadas[cartaInicio + 2].alberto),
                        mesa[cartaFim] + min(rodadas[cartaInicio].alberto, rodadas[cartaInicio + 1].alberto)
                );
            }else{
                rodadas[cartaInicio].alberto = max(
                    mesa[cartaInicio] + min(rodadas[cartaInicio + 1].wanderley, rodadas[cartaInicio + 2].wanderley), 
                    mesa[cartaFim] + min(rodadas[cartaInicio].wanderley, rodadas[cartaInicio + 1].wanderley)
                );
            }
        }
    }

    if(ehAlberto) return rodadas[0].alberto;
    return rodadas[0].wanderley;
}
 
int main() {
    int n;
    
    while(cin >> n){
        long long cartao;
        vector<Rodada> rodadas;
        vector<int> mesa;

        for(int x=0; x<n; x++){
            cin >> cartao;
            mesa.push_back(cartao);
        }

        for(int x=0; x<n; x++){
            rodadas.push_back(Rodada{0, 0});
        }

        cout << escolheMelhorOpcao(rodadas, mesa) << endl;
    }
    return 0;
}