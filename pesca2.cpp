#include <bits/stdc++.h>
 
using namespace std;
 
int N;
int v[11234];
long long dp[11234][2];
 
 
int main() 
{
     
    while (scanf("%d", &N) != EOF) 
    {   
        for (int i = 0; i < N; ++i) {
            scanf("%d", &v[i]);
        }
        for (int i = 0; i < N - 1; ++i) {
            dp[i][0] = max(v[i], v[i + 1]);
        }
        int turn = 0;
        int pastTurn = 1;
        for (int intervalSize = 4; intervalSize <= N; intervalSize += 2) 
        {
            pastTurn = turn;
            turn = (!(turn & 1));
            for (int i = 0, j = intervalSize - 1; j < N; ++i, ++j) 
            {
                // cout << "debug\n";
                // cout << turn << endl;
                // cout << v[i] << endl;
                // cout << v[j] << endl;
                // cout << min(dp[i + 1][pastTurn], dp[i + 2][pastTurn]) << endl;
                // cout << min(dp[i][pastTurn], dp[i + 1][pastTurn]) << endl;
                // cout << v[i] + min(dp[i + 1][pastTurn], dp[i + 2][pastTurn]) << endl;
                // cout << v[j] + min(dp[i][pastTurn], dp[i + 1][pastTurn]) << endl;
                // cout << max(v[i] + min(dp[i + 1][pastTurn], dp[i + 2][pastTurn]),
                //                   v[j] + min(dp[i][pastTurn], dp[i + 1][pastTurn])) << endl;
                dp[i][turn] = max(v[i] + min(dp[i + 1][pastTurn], dp[i + 2][pastTurn]),
                                  v[j] + min(dp[i][pastTurn], dp[i + 1][pastTurn]));
                // cout << "pd[" << i << "]" << "[" << turn << "] recebeu " << dp[i][turn] << endl; 
            }
        }
        printf("%lld\n", dp[0][turn]);
    }
    return 0;
}