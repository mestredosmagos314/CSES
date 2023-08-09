#include <bits/stdc++.h>

using namespace std;

int main(){

    //ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    int n, x;
    cin >> n >> x;

    vector <int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    //processing
    int p1, p2; p1 = p2 = 0;
    long long sum = arr[0];
    int ans = 0;
    while(true){
        if(p1 > p2){
            sum = arr[p1];
            p2 = p1;
            continue;
        }
        if(sum == x){
            ans++;
            sum -= arr[p1];
            p1++;
            p2++;
            if(p2 >= n)
                break;
            sum += arr[p2];
        }
        else if(sum < x){
            p2++;
            if(p2 >= n)
                break;
            sum += arr[p2];
        }
        else{
            sum -= arr[p1];
            p1++;
        }
    }

    //output
    cout << ans;

    return 0;
}