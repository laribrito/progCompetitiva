#include <bits/stdc++.h>
using namespace std;

void merge(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(void){
    int numMarmore, numTestes, num, busca, contador=1;
    while(cin >> numMarmore >> numTestes && numMarmore){
        vector<int> vetor;
        for(int x=0; x<numMarmore; x++){
            cin>>num;
            vetor.push_back(num);
        }
        
        mergeSort(vetor, 0, numMarmore-1);

        cout << "CASE# " << contador++ << ":"<< endl;
        while(numTestes--){
            cin >> busca;
            
            int achou=-1;
            for(int x=0; x<vetor.size();x++){
                if(vetor[x]==busca) {
                    achou = x;
                    break;
                }
            }

            if(achou==-1) cout << busca << " not found";
            else cout << busca << " found at " << achou+1;
            cout << endl;
        }
    }
    return 0;
}