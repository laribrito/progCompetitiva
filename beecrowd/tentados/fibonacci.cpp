#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;

    cin >> n;

    int fib[n];

    for(int i=0; i<n;i++){
        if(i==0) fib[0]=0;
        else if(i ==1) fib[1]=1;
        else{
            fib[i] = fib[i-1]+fib[i-2];
        }
    }

    cout << fib[n-1] << endl;

    return 0;
}