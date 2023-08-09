#include <bits/stdc++.h>

using namespace std;

int main(){

    //ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    //processing
    vector <long long> prefix(n);
    for(int i = 0; i < n; ++i){
        prefix[i] = 0;
    }
    prefix[0] = 1;

    long long curr = 0;
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        curr = (curr + arr[i]) % n;
        if(curr < 0)
            curr += n;
        ans += prefix[curr];
        prefix[curr] += 1;
    }

    //output
    cout << ans;

    return 0;
}