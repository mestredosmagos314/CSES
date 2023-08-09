#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    ll n, k;
    cin >> n >> k;

    vector <ll> arr(n);
    ll sum = 0;
    for(int i =0; i < n; ++i){
        cin >> arr[i];
        sum += arr[i];
    }

    //processing
    ll l = 0; 
    ll r = sum;
    ll mid;
    ll ans;
    while(l <= r){
        mid = l + (r-l)/2;
        
        ll curr = 0;
        ll qtd = 1;
        for(int i = 0; i < n; ++i){
            if(curr + arr[i] <= mid){
                curr += arr[i];
            }
            else{
                if(arr[i] <= mid){
                    curr = arr[i];
                    qtd += 1;
                }
                else{
                    qtd = k + 10;
                    break;
                }
            }
        }
        if(qtd <= k){
            r = mid - 1;
            ans = mid;
        }
        else{
            l = mid + 1;
        }
    }

    //output
    cout << ans;

    return 0;
}