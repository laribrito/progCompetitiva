    #include <bits/stdc++.h>
    using namespace std;

    int main(void){
        int numMarmore, numTestes, num, busca, contador=1;
        while(cin >> numMarmore >> numTestes && numMarmore){
            vector<int> vetor;
            for(int x=0; x<numMarmore; x++){
                cin>>num;
                vetor.push_back(num);
            }
            
            sort(vetor.begin(), vetor.end());

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