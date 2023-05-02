#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        string texto, aux;
        getline(cin, texto);
        for(int x=texto.size()-1; x>=0; x--){
            if(isalpha(texto[x])){
                texto[x]+=3;
            }
            aux += texto[x];
        }

        for(int x=texto.size()/2; x<texto.size(); x++) --aux[x];

        cout << aux << endl;
    }
    return 0;
}