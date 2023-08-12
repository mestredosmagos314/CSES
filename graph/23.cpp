#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define INF (int) 1e9 + 10
#define BINF (ll) 1e18 + 10
#define nl '\n'

int n, m;
vector <int> par(n+10);
vector <int> sz(n+10);
int comp, biggest;

int find(int n){
    if(par[n] == n){
        return n;
    }
    return par[n] = find(par[n]);
}

bool join(int n1, int n2){

    int p1 = find(n1);
    int p2 = find(n2);

    if(p1 == p2)
        return false;
    
    if(sz[p1] > sz[p2]){
        par[p2] = p1;
        sz[p1] += sz[p2];
        biggest = max(biggest, sz[p1]);
    }
    else{
        par[p1] = p2;
        sz[p2] += sz[p1];
        biggest = max(biggest, sz[p2]);
    }
    
    return true;

}

int main(){

    //ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        par[i] = i;
        sz[i] = 1;
    }

    comp = n;
    biggest = 1;

    vector <pair <int, int>> sla;

    for(int i = 0; i < m; ++i){
        int tmpa, tmpe;
        cin >> tmpa >> tmpe;
        sla.pb({tmpa, tmpe});
    }

    for(int i = 0; i < m; ++i){
        int tmp1, tmp2;
        tmp1 = sla[i].first;
        tmp2 = sla[i].second;

        bool cond = join(tmp1, tmp2);
        if(cond == false){
            //cout << "ans = ";
            cout << comp << " " << biggest << endl;
        }
        else{
            //cout << "ans = ";
            comp -=  1;
            cout << comp << " " << biggest << endl;
        }
    
    }

    return 0;
}