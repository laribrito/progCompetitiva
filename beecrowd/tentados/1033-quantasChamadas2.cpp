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
    int n, chamadas, fib, base, x=1;
    while(cin >> n >> base){
        if(n==0 && base == 0) break;
        chamadas=0;
        fibonacci(n, &chamadas);
        printf("Case %d: %d %d %d\n", x++, n, base, chamadas%base);
    }
    return 0;
}