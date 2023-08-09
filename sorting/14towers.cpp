#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    //processing
    multiset <int> set;
    for(int i = 0; i < n; ++i){
        auto it = set.upper_bound(arr[i]);
        if(it != set.end()){
            set.erase(it);
        }
        set.insert(arr[i]);
    }

    //output
    cout << set.size();

    return 0;
}