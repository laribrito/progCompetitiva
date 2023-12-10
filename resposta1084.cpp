// Estêvão Sousa - 202210345
// Larissa de Brito - 202210349
// Davi Roriz - 202210342
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, D;
    char aux;
    while (cin >> N >> D && (N != 0 && D != 0)) {
        string numero;
        cin >> numero;

        vector<char> pilha;
        for(int a = 0 ; a < numero.length() ; a++) {
            aux = numero[a];
            for( ; D > 0 && !pilha.empty() && aux > pilha.back() ; D--) {
                pilha.pop_back();
            }
            pilha.push_back(aux);
        }

        while (D > 0) {
            pilha.pop_back();
            D--;
        }

        for(int a = 0 ; a < pilha.size() ; a++) {
            cout << pilha[a];
        }
        cout << endl;
    }

    return 0;
}