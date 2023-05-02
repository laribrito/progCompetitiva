#include <bits/stdc++.h>
using namespace std;

int main(void){
    unsigned int a, b;
    while(cin >> a >> b){
        int novo = a ^ b;
        if(novo==-1) cout << "4294967295";
        else cout << novo;
        cout << endl;
    }
    return 0;
}