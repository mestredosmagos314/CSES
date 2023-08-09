#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    int arr[200005];

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int last = -1;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] != last)
            ans++;
        last = arr[i];
    }

    cout << ans;

    return 0;
}