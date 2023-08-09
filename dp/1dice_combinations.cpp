#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    //ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    int n;
    cin >> n;

    //processing
    vector <int> dp(n+1);
    for(int i = 1; i <= n; ++i){
        dp[i] = 0;
    }
    dp[0] = 1;

    for(int i = 0; i < n; ++i){
        for(int j = 1; j <= 6; ++j){
            if(i + j <= n){
                dp[i + j] += dp[i];
                dp[i+j] %= (int) 1e9 + 7;
            }
        }
    }

    //output
    cout << dp[n];

    return 0;
}