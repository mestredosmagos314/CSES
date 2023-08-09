#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    //input
    int n, k;
    cin >> n >> k;

    int arr[200005];

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    //processing
    map <int, int> map;

    int p1, p2;
    p1 = p2 = 0;
    
    map[arr[p1]] = 1;
    ll ans = 1;
    int rep = 0;
    while(p2 < n-1){
        p2++;
        rep += arr[p2];
        map[arr[p2]] += 1;
        while(rep > k){

        }
    }

    cout << ans;

    return 0;
}