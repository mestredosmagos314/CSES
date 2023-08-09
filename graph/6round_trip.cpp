#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define INF (int) 1e9
#define nl '\n'

using namespace std;

int n, m;
vector <int> adj[100005];
int previ[100005];
bool vis[100005];

void dfs(int n, int prev){
    vis[n] = true;
    previ[n] = prev;
    for(int i = 0; i < adj[n].size(); ++i){
        int viz = adj[n][i];
        if(viz == previ[n])
            continue;
        if(vis[viz]){
            queue <int> q;
            q.push(viz);
            q.push(n);
            while(n != viz){
                q.push(previ[n]);
                n = previ[n];
            }
            cout << q.size() << nl;
            while(!q.empty()){
                cout << q.front() << " ";
                q.pop();
            }
            exit(0);
        }
        else
            dfs(viz, n);
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
    for(int i = 1; i <= n; ++i){
        if(!vis[i])
            dfs(i, i);
    }

    //output
    cout << "IMPOSSIBLE";
    return 0;
}