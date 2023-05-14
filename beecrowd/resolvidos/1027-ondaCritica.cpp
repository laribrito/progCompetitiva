#include <bits/stdc++.h>
using namespace std;

struct Ponto{
    int x;
    int y;
};

struct ParResult{
    int qtdSup;
    int qtdInf;
};

bool fatorOrdenacao (Ponto a, Ponto b){ return (a.x<b.x);}

int main(void){
    // lis - Longest Increasing Subsequence - A maior subsequência crescente
    int qtd, a, b, maior;
    bool valido;
    vector<ParResult> tabela; //qtdValido - paraQuemÉValido
    vector<Ponto> pontos;
    Ponto pAtual, outroP;
    ParResult par, *parAtual, *parOutro;
    while(cin>>qtd){
        for(int i=0;i<qtd;i++){
            cin >> a >> b;
            // cout << a << " "<< b << endl;
            pAtual.x = a; pAtual.y = b;
            pontos.push_back(pAtual);

            par.qtdInf = par.qtdSup = 1;
            tabela.push_back(par);
        }        

        sort(pontos.begin(), pontos.end(), fatorOrdenacao);

        maior = 1;
        for(int i=0; i<qtd;i++){
            for(int j=0; j<i; j++){
                pAtual=pontos[i]; outroP = pontos[j];
                parAtual=&tabela[i]; parOutro = &tabela[j];

                if(pAtual.x != outroP.x){
                    if((pAtual.y+2)==outroP.y){
                        if((parOutro->qtdInf+1) > parAtual->qtdSup) parAtual->qtdSup = parOutro->qtdInf + 1;
                    }

                    if((pAtual.y-2)==outroP.y){
                        if((parOutro->qtdSup+1) > parAtual->qtdInf) parAtual->qtdInf = parOutro->qtdSup + 1;
                    }
                }

                if(parAtual->qtdInf>maior) maior = parAtual->qtdInf;
                if(parAtual->qtdSup>maior) maior = parAtual->qtdSup;
            }
        }

        cout << maior << endl;

        // delete pontos;
        tabela.clear();
        pontos.clear();
    }
    return 0;
}