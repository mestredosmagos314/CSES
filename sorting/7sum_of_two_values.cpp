#include <bits/stdc++.h>
 
using namespace std;
 
//this shit does work (not TLE)
 
int main(){
 
    //input
    int n, x;
    cin >> n >> x;
 
    vector <int> arr(200005);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
 
    //processing
    set <int> set;
    map <int, int> map;
    for(int i = 0; i < n; ++i){
        if(set.find(x - arr[i]) != set.end()){
            cout << map[x - arr[i]] + 1 << " " << i+1;
            return 0;
        }
        set.insert(arr[i]);
        map[arr[i]] = i;
    }
 
    //output
    cout << "IMPOSSIBLE";
 
    return 0;
}