#include <bits/stdc++.h>

using namespace std;

//CRINGE UNSIGNED LONG LONG (LOL)

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);
    
    //input
    unsigned long long n, k;
    cin >> n >> k;

    unsigned long long cu = -1;
    vector <unsigned long long> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        cu = max(cu, arr[i]);
    }

    //output
    unsigned long long bound = k*cu; //rever essa bound

    unsigned long long ans;
    unsigned long long l = 0; unsigned long long r = bound;
    while(l <= r){
        unsigned long long m = l + (r-l)/2;

        unsigned long long tmp = 0;
        for(int i = 0; i < n; ++i){
            tmp += m/arr[i];
        }

        if(tmp < k)
            l = m + 1;
        else{
            r = m - 1;
            ans = m;
        }

    }
    //output
    cout << ans;

    return 0;
}