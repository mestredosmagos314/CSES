#include <bits/stdc++.h>
#define ll long long
#define INF (int) 1e9
 
using namespace std;
 
int main(){
 
    //ios::sync_with_stdio(false); cin.tie(NULL);
 
    //input
    int n;
    cin >> n;
 
    vector <int> arr(200005);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
 
    //processing
    int dp[n]; //dp[i] -> size of the longest increasing subsequence ending at i
    dp[0] = 1;

    set <pair <int, int>> set; //set de pair {LIS, maior valor da LIS}
    set.insert({1, arr[0]});
    for(int i = 1; i < n; ++i){
        int l = 0;
        int r = i;
        int LIS = 0;
        while(l <= r){
            int m = l + (r-l)/2;
            auto it = set.lower_bound({m,0});
            if(it == set.end()){
                --it;
            }
            pair <int, int> pair = *it;
            if(pair.second < arr[i]){
                LIS = pair.first;
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
 
        dp[i] = LIS + 1;
        set.insert({dp[i], arr[i]});
    }
 
    //output
    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans = max(ans, dp[i]);
    }
    cout << ans;
 
    return 0;
}