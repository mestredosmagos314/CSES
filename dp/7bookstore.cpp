#include <bits/stdc++.h>
#define ll long long
#define INF (int) 1e9 + 7

using namespace std;

int main(){

    //ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    int n, x;
    cin >> n >> x;

    vector <int> weight(n);
    for(int i = 0; i < n; ++i)
        cin >> weight[i];
    
    vector <int> profit(n);
    for(int i = 0; i < n; ++i)
        cin >> profit[i];

    //processing
    int dp[100005];
    for(int i = 0; i <= x; ++i){
        dp[i] = 0;
    }

    for(int i = 0; i < n; ++i){ //i -> qual e o max(produto) que posso usar
        for(int j = x; j >= 0; --j){ //j -> peso
            if(j - weight[i] >= 0)
                dp[j] = max(dp[j], profit[i] + dp[j - weight[i]]);
        }
    }

    //output
    cout << dp[x];

    return 0;
}