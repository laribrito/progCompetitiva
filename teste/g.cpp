#include <bits/stdc++.h>
using namespace std;

int main(void){
    int totalQst, necessariasQst;
    vector<float> probs;
    float valProb;

    cin >> totalQst >> necessariasQst;
    for(int x=totalQst; x>=1; x--){
        cin >> valProb;
        probs.push_back(valProb);
    }

    sort(probs.begin(),probs.end());

    
    return 0;
}