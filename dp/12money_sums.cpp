#include <bits/stdc++.h>
#define ll long long
#define INF (int) 1e9

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    int n;
    cin >> n;

    vector <int> arr(n);
    int sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        sum += arr[i];
    }

    //processing
    bool dp[100005]; //dp[i][j] -> can I make sum j using up to coin i?
    memset(dp, false, sizeof(dp));
    dp[0] = true;

    set <int> ans;
    for(int i = 0; i < n; ++i){
        for(int j = sum; j >= 1; --j){
            if(j - arr[i] >= 0 && dp[j-arr[i]] == true){
                dp[j] = true;
                ans.insert(j);
            }
        }
    }

    //output
    cout << ans.size() << endl;
    for(auto x: ans){
        cout << x << " ";
    }

    return 0;
}