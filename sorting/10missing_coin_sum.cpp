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
    sort(arr, arr + n);
    if(arr[0] > 1){
        cout << 1;
        return 0;
    }

    long long sum = 1;
    for(int i = 1; i < n; ++i){
       if(arr[i] > sum + 1){
            cout << sum + 1;
            return 0;
       }
       sum += arr[i]; 
    }
    cout << sum + 1;

    return 0;
}