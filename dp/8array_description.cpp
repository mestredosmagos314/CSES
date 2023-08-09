#include <bits/stdc++.h>
#define ll long long
#define INF (int) 1e9

using namespace std;

int main(){

    //ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    ll n, m;
    cin >> n >> m;

    vector <ll> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    //processing
    ll dp[100005][105];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; ++i){
        if(arr[i] == 0)
            continue;
        dp[i][arr[i]] = 1;
    }

    if(arr[0] == 0){
        for(int j = 1; j <= m; ++j){
            dp[0][j] = 1;
        }
    }

    for(int i = 1; i < n; ++i){
        if(arr[i] != 0){
            int j = arr[i];
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % (int) (1e9 + 7);
            continue;
        }
        for(int j = 1; j <= m; ++j){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % (int) (1e9 + 7);
        }
    }

    //output
    ll ans = 0;
    for(int i = 1; i <= m; ++i){
        ans += dp[n-1][i];
        ans %= (int) (1e9 + 7);
    }

    cout << ans;

    return 0;
}