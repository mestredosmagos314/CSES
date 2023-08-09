#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    int n;
    cin >> n;

    vector <long long> arr(n);
    long long sum = 0;
    long long m = 0;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        sum += arr[i];
        m = max(arr[i], m);
    }

    //output
    cout << max(2*m, sum);

    return 0;
}