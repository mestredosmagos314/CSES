#include <bits/stdc++.h>
#define ll long long
#define INF (int) 1e9

using namespace std;

int dp[1000005];

int main(){

    //input
    int n;
    cin >> n;

    //processing
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;

    int cap = n*(n+1)/2;
    
    for(int i = 2; i < n; ++i){
        for(int j = cap - i; j >= 0; --j){
            dp[j+i] += dp[j];
            dp[j+i] %= (int) 1e9 + 7;
        }
    }

    //output
    if(n*(n+1) % 4 == 0)
        cout << dp[n*(n+1)/4 - n];
    else
        cout << 0;

    return 0;
}