#include <bits/stdc++.h>
 
using namespace std;

int fib[22] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657};

void calculaSeq(int km, vector<int>& seq, int& soma){
    int limiteMaior = 0;
    while(fib[limiteMaior++]<=km);

    soma+=fib[limiteMaior-3];
    km -= fib[limiteMaior-2];

    if(km) calculaSeq(km, seq, soma);
}
 
int main() {
    int t, km, soma;
    cin >> t;
    while(t--){
        cin >> km;
        vector<int> seq;
        soma = 0;
        calculaSeq(km, seq, soma);

        cout<<soma<<endl;
    }
    return 0;
}