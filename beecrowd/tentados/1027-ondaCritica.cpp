#include <bits/stdc++.h>
using namespace std;

struct Ponto{
    int x;
    int y;
};

struct ParResult{
    int qtdValido;
    int index;
};

bool ehValidoMaior(Ponto a, int indexA, Ponto b, int indexB, vector<ParResult> tabela, vector<Ponto> pontos){

    bool valido = true;
    if(a.x == b.x) valido = false;
    else if (tabela[indexB].qtdValido==1){
        if(abs(a.y - b.y) != 2) valido = false;
    } else {
        if(a.y != pontos[ tabela[indexB].index ].y) valido = false;
    }

    return valido;
}

bool ehValido(Ponto a, Ponto b){

    bool valido = true;
    if(a.x == b.x) valido = false;
    else if(abs(a.y - b.y) != 2) valido = false;

    return valido;
}

bool fatorOrdenacao (Ponto a, Ponto b){ return (a.x<b.x);}

bool restricaoMaiorElemento (ParResult a, ParResult b){ return (a.qtdValido<b.qtdValido);}

int main(void){
    // lis - Longest Increasing Subsequence - A maior subsequência crescente
    int qtd, a, b;
    vector<ParResult> tabela; //qtdValido - paraQuemÉValido
    vector<Ponto> pontos;
    Ponto p;
    ParResult par;
    while(cin>>qtd){
        for(int i=0;i<qtd;i++){
            cin >> a >> b;
            p.x = a; p.y = b;
            pontos.push_back(p);

            par.index = -1; par.qtdValido = 1;
            tabela.push_back(par);
        }        

        sort(pontos.begin(), pontos.end(), fatorOrdenacao);

        // for(auto it=pontos.begin(); it!=pontos.end();it++){
        //     cout << "x: " << (*it).x << " y: " << (*it).y <<endl;
        // }
        // cout << endl;

        for(int i=0; i<qtd;i++){
            for(int j=0; j<i; j++){
                if(ehValidoMaior(pontos[i], i, pontos[j], j, tabela, pontos)){
                    // if(i==5 && j==3) cout << endl << (tabela[j].qtdValido+1) << " " << tabela[i].qtdValido << " = " << ((tabela[j].qtdValido+1) > tabela[i].qtdValido);
                    if((tabela[j].qtdValido+1) > tabela[i].qtdValido){
                        tabela[i].qtdValido=tabela[j].qtdValido+1;
                        tabela[i].index = j;
                    }
                } else if(ehValido(pontos[i], pontos[j])){
                    if(tabela[i].qtdValido<2){
                        tabela[i].qtdValido=2;
                        tabela[i].index = j;
                    }
                }


                // cout << endl << "i: " << i << " j: " << j <<endl << " ";
                // for(auto it=tabela.begin(); it!=tabela.end();it++){
                //     cout << (*it).qtdValido << "  ";
                // }
                // cout << endl;
                // for(auto it=tabela.begin(); it!=tabela.end();it++){
                //     cout << (*it).index << " ";
                // }
                // cout << endl;
            }
        }

        // for(auto it=tabela.begin(); it!=tabela.end();it++){
        //     cout << *it << " ";
        // }
        // cout << endl;

        cout << (*max_element(tabela.begin(), tabela.end(), restricaoMaiorElemento)).qtdValido << endl;

        // delete pontos;
        tabela.clear();
        pontos.clear();
    }
    return 0;
}