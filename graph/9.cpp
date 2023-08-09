#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mk make_pair
#define mt make_tuple
#define nl '\n'

using namespace std;

//variables
int n, m;
vector <tuple<int, int, int>> adj;

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    //input
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        ll tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        adj.pb(mt(tmp1, tmp2, -tmp3));
        adj.pb(mt(tmp2, tmp1, -tmp3));
    }

    //processing

    //output

    return 0;
}