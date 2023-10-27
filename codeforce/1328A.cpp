#include <bits/stdc++.h>

using namespace std;

int main(){
    int m, a, b, aux;
    cin >> m;

    while(m--){
        cin >> a >> b;
        if(a%b==0){ cout << 0 << endl;   
        cout << b - a%b << endl;
        }else{
            aux = a/b;
            cout << (b*(aux+1)) - a << endl;
        }
    }
    return 0;
}