#include <bits/stdc++.h>

using namespace std;

int calcula(int a, int b, int c, vector<int> coef){
    int res=a*coef[0];

    if(b!=0) res+=b*coef[1];
    if(c!=0) res+=c*coef[2];

    return res;
}

// Função para calcular o fatorial de um número
unsigned long long fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}

// Função para calcular permutações (nPr)
unsigned long long permutacao(int n, int r) {
    if (r < 0 || r > n) {
        return 0;  // Tratamento para valores inválidos de r
    }

    return fatorial(n) / fatorial(n - r);
}

int main(){
    int m, n, cn, qtd;
    bool possivel;

    while(cin >> n >> m){
        vector<int> coef;
        for(int x=0; x<n; x++){
            cin >> cn;
            coef.push_back(cn);
        }

        int caso[n];
        possivel = true;
        set<int> resultados;
        qtd = permutacao(m, n);
        if(n==3)
            for(int i=1; i<=m && possivel; i++)
                for(int j=1; j<=m && possivel; j++)
                    for(int k=1; k<=m && possivel; k++){

                        if(i!=j && j!=k && i!=k){
                            caso[0] = i;
                            caso[1] = j;
                            caso[2] = k;

                            resultados.insert(calcula(caso[0], caso[1], caso[2], coef));
                        }
                    }
        else if(n==2)
            for(int i=1; i<=m && possivel; i++)
                for(int j=1; j<=m && possivel; j++){
                    if(i!=j){
                        caso[0] = i;
                        caso[1] = j;

                        resultados.insert(calcula(caso[0], caso[1], 0, coef));
                    }
                }

        if(resultados.size() == qtd || n==1){
            cout << "Lucky Denis!\n";
        } else {
            cout << "Try again later, Denis...\n";
        }
    }
    return 0;
}