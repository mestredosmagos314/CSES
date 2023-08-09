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
    set <int> set;

    int p1;
    int p2;
    p1 = p2 = 0;

    set.insert(arr[0]); //VAI TOMAR NO CU

    int curr, ans;
    curr = ans = 1;
    while(p2 < n - 1){
        ++p2;
        ++curr;
        if(set.count(arr[p2]) > 0){
            while(true){
                set.erase(arr[p1]);
                ++p1;
                --curr;
                if(arr[p1 -1] == arr[p2])
                    break;
            }
        }
        set.insert(arr[p2]);
        ans = max(ans, curr);
    }

    //output
    cout << ans;

    return 0;
}