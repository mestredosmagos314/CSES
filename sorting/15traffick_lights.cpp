#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    int x, n;
    cin >> x >> n;

    vector <int> arr(n);

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    //processing
    multiset <int> seg;
    set <int> light;

    light.insert(0); light.insert(x);
    seg.insert(x);

    for(int i = 0; i < n; ++i){
        
        light.insert(arr[i]);
        auto it = light.find(arr[i]);

        int curr = *it;
        int min = *(--it); ++it;
        int max = *(++it);

        seg.erase(seg.find(max - min));
        seg.insert(curr - min); seg.insert(max - curr);

        cout << *(--seg.end()) << " ";
    }

    return 0;

}