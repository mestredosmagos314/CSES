#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mk make_pair
#define nl '\n'
#define INF (int) 1e12

using namespace std;

int n, m;
vector <pair <int, ll>> adj[100005];
ll dist[100005];
bool vis[100005];

int main(){

    //ios::sync_with_stdio(false); cin.tie(nullptr);

    //input
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        ll tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        adj[tmp1].pb(make_pair(tmp2,tmp3));
    }

    //processing
    memset(dist, -1, sizeof(dist));
    dist[1] = 0;

    priority_queue <pair<ll, int>> pq;
    pq.push(mk(0, 1));

    for(int j = 0; j < n; ++j){
        //dijkstras part 1
        int curr = pq.top().second; pq.pop();
        while(vis[curr]){
            curr = pq.top().second; pq.pop();
        }
        vis[curr] = true;

        //dijsktras part 2
        for(int i = 0; i < adj[curr].size(); ++i){
            int nei = adj[curr][i].first;
            ll w = adj[curr][i].second;

            if(vis[nei])
                continue;

            if(dist[nei] == -1 || dist[nei] > dist[curr] + w){
                dist[nei] = dist[curr] + w;
                pq.push(mk(-dist[nei], nei));
            }
        }
    }

    //output
    for(int i = 1; i <= n; ++i){
        cout << dist[i] << " ";
    }

    return 0;
}