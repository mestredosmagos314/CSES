#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    long long arr[200005];
    for(int i =0; i < n; ++i){
        cin >> arr[i];
    }

    long long dp[200005];
    dp[0] = arr[0];

    long long ans = dp[0];
    for(int i = 1; i < n; ++i){
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}