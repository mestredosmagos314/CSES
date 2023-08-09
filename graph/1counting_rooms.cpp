#include <bits/stdc++.h>
#define ll long long
#define INF (int) 1e9

using namespace std;

int n, m;
bool arr[1005][1005];

void dfs(int a, int b){
    arr[a][b] = true;

    if(a + 1 < n){
        if(!arr[a+1][b])
            dfs(a+1, b);
    }
    if(a - 1 >= 0){
        if(!arr[a-1][b])
            dfs(a-1, b);
    }
    if(b + 1 < m){
        if(!arr[a][b+1])
            dfs(a, b+1);
    }
    if(b - 1 >= 0){
        if(!arr[a][b-1])
            dfs(a, b-1);
    }
}

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    //input

    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            char temp;
            cin >> temp;
            if(temp == '#'){
                arr[i][j] = true;
            }
            else{
                arr[i][j] = false;
            }
        }
    }

    //processing
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!arr[i][j]){
                ans++;
                dfs(i, j);
            }
        }
    }

    //output
    cout << ans;

    return 0;
}