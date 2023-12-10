#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    long long int n, atual, res, transporte;
    while(cin>>n && n){
        res = 0; transporte = 0;
        while(n--){
            cin>>atual;
            res += abs(transporte);
            transporte += atual;
        }

        cout << res << endl;
    }
    return 0;
}