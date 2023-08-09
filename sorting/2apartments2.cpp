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

    int start = 0;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        while(apt[start] < app[i] - k){
            start++;
            if(start >= m){
                cout << ans;
                return 0;
            }
        }
        if(apt[start] <= app[i] + k){
            ans++;
            start++;
        }
    }

    //output
    cout << ans;

    return 0;
}