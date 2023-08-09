#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define INF (int) 1e9

using namespace std;

int n, m;
vector <int> adj[100005];
bool vis[100005];

void dfs(int n){
    vis[n] = true;
    for(int i = 0; i < adj[n].size(); ++i){
        int neig = adj[n][i];
        if(!vis[neig])
            dfs(neig);
    }
}

int main(){

    //ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp1].pb(temp2);
        adj[temp2].pb(temp1);
    }

    //processing
    vector <int> ans; //saves the "leaders" of each component. just gotta link em.
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            ans.pb(i);
            dfs(i);
        }
    }

    //output
    cout << ans.size() - 1 << endl;

    int god = ans[0];
    for(int i = 1; i < ans.size(); ++i){
        cout << god << " " << ans[i] << endl;
    }

    return 0;
}