#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mk make_pair
#define nl '\n'
#define INF (int) 1e9
#define BINF (ll) 1e18

using namespace std;

int n, m;
vector <pair <int, ll>> adj[100005];
ll dist[100005];
bool vis[100005];

//new
vector <ll> qtd(100005);
vector <int> mn(100005);
vector <int> mx(100005);
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
    for(int i = 1; i <= n; ++i){
        dist[i] = BINF;
        mn[i] = INF;
        mx[i] = 0;
        qtd[i] = 0;
    }
    dist[1] = 0;
    mn[1] = 1;
    mx[1] = 1;
    qtd[1] = 1;

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

            if(dist[nei] == dist[curr] + w){
                qtd[nei] += qtd[curr];
                qtd[nei] %= (int) 1e9 + 7;
                mn[nei] = min(mn[nei], mn[curr] + 1);
                mx[nei] = max(mx[nei], mx[curr] + 1);
            }

            else if(dist[nei] > dist[curr] + w){
                dist[nei] = dist[curr] + w;
                pq.push(mk(-dist[nei], nei));
                mn[nei] = mn[curr] + 1;
                mx[nei] = mx[curr] + 1;
                qtd[nei] = qtd[curr];
            }
        }
    }

    //output
    cout << dist[n] << " " << qtd[n] << " " << mn[n]-1 << " " << mx[n]-1;
    
    return 0;
}