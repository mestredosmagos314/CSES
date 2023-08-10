#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mk make_pair
#define mt make_tuple
#define nl '\n'
#define INF (int) 1e9
#define BINF (ll) 1e18 //cringe as fuck LOL

using namespace std;

//variables
int n, m;
vector <tuple<ll, ll, ll>> adj;
vector <ll> dist(2505);
vector <ll> sla[2505];
bool vis[2505];
bool vis2[2505];
vector <ll> cp;

void dfs(int n2){
    vis[n2] = true;
    for(int i = 0; i < sla[n2].size(); ++i){
        int viz = sla[n2][i];
        if(viz == n){
            cout << -1;
            exit(0);
        }
        if(vis[viz])
            continue;
        dfs(viz);
    }
}

void dfs2(int n2){
    vis2[n2] = true;
    for(int i = 0; i < sla[n2].size(); ++i){
        int viz = sla[n2][i];
        if(dist[viz] != cp[viz]){
            dfs(viz);
        }
        if(vis2[viz])
            continue;
        dfs2(viz);
    }
}

int main(){

    //ios::sync_with_stdio(false); cin.tie(nullptr);
    
    //input
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        ll tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        adj.pb(mt(tmp1, tmp2, -tmp3));
        sla[tmp1].pb(tmp2);
    }

    //processing
    for(int i = 2; i <= n; ++i){
        dist[i] = INF;
    }
    dist[1] = 0;
    for(int i = 1; i < n; ++i){
        for(auto e : adj){
            int a, b, w;
            tie(a, b, w) = e;
            dist[b] = min(dist[b], dist[a] + w);
        }
    }
    cp = dist;
    for(auto e : adj){
        int a, b, w;
        tie(a, b, w) = e;
        dist[b] = min(dist[b], dist[a] + w);
    }

    //output
    dfs2(1);
    cout << -dist[n];

    return 0;
}