#include <bits/stdc++.h>
using namespace std;

struct Ponto{
    int x;
    int y;
};

struct ParResult{
    int qtdValido;
    int ySup;
    int yInf;
};

bool ehValido(Ponto a, Ponto b){
    
}

bool fatorOrdenacao (Ponto a, Ponto b){ return (a.x<b.x);}

bool restricaoMaiorElemento (ParResult a, ParResult b){ return (a.qtdValido<b.qtdValido);}

int main(void){
    // lis - Longest Increasing Subsequence - A maior subsequência crescente
    int qtd, a, b, maior;
    bool valido;
    vector<ParResult> tabela; //qtdValido - paraQuemÉValido
    vector<Ponto> pontos;
    Ponto p1, p2;
    ParResult par;
    while(cin>>qtd){
        for(int i=0;i<qtd;i++){
            cin >> a >> b;
            // cout << a << " "<< b << endl;
            p1.x = a; p1.y = b;
            pontos.push_back(p1);

            par.yInf = -1; par.ySup = -1; par.qtdValido = 1;
            tabela.push_back(par);
        }

        // for(auto it=pontos.begin(); it!=pontos.end();it++){
        //     cout << "x: " << (*it).x << " y: " << (*it).y <<endl;
        // }
        // cout << endl;
        

        sort(pontos.begin(), pontos.end(), fatorOrdenacao);

        // for(auto it=pontos.begin(); it!=pontos.end();it++){
        //     cout << "x: " << (*it).x << " y: " << (*it).y <<endl;
        // }
        // cout << endl;

        maior = 1;
        for(int i=0; i<qtd;i++){
            for(int j=0; j<i; j++){
                p1=pontos[i]; p2 = pontos[j];

                if(p1.x != p2.x){
                    if ((tabela[j].yInf != -1 && p2.y==tabela[j].yInf) || (tabela[j].yInf == -1 && p1.y - 2 == p2.y)){
                        tabela[i].yInf = pontos[j].y;
                        tabela[i].qtdValido=tabela[j].qtdValido+1;
                    }

                    if ((tabela[j].ySup != -1 && p2.y==tabela[j].ySup) || (tabela[j].ySup == -1 && p1.y + 2 == p2.y)){
                        tabela[i].ySup = pontos[j].y;
                        tabela[i].qtdValido=tabela[j].qtdValido+1;
                    }
                }

                // cout << endl << "i: " << i << " j: " << j <<endl << " ";
                // for(auto it=tabela.begin(); it!=tabela.end();it++){
                //     cout << (*it).qtdValido << "  ";
                // }
                // cout << endl;
                // for(auto it=tabela.begin(); it!=tabela.end();it++){
                //     cout << (*it).yInf << " ";
                // }
                // cout << endl;
                // for(auto it=tabela.begin(); it!=tabela.end();it++){
                //     cout << (*it).ySup << " ";
                // }
                // cout << endl;

                if(tabela[i].qtdValido>maior) maior = tabela[i].qtdValido;
            }
        }

        // for(auto it=tabela.begin(); it!=tabela.end();it++){
        //     cout << *it << " ";
        // }
        // cout << endl;

        cout << maior << endl;

        // delete pontos;
        tabela.clear();
        pontos.clear();
    }
    return 0;
}