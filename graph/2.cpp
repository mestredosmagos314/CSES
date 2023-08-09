#include <bits/stdc++.h>
#define ll long long
#define INF (int) 1e9

using namespace std;

int n, m;
pair <int, int> start, finish;
bool arr[1005][1005];

int main(){

    //ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            char temp;
            cin >> temp;
            if(temp == '#'){
                arr[i][j] = false;
            }
            else{
                arr[i][j] = true;
                if(temp == 'A')
                    start = make_pair(i, j);
                else if(temp == 'B')
                    finish = make_pair(i, j);
            }
        }
    }

    //processing
    pair <int, int> prev[1005][1005];
    prev[start.first][start.second] = start;
    
    queue <pair <int, int>> q;
    q.push(start);

    while(!q.empty()){
        pair <int, int> curr = q.front();
        q.pop();

    }

    return 0;
}