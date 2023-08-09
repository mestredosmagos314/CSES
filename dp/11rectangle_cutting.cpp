#include <bits/stdc++.h>
#define ll long long
#define INF (int) 1e9

using namespace std;

int main(){

    //ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    int a, b;
    cin >> a >> b;

    //processing
    int dp[505][505];
    dp[0][0] = 0;

    for(int i = 1; i <= a; ++ i){
        for(int j = 1; j <= b; ++j){
            dp[i][j] = INF;
            if(i == j){
                dp[i][j] = 0;
                continue;
            }

            for(int k = 1; k < i; ++k) //improvable
                dp[i][j] = min(dp[i][j], dp[i-k][j] + dp[k][j] + 1);
            for(int k = 1; k < j; ++k) //improvable
                dp[i][j] = min(dp[i][j], dp[i][j-k] + dp[i][k] + 1);
        }
    }

    //output
    cout << dp[a][b];

    return 0;
}