#include <bits/stdc++.h>
using namespace std;

class Ponto{
    private:
        short int x;
        short int y;
    public:
        short int validos;
        Ponto (int a, int b): x(a), y(b), validos(1) {}

        bool ehValido(Ponto outro){
            bool valido = true;
            if(this->x == outro.x) valido = false;
            else if(validos%2==0 && outro.y!=this->y-2) valido = false;
            else if(validos%2==1 && outro.y!=this->y+2) valido = false;

            cout << x << " " << y << endl;
            cout << outro.x << " " << outro.y << endl;
            cout << validos << endl;
            cout << valido << endl << endl;

            if(valido) validos++;
        }
};

int main(void){
    short int x, y, maior;
    int qtd;
    while(cin >> qtd){
        vector<Ponto> pontos;
        for(int z=0;z<qtd;z++){
            cin >> x >> y;
            Ponto p(x, y);
            pontos.push_back(p);
        }
        for(int x=0; x<qtd; x++){
            for(int y=0; y<qtd; y++){
                if(x!=y) pontos[x].ehValido(pontos[y]);
            }
            if(x==0) maior = pontos[0].validos;
            else if(pontos[x].validos > maior) maior = pontos[x].validos;
        }
        cout << maior << endl;
    }    
    return 0;
}