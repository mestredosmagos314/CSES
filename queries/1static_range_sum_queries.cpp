#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int n, q;
vector <int> arr(200005);
vector <ll> pref(200005);

int main(){

    //input
    cin >> n >> q;

    pref[0] = 0;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        pref[i+1] = pref[i] + arr[i];
    }

    //processing
    for(int i = 0; i < q; ++i){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        tmp1--;
        tmp2--;
        cout << pref[tmp2 + 1] - pref[tmp1] << endl;
    }

    //output

    return 0;
}