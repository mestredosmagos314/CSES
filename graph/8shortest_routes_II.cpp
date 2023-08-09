#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mk make_pair
#define INF (int) 1e9
#define bINF (int) 1e17
#define nl '\n'

using namespace std;

int n, m, q;
ll dist[505][505];

int main(){

    //ios::sync_with_stdio(false); cin.tie(nullptr);

    //input
    cin >> n >> m >> q;

    memset(dist, -1, sizeof(dist));

    for(int i = 0; i < m; ++i){
        ll tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        if(dist[tmp1][tmp2] == -1)
            dist[tmp1][tmp2] =  dist[tmp2][tmp1] = tmp3;
        else
            dist[tmp1][tmp2] = dist[tmp2][tmp1] = min(dist[tmp1][tmp2], tmp3);
    }

    //processing
    
    for(int i = 1; i <= n; ++i){
        dist[i][i] = 0;
    }
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(dist[i][k] == -1 || dist[k][j] == -1)
                    continue;
                if(dist[i][j] == -1){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
                else
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    //output
    for(int i = 0; i < q; ++i){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        cout << dist[tmp1][tmp2] << nl;
    }
    return 0;
}