#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    //ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    int n, x;
    cin >> n >> x;

    vector <int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    //processing
    vector <int> dp(x + 1);
    dp[0] = 0;
    for(int i = 1; i <= x; ++i){
        dp[i] = -1;
    }

    for(int i = 0; i < x; ++i){
        if(dp[i] == -1)
            continue;

        for(int j = 0; j < n; ++j){
            int coin = arr[j];
            if(i + coin <= x){
                if(dp[i + coin] == -1)
                    dp[i + coin] = dp[i] + 1;
                else
                    dp[i + coin] = min(dp[i] + 1, dp[i + coin]);
            }
        }
    }

    //output
    cout << dp[x];

    return 0;
}