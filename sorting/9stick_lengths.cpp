#include <bits/stdc++.h>

using namespace std;

int abs(int x){
    if(x >= 0)
        return x;
    return -x;
}

int main(){

    //input
    int n;
    cin >> n;

    int arr[200005];

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    //processing
    sort(arr, arr + n);

    int x;
    if(n % 2 == 1)
        x = arr[(n-1)/2];
    else
        x = arr[n/2 - 1];

    long long ans = 0;
    for(int i = 0; i < n; ++i){
        ans += abs(arr[i] - x);
    }

    cout << ans;

    return 0;
}