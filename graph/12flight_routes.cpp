#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mk make_pair
#define nl '\n'
#define INF (int) 1e9
#define BINF (ll) 1e18

using namespace std;

//variables
int n, m, k;
vector <pair <int, int>> adj[100005];
ll dist[100005][10]; //dist[i][0] = distancia de 1 a i sem usar uma desconto. dist[i][1] = distancia de 1 a i usando desconto
bool vis[100005][10];
int pos[100005]; //pos indica a primeira posicao que ainda nao foi marcada como visitada

int main(){

    //ios::sync_with_stdio(false); cin.tie(nullptr);

    //input
    cin >> n >> m >> k;

    for(int i = 0; i < m; ++i){
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        adj[tmp1].pb(mk(tmp2, tmp3));
    }
    
    //processing
    for(int i = 0; i < 10; ++i)
        dist[1][i] = 0;

    for(int i = 1; i <= n; ++i){
        pos[i] = 0;
        for(int j = 0; j < 10; ++j){
            dist[i][j] = BINF;
            vis[i][j] = false;
        }
    } //initializization

    priority_queue <pair <ll, ll>> pq;
    pq.push({0,1}); //initialize priority queue
    
    //dont compute repeated paths (OK)
    //compute all paths (OK)
    while(!pq.empty()){
        //dijkstras part 1
        int curr;
        ll ds;
        do{
            if(pq.empty())
                break;
            ds = -pq.top().first;
            curr = pq.top().second;
            pq.pop();
        }while(vis[curr][9]);

        vis[curr][pos[curr]] = true;
        dist[curr][pos[curr]] = ds;

        //dijkstras part 2
        for(int i = 0; i < adj[curr].size(); ++i){
            int viz = adj[curr][i].first;
            int w = adj[curr][i].second;

            if(pos[viz] < k)//<= ou < ?
                pq.push({-(dist[curr][pos[curr]] + w), viz});
            }
        pos[curr]++;
    }

    //output
    for(int i = 0; i < k; ++i){
        cout << dist[n][i] << " ";
    }

    return 0;
}