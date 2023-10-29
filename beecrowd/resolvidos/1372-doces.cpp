#include <bits/stdc++.h>

using namespace std;

long long int max(long long int a, long long int b){
    return (a>b)? a: b;
}

int main(void){ 
    int m, n; 
    long long aux;

    while(scanf("%d %d", &m, &n) && (m+n)){
        long long int pdVertical[m]={0}, pdLinha[n]={0}, matriz[m][n]={0};
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++) cin >> matriz[i][j];
        

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(j==0)  pdLinha[0] = matriz[i][j];
                else if(j==1){
                    pdLinha[1] = max(pdLinha[0], matriz[i][j]);
                } else {
                    pdLinha[j] = max(matriz[i][j]+pdLinha[j-2], pdLinha[j-1]);
                }
            }
                    
            if(i==0)  pdVertical[0]  = pdLinha[n-1];
            else if(i==1){
                pdVertical[1] = max(pdLinha[n-1], pdVertical[0]);
            } else {
                pdVertical[i] = max(pdVertical[i-2]+pdLinha[n-1], pdVertical[i-1]);
            }
        }
    
        cout << pdVertical[m-1] << endl;
    }
    return 0;
}