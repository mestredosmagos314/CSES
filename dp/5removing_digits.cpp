#include <bits/stdc++.h>
#define ll long long
#define INF (int) 1e9

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    int n;
    cin >> n;

    //processing
    vector <int> dp(n+5);
    dp[0] = 0;
    
    for(int i = 10; i <= n; ++i){
        dp[i] = INF;
        int temp = i;
        while(temp > 0){
            int sla = temp % 10;
            temp /= 10;
            dp[i] = min(dp[i], dp[i-sla] + 1);
        }
    }

    //output
    cout << dp[n];

    return 0;
}