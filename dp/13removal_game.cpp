#include <bits/stdc++.h>
#define ll long long
#define INF (int) 1e9

using namespace std;

ll dp[5005][5005];

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    ll n;
    cin >> n;

    vector <ll> arr;
    vector <ll> pref; pref.push_back(0);
    ll sum = 0;
    for(int i = 0; i < n; ++i){
        int temp;
        cin >> temp;
        arr.push_back(temp);
        sum += temp; pref.push_back(sum);
    }

    //processing
    
    for(int i = 0; i < n; ++i){
        dp[i][i] = arr[i];
    }
    
    for(ll i = 1; i < n; ++i){
        ll l = 0;
        for(ll r = i; r < n; ++r){
            ll o1 = arr[l] + pref[r+1] - pref[l+1] - dp[l+1][r];
            ll o2 = arr[r] + pref[r] - pref[l] - dp[l][r-1];
            dp[l][r] = max(o1, o2);
            ++l;
        }
    }

    //output
    cout << dp[0][n-1];

    return 0;
}