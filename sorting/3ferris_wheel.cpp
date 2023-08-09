#include <bits/stdc++.h>

using namespace std;

int main(){

    //input
    int n, x;
    cin >> n >> x;

    int arr[200005];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //processing
    sort(arr, arr + n);

    int ptr1 = 0; int ptr2 = n-1;
    int ans = 0;
    while(ptr2 >= ptr1){
        if(ptr1 == ptr2){
            ans++;
            break;
        }
        if(arr[ptr1] + arr[ptr2] <= x){
            ptr1++;
            ptr2--;
            ans++;
        }
        else{
            ptr2--;
            ans++;
        }
    }
    //output
    cout << ans;

    return 0;
}