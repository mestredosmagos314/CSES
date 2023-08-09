#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define INF (int) 1e9

using namespace std;

int n, m;
vector <int> adj[100005];
queue <int> q;
vector <int> previ(100005);
bool vis[100005];

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);

    //input
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int temp1, temp2;
        cin >> temp1 >> temp2;

        adj[temp1].pb(temp2);
        adj[temp2].pb(temp1);
    }


    //processing
    q.push(1);

    memset(vis, false, sizeof(vis));
    previ[1] = 1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i = 0; i < adj[curr].size(); ++i){
            int nei = adj[curr][i];
            if(!vis[nei]){
                vis[nei] = true;
                previ[nei] = curr;
                q.push(nei);
            }
        }
    }

    //output
    if(vis[n]){
        stack <int> stack;
        int curr = n;
        stack.push(n);
        while(vis[curr]  != curr){
            stack.push(previ[curr]);
            curr = previ[curr];
        }
        cout << stack.size() << endl;
        while(!stack.empty()){
            cout << stack.top() << " ";
            stack.pop();
        }
    }
    else    
        cout << "IMPOSSIBLE";

    return 0;
}