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
stack <int> st;
queue <int> q;

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
        if(deg[i] == 0){
            q.push(i);
            st.push(i);   
        }
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i = 0; i < adj[curr].size(); ++i){
            int nei = adj[curr][i];
            deg[nei]--;
            if(deg[nei] == 0){
                q.push(nei);
                st.push(nei);
            }
        }
    }
    //output
    if(st.size() < n)
        cout << "IMPOSSIBLE";
    else{
        while(!st.empty()){
            cout << st.top() << " ";
            st.pop();
        }
    }
    return 0;
}