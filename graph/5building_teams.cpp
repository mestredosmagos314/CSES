#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define INF (int) 1e9
#define endl nl

using namespace std;

int n, m;
vector <int> adj[100005];
bool vis[100005];
bool col[100005];

void dfs(int n, int prev){
    vis[n] = true;
    col[n] = !col[prev];
    for(int i = 0; i < adj[n].size(); ++i){
        int nei = adj[n][i];

        if(!vis[nei]){
            dfs(nei, n);
        }
        else{
            if(col[n] == col[nei]){
                cout << "IMPOSSIBLE";
                exit(0);
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);

    //input
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        adj[tmp1].pb(tmp2);
        adj[tmp2].pb(tmp1);
    }

    //processing
    memset(vis, false, sizeof(vis));
    for(int i = 1; i <= n; ++i){
        if(vis[i])
            continue;
        else{
            col[i] = 0;
            dfs(i, i);
        }
    }

    //output
    for(int i = 1; i <= n; ++i){
        cout << col[i] + 1 << " ";
    }

    return 0;
}