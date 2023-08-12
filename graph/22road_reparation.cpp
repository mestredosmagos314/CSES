#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define INF (int) 1e9 + 1
#define BINF (ll) 1e18
#define nl '\n'

int n, m;
vector <pair<int, int>> adj[100005];
bool vis[100005];
int dist[100005];

int main(){

    //input
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        adj[tmp1].pb({tmp2, tmp3});
        adj[tmp2].pb({tmp1, tmp3});
    }

    //processing
    for(int i = 1; i <= n; ++i){
        dist[i] = INF;
        vis[i] = false;
    }
    dist[1] = 0;

    ll ans = 0;

    priority_queue <pair <int, int>> pq;
    pq.push({0, 1});

    while(!pq.empty()){
        //part 1
        int curr;
        int cost;
        do{
            if(pq.empty())
                break;
            curr = pq.top().second;
            cost = -pq.top().first;
            pq.pop();
            
        }while(vis[curr]);
        if(vis[curr])
            break;

        vis[curr] = true;
        ans += cost;

        //part 2
        for(int i = 0; i < adj[curr].size(); ++i){
            int viz = adj[curr][i].first;
            int w = adj[curr][i].second;

            if(dist[viz] > w){
                dist[viz] = w;
                pq.push({-w, viz});
            }
        }
    }

    //output
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    cout << ans;

    return 0;
}