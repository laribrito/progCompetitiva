#include <bits/stdc++.h>
using namespace std;

class Arvore{
    private:
        Arvore* filhoEsquerdo, *filhoDireito;

        char info;
    public:
        Arvore(char val) {
            info = val;
            filhoEsquerdo = NULL;
            filhoDireito = NULL;
        }

        Arvore* filhoE(){
            return filhoEsquerdo;
        }

        Arvore* filhoD(){
            return filhoDireito;
        }

        Arvore* insereFilhoE(Arvore *f){
            filhoEsquerdo = f;
            return f;
        }

        Arvore* insereFilhoD(Arvore *f){
            filhoDireito = f;
            return f;
        }

        char valor(){
            return info;
        }

        void posfixa() {
            if(filhoEsquerdo) filhoEsquerdo->posfixa();
            if(filhoDireito) filhoDireito->posfixa();
            cout << info;
            return;
        }
};

Arvore* geraArvore(string pre, int *indicePre, string inf){
    char atual = pre[*indicePre];
    Arvore *no = new Arvore(atual);

    if(inf.size()==1) return no;
    long unsigned int indiceInf = inf.find(atual);
    if(indiceInf != string::npos){
        if(indiceInf>=1){
            (*indicePre)++;
            no->insereFilhoE(geraArvore(pre, indicePre, inf.substr(0, indiceInf)));
        }
        if((indiceInf+1)<inf.size()){
            (*indicePre)++;
            no->insereFilhoD(geraArvore(pre, indicePre,inf.substr(indiceInf+1, inf.size()-1)));
        }
    } 
    return no;
}

int main(void){
    string prefixo, infixo;
    int indAuxPrefixo;
    Arvore *raiz;
    while(cin>>prefixo>>infixo){
        indAuxPrefixo = 0;
        raiz = geraArvore(prefixo, &indAuxPrefixo, infixo);
        raiz->posfixa();
        cout << endl;
    }
    return 0;
}