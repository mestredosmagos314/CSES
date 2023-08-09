#include <bits/stdc++.h>

using namespace std;

int main(){

    //input
    int n;
    cin >> n;

    vector <pair <int, int>> arr;

    for(int i = 0; i < n; ++i){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        arr.push_back({temp2, temp1});
    }

    //processing
    sort(arr.begin(), arr.end());

    int time, ans;
    time = ans = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i].second >= time){
            ans++;
            time = arr[i].first;
        }
    }

    //output
    cout << ans;

    return 0;
}