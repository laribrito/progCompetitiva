#include <bits/stdc++.h>

using namespace std;

int oMaior(int x, int y){
    return (x + y + abs(x-y))/2;
}

int main(void){
    int a, b, c;
    cin >> a >> b >> c;

    cout << oMaior(oMaior(a, b), c) << " eh o maior"<< endl;

    return 0;
}