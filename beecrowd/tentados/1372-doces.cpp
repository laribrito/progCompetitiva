#include <bits/stdc++.h>

using namespace std;

int main(void){ 
    int m, n; 
    long long aux;

    while(scanf("%d %d", &m, &n) && (m+n)){
        int pdVertical[m], pdLinha[n], matriz[m][n];
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++) cin >> matriz[i][j];
        

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(j==0)  pdLinha[0] = matriz[i][j];
                else if(j==1){
                    if(matriz[i][j]>pdLinha[0]) pdLinha[1] = matriz[i][j];
                    else pdLinha[1] = pdLinha[0];
                } else {
                    aux = pdLinha[1];
                    if(aux>pdLinha[0]+matriz[i][j]) pdLinha[1] = aux;
                    else pdLinha[1] = pdLinha[0]+matriz[i][j];
                    pdLinha[0] = aux;
                }
            }
                    
            if(i==0)  pdVertical[0]  = pdLinha[1];
            else if(i==1){
                if(pdLinha[1]>pdVertical[0]) pdVertical[1] = pdLinha[1];
                else pdVertical[1] = pdVertical[0];
            } else {
                aux = pdVertical[1];
                if(aux>pdVertical[0]+pdLinha[1]) pdVertical[1] = aux;
                else pdVertical[1] = pdVertical[0]+pdLinha[1];
                pdVertical[0] = aux;
            }
        }
    
        cout << pdVertical[1] << endl;
    }
    return 0;
}