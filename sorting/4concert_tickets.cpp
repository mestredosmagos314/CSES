#include <bits/stdc++.h>

using namespace std;

int main(){

    //input
    int n, m;
    cin >> n >> m;

    multiset <int> set;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        set.insert(temp);
    }

    vector <int> prs(200005);
    for(int i = 0; i < m; i++){
        cin >> prs[i];
    }

    //processing
    bool cond = false;
    vector <int> ans(200005);
    for(int i = 0; i < m; i++){
        auto it = set.upper_bound(prs[i]);
        if(cond || it == set.begin())
            ans[i] = -1;
        else{
            --it;
            ans[i] = *it;
            set.erase(it);
            if(set.size() == 0){
                cond = true;
            }
        }
    }

    //output
    for(int i = 0; i < m; ++i){
        cout << ans[i] << endl;
    }

    return 0;
}