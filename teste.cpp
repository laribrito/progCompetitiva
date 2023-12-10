//Larissa, Estêvão e Davi
#include <bits/stdc++.h>
 
using namespace std;

struct Rodada{
    long long alberto;
    long long wanderley;
};

long long retiraDaMesa(deque<long long>& mesa, bool oMaior){
    long long a = mesa.front(), b=mesa.back();
    if(a>b){
        if(oMaior){
            mesa.pop_front();
            return a;
        } else {
            mesa.pop_back();
            return b;
        }
    } else {
        if(oMaior){
            mesa.pop_back();
            return b;
        } else {
            mesa.pop_front();
            return a;
        }
    }

}

long long diffEscolha(long long minhaPontAtual, long long outroPontAtual, deque<long long> mesa, bool pegaMaior){
    long long minhaPont, outroPont;

    if(pegaMaior){
        //se eu escolher o atual maior
        minhaPont = minhaPontAtual + retiraDaMesa(mesa, true);
    } else {
        //se eu escolher o atual menor
        minhaPont = minhaPontAtual + retiraDaMesa(mesa, false);
    }

    //meu oponente pode escolher o proximo maior 
    outroPont = outroPontAtual + retiraDaMesa(mesa, true);

    if(mesa.size()>=2){
        minhaPont += retiraDaMesa(mesa, true);
        outroPont += retiraDaMesa(mesa, true);
    }

    //e a nossa diferença será de...
    return minhaPont - outroPont;
}

Rodada escolheMelhorOpcao(Rodada atual, deque<long long>& mesa){
    long long minhaPontAtual = atual.alberto, outroPontAtual = atual.wanderley, diff1, diff2;
    Rodada novaRodada;

    //estratégia - jogador 1
    diff1 = diffEscolha(minhaPontAtual, outroPontAtual, mesa, true);
    diff2 = diffEscolha(minhaPontAtual, outroPontAtual, mesa, false);

    if(diff1>diff2) {
        //escolho retirar o maior
        novaRodada.alberto = atual.alberto + retiraDaMesa(mesa, true);
        minhaPontAtual = novaRodada.alberto;
    } else {
        //escolho retirar o menor
        novaRodada.alberto = atual.alberto + retiraDaMesa(mesa, false);
        minhaPontAtual = novaRodada.alberto;
    }

    if(mesa.size()>1){
        //estratégia - jogador 2
        diff1 = diffEscolha(outroPontAtual, minhaPontAtual, mesa, true);
        diff2 = diffEscolha(outroPontAtual, minhaPontAtual, mesa, false);

        if(diff1>diff2) {
            //escolho retirar o maior
            novaRodada.wanderley = atual.wanderley + retiraDaMesa(mesa, true);
        } else {
            //escolho retirar o menor
            novaRodada.wanderley = atual.wanderley + retiraDaMesa(mesa, false);
        }
    } else novaRodada.wanderley = atual.wanderley + retiraDaMesa(mesa, true);

    return novaRodada;
}
 
int main() {
    int n;
    
    while(cin >> n){
        int cartao;
        vector<Rodada> rodadas;
        deque<long long> mesa;

        for(int x=0; x<n; x++){
            cin >> cartao;
            mesa.push_back(cartao);
        }

        rodadas.push_back(Rodada{0, 0});
        for(int x=1; x<n/2+1; x++){
            rodadas.push_back(escolheMelhorOpcao(rodadas[x-1], mesa));
        }

        cout << rodadas.back().alberto << endl;
    }
    return 0;
}