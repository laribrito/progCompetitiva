#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, k, soma;

    while(cin >> n >> k){
        int pos[n]={0}, dist[n]={0};
        for(int x=1; x<n; x++){
            cin >> pos[x];

            dist[x] = pos[x] - pos[x-1];
        }

        sort(dist, dist + n);

        soma = 0;
        for(int x=0; x<=n-k; x++){
            soma += dist[x];
        }

        cout << soma << endl;
    }
    return 0;
}