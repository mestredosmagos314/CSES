#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, x;
int coin[105];
int dp[1000005];

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    cin >> n >> x;

    for(int i = 1; i <= n; ++i){
        cin >> coin[i];
    }

    //processing
    dp[0] = 1;
    for(int i = 1; i <= x; ++i){
        dp[i] = 0;
    }

    sort(coin + 1, coin + n + 1);

    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= x; ++i){
            if(i - coin[k] >= 0)
                dp[i] += dp[i - coin[k]];
            dp[i] %= (int) 1e9 + 7;
        }
    }

    //output
    cout << dp[x];

    return 0;
}