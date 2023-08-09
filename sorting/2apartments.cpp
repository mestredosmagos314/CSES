#include <bits/stdc++.h>

using namespace std;

int main(){

    //input
    int n, m, k;
    cin >> n >> m >> k;

    int app[200005];
    for(int i = 0; i < n; i++){
        cin >> app[i];
    }

    int apt[200005];
    for(int i = 0; i < m; i++){
        cin >> apt[i];
    }

    //processing
    sort(app, app + n); 
    sort(apt, apt + m);

    int ans = 0;
    int temp = -1;
    for(int i = 0; i < n; i++){
        if(app[i] - k > apt[m-1])
            break;

        int pos = lower_bound(apt + temp + 1, apt + m, app[i] - k) - apt;
        if(apt[pos] <= app[i] + k){
            ans++;
            temp = pos;
            if(temp + 1 >= m)
                break;
        }
    }

    //output
    cout << ans;

    return 0;
}