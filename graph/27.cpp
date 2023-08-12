#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define INF (int) 1e9 + 10
#define BINF (ll) 1e18 + 10
#define nl '\n'

int n, m;
vector <int> adj[100005];
bool vis[100005];
stack <int> st;
vector <int> rev[100005];
int ans = 0;
int coin[100005];
vector <int> meta;

void dfs(int n){
    vis[n] = true;
    for(int i = 0; i < adj[n].size(); ++i){
        int nei = adj[n][i];
        if(!vis[nei])
            dfs(nei);
    }
    st.push(n);
}

void dfs_rev(int n){
    vis[n] = true;
    for(int i = 0; i < rev[n].size(); ++i){
        int nei = rev[n][i];
        if(!vis[nei]){
            dfs_rev(nei);
            meta[ans-1] += coin[nei];
        }
    }
}

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);

    //input
    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        cin >> coin[i+1];
    }

    for(int i = 0; i < m; ++i){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        adj[tmp1].pb(tmp2);
        rev[tmp2].pb(tmp1);
    }

    //processing
    for(int i = 1; i <= n; ++i){
        vis[i] = false;
    }

    //kosaraju part 1 (make the dfs stack)
    for(int i = 1; i <= n; ++i){
        if(!vis[i])
            dfs(i);
    }

    //kosaraju part 2 (reverse the edges)
    for(int i = 1; i <= n; ++i){
        vis[i] = false;
    }

    //kosaraju part 3 (traverse bs)
 
    int prev;
    while(!st.empty()){
        int tp = st.top();
        st.pop();

        if(ans == 0)
            prev = tp;

        if(!vis[tp]){
            ans++;
            meta.pb(coin[tp]);
            dfs_rev(tp);
        }
    }

    //top-sort on the meta-graph

    //output
    //meta graph has ans nodes. king[i] -> amount of coins in the node i of the metagraph (0 ... n-1)



    return 0;
}