#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define nl '\n'
#define INF (int) 1e9
#define BINF (ll) 1e18

int n, m;
vector <int> adj[100005];
vector <int> deg(100005);
queue <int> q;
vector <int> dp(100005);
vector <int> nx(100005);
int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);

    //input
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        deg[i] = 0;
    }
    for(int i = 0; i < m; ++i){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        adj[tmp2].pb(tmp1);
        deg[tmp1]++;
    }
    
    
    //processing
    for(int i = 1; i <= n; ++i){
        dp[i] = 0;
        if(deg[i] == 0){
            q.push(i);
        }
    }

    dp[n] = 1;
    nx[n] = -1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i = 0; i < adj[curr].size(); ++i){
            int nei = adj[curr][i];
            deg[nei]--;
            if(deg[nei] == 0){
                q.push(nei);
            }
            if(dp[curr] == 0)
                continue;
            if(dp[nei] < dp[curr] + 1){
                dp[nei] = dp[curr] + 1;
                nx[nei] = curr;
            }
        }
    }
    //output
    if(dp[1] == 0)
        cout << "IMPOSSIBLE";
    else{
        cout << dp[1] << endl;
        int cr = 1;
        cout << cr << " ";
        while(nx[cr] != -1){
            cout << nx[cr] << " ";
            cr = nx[cr];
        }
    }
    return 0;
}