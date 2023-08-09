#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    int n;
    cin >> n;

    vector <pair <int, int>> arr;
    for(int i = 0; i < n; ++i){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        arr.push_back({temp1, temp2});
    }

    //processing

    vector <pair <int, int>> st = arr;
    sort(st.begin(), st.end());

    vector <int> suf(n);
    vector <int> pref(n);

    pref[0] = st[0].second;
    for(int i = 1; i < n; ++i){
        pref[i] = max(pref[i-1], st[i].second);
    }

    suf[n-1] = st[n-1].second;
    for(int i = n-2; i >= 0; --i){
        suf[i] = min(suf[i+1], st[i].second);
    }

    vector <bool> contido(n);
    vector <bool> contem(n);
    for(int i = 0; i < n; ++i){
        int id = lower_bound(st.begin(), st.end(), arr[i]) - st.begin(); //DOES THIS SHIT WORK

        if(id < n-1 && suf[id+1] <= arr[i].second){
            contem[i] = 1;
        }
        else{
            if(id > 0 && st[id-1].first == arr[i].first)
                contem[i] = 1;
            else
                contem[i] = 0;
        }

        if(id > 0 && pref[id-1] >= arr[i].second){
            contido[i] = 1;
        }
        else{
            if(id < n-1 && st[id+1].first == arr[i].first)
                contido[i] = 1;
            else
                contido[i] = 0;
        }
    }

    //output
    for(int i = 0; i < n; ++i){
        cout << contem[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; ++i){
        cout << contido[i] << " ";
    }

    return 0;
}