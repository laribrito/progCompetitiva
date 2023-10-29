#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, t, d, p, cont=1, res;

    while(cin>>n>>t && n){
        vector<pair<int, int>> dados;
        int pd[t+1] = {0};
        for(int x=0; x<n; x++){
            cin >> d >> p;
            dados.push_back(make_pair(d, p));
        }

        sort(dados.begin(), dados.end());

        for(int i=0; i<n; i++){
            for(int j=0; j<=t; j++){
                if(j>=dados[i].first && (pd[j-dados[i].first]+dados[i].second)>pd[j]){
                    pd[j] = pd[j-dados[i].first]+dados[i].second;
                }
            }
        }

        cout << "Instancia " << cont++ << endl << pd[t] << endl << endl; 
    }

    return 0;
}