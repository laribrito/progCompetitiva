#include <bits/stdc++.h>
using namespace std;

int mdc(int a, int b){
    if(a%b==0) return b;
    else return mdc(b, a%b);
}

int main(void){
    int n, a, b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        cout << mdc(a,b) << endl;
    }
    return 0;
}