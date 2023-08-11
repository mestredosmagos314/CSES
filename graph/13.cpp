#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mk make_pair
#define nl '\n'
#define INF (int) 1e9
#define BINF (ll) 1e18

using namespace std;

int n, m;
vector <int> adj[100005];
vector <int> cu[100005];
vector <int> deg(100005);
bool vis[100005];
stack <int> st;

void printl(){
    cout << st.size() << nl;
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

void dfs(int n){
    vis[n] = true;
    st.push(n);
    for(int i = 0; i < cu[n].size(); ++i){
        int nei = cu[n][i];
        if(vis[nei]){
            st.push(nei);
            printl();
            exit(0);
        }
        else
            dfs(nei);
    }
}

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        deg[i] = 0;
    }

    for(int i = 0; i < m; ++i){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        adj[tmp2].pb(tmp1);
        cu[tmp1].pb(tmp2);
        deg[tmp1]++;
    }

    queue <int> q;
    for(int i = 1; i <= n; ++i){
        if(deg[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i = 0; i < adj[curr].size(); ++i){
            int nei = adj[curr][i];
            deg[nei]--;
            if(deg[nei] == 0)
                q.push(nei);
        }
    }

    memset(vis, false, sizeof(vis));

    for(int i = 1; i <= n; ++i){
        if(deg[i] > 0){
            dfs(i);
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}