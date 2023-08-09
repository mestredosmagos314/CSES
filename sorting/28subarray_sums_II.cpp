#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    int n, x;
    cin >> n >> x;

    vector <int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    //processing
    map <long long, long long> prefix; //map instead of multiset (gigantic brain move)
    prefix[0] = 1;
    long long sum = 0;
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        sum += arr[i];
        ans += prefix[sum - x];
        prefix[sum] += 1;
    }

    //output
    cout << ans;

    return 0;
}