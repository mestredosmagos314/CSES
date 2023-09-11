#include <bits/stdc++.h>

#define ll long long
#define INF (int) 1e9

using namespace std;

int n, k, c;
int arr[10005];
ll dp[10005][10005];

int main(){

    //reading input
    cin >> n >> k >> c;

    

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    if(c == 1){
        sort(arr, arr + n);
        ll sum = 0;
        for(int i = n-1; i >= k; --i){
            sum += arr[i];
        }
        cout << sum;
        return 0;
    }

    //calculating base cases of the DP
    dp[0][0] = 0;

    for(int i = 1; i <= n; ++i){
        dp[i][0] = dp[i-1][0] + arr[i-1];
    }

    for(int i = 1; i <= k; ++i){
        dp[0][i] = -INF;
    }

    //calculating the DP
    for(int i = 1; i <= k; ++i){
        for(int j = 1; j <= n; ++j){
            if(j < c){
                dp[j][i] = -INF;
            }
            else{
                dp[j][i] = max(arr[j-1] + dp[j-1][i], dp[j-c][i-1]);
            }
        }
    }

    cout << dp[n][k];

    return 0;
}