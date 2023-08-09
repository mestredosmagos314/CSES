#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool aux(pair <int, int> a, pair <int, int> b){
    if(a.first != b.first)
        return a < b;
    return b < a;
}

int main(){

    //input
    int n, k;
    cin >> n >> k;

    vector <pair <int, int>> arr;

    for(int i = 0; i < n; ++i){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        arr.push_back({temp2, temp1});
    }

    //processing
    sort(arr.begin(), arr.end());

    multiset <int> set;
    for(int i = 0; i < k; i++){
        set.insert(0);
    }

    int ans = 0;
    for(int i = 0; i < n; ++i){
        auto it = set.lower_bound(arr[i].second);
        if(it == set.begin()){
            if(*it != arr[i].second)
                continue;
        }
        if(it == set.end() || *it != arr[i].second)
            it--;
        ans++;
        set.erase(it);
        set.insert(arr[i].first);
    }

    //output
    cout << ans;

    return 0;
}