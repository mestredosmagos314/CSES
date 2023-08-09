#include <bits/stdc++.h>
#define ll long long

using namespace std;

void printl(multiset <int> a){
    auto cu = a.begin();
    while(cu != a.end()){
        cout << *cu << " ";
        cu++;
    }
    cout << endl;
}

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    int n, k;
    cin >> n >> k;

    vector <int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    multiset <int> set;
    for(int i = 0; i < k; ++i){
        set.insert(arr[i]);
    }

    vector <int> ans(n);
    auto it = set.begin(); 
    for(int i = 1; i < (k + (k%2))/2; ++i){
        it++;
    }
    ans[0] = *it;

    for(int i = k; i < n; i++){
        int rem = arr[i-k];
        int add = arr[i];

        int mid = ans[i-k];
        set.insert(add);
        if(add >= mid){
            if(k % 2 == 0){
                it++;
            }
        }
        else{
            if(k % 2 == 1){
                it--;
            }
        }
        auto bc = set.find(rem);

        if(rem > *it){
            if((k + 1) % 2 == 1){{
                it--;
            }
        }
        else if(bc == it){
            if((k + 1) % 2 == 0){
                it++;
            }
            else{
                it--;
            }
        }
        else{
            if((k + 1) % 2 == 0){
                it++;
            }
        }
        set.erase(bc);

        ans[i - k + 1] = *it;
    }

    //output
    for(int i = 0; i < n - k + 1; ++i){
        cout << ans[i] << " ";
    }

    return 0;
}