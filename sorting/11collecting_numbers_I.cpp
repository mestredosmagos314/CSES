#include <bits/stdc++.h>

using namespace std;

int main(){

    //input
    int n;
    cin >> n;

    int arr[200005];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    //processing
    unordered_set <int> set;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(set.find(arr[i]-1) == set.end())
            ans++;
        set.insert(arr[i]);
    }

    //output
    cout << ans;

    return 0;
}