#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    int n;
    cin >> n;

    vector <pair <int, int>> arr(n);
    for(int i = 0; i < n; ++i){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        arr[i] = {temp1, temp2};
    }

    //processing
    sort(arr.begin(), arr.end());

    long long time = 0;
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        time += arr[i].first;
        ans += arr[i].second - time;
    }

    //output
    cout << ans;

    return 0;
}