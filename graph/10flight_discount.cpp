#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mk make_pair
#define nl '\n'
#define INF (ll) 1e18

using namespace std;

//variables
int n, m;
vector <pair <int, int>> adj[100005];
ll dist[100005][2]; //dist[i][0] = distancia de 1 a i sem usar uma desconto. dist[i][1] = distancia de 1 a i usando desconto
bool vis[100005][2];

int main(){

    //ios::sync_with_stdio(false); cin.tie(nullptr);

    //input
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        adj[tmp1].pb(mk(tmp2, tmp3));
    }
    
    //processing
    for(int i = 1; i <= n; ++i){
        vis[i][0] = vis[i][1] = false;
    } //initialize visited array

    for(int i = 1; i <= n; ++i){ //initialize distance array
        dist[i][0] = dist[i][1] = INF;
    }
    dist[1][0] = dist[1][1] = 0;

    priority_queue <pair <pair<ll, int>, int>> pq;
    pq.push({{0,1},0}); //initialize priority queue
    
    while(!pq.empty()){
        //dijkstras part 1
        //printf("foo = %d:\n", foo);
        int curr, mode;
        do{
            curr = pq.top().first.second;
            mode = pq.top().second;
            //printf("curr = %d, mode = %d; ", curr, mode);
            pq.pop();
            if(pq.empty())
                break;
        }while(vis[curr][mode]);
        vis[curr][mode] = true;

        //dijkstras part 2
        for(int i = 0; i < adj[curr].size(); ++i){
            int viz = adj[curr][i].first;
            int w = adj[curr][i].second;

            //case 1 (not using the ticket)
            if(mode == 0){
                if(dist[viz][0] > dist[curr][0] + w){
                    dist[viz][0] = dist[curr][0] + w;
                    pq.push({{-dist[viz][0], viz}, 0});
                }
                if(dist[viz][1] > dist[curr][0] + w/2){
                    dist[viz][1] = dist[curr][0] + w/2;
                    pq.push({{-dist[viz][1], viz}, 1});
                }
            }
            //case 2 (using the ticket)
            else{
                if(dist[viz][1] > dist[curr][1] + w){
                    dist[viz][1] = dist[curr][1] + w;
                    pq.push({{-dist[viz][1], viz}, 1});
                }
            }
        }
    }

    //output
    cout << dist[n][1];

    return 0;
}