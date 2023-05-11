#include <bits/stdc++.h>
using namespace std;

int fibonacci(int a, int *count){
    (*count)++;
    if (a == 0) return 0;
    else if(a==1) return 1;

    else {
        return fibonacci(a-1, count)+fibonacci(a-2, count);
    }
}

int main(void){
    int qtd, n, chamadas, fib;
    cin >> qtd;
    while(qtd--){
        cin >> n;
        chamadas=0;
        fib = fibonacci(n, &chamadas);
        cout << "fib(" << n << ") = " << chamadas-1 << " calls = " << fib << endl; 
    }
    return 0;
}