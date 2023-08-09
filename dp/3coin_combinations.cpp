#include <bits/stdc++.h>

using namespace std;

int main(){

    //ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    int n, x;
    cin >> n >> x;

    vector <int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //processing
    vector <int> dp(x+1);
    for(int i = 1; i <= x; ++i){
        dp[i] = 0;
    }
    dp[0] = 1;

    for(int i = 0; i < x; i++){
        for(int j = 0; j < n; ++j){
            if(i + arr[j] > x)
                continue;
            dp[i + arr[j]] += dp[i];
            dp[i + arr[j]] %= (int) 1e9 + 7;
        }
    }

    //output
    cout << dp[x];

    return 0;
}