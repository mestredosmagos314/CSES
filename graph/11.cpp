#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mk make_pair
#define INF (int) 1e9
#define BINF (ll) 1e17

using namespace std;

//variables
int n, m;
vector <tuple<int, int, int>> edge;
vector <ll> dist(n+10);

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);

    //input
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        edge.pb({tmp1,tmp2,tmp3});
    }

    //processing
    for(int i = 1; i <= n; ++i){
        dist[i] = INF;
        cout << dist[i] << " ";
    }
    dist[1] = 0;

    for(int i = 1; i <= n-1; ++i){
        for(auto e: edge){
            int a, b, w;
            tie(a, b, w) = e;
            dist[b] = min(dist[b], dist[a] + w);
        }
    }

    //vector <ll> cp(n+10);
    //for(int i = 1; i <= n; ++i){
    //    cout << dist[i] << " ";
    //}
    for(auto e: edge){
            int a, b, w;
            tie(a, b, w) = e;
            dist[b] = min(dist[b], dist[a] + w);
    }

    /*
    for(int i = 1; i <= n; ++i){
        printf("dist[i] = %d, copy[i] = %d\n", dist[i], cp[i]);
        if(dist[i] != cp[i]){
            cout << "YES";
            return 0;
        }
    }
    //output
    cout << "NO";
    */

    return 0;
}