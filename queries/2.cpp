#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int n, q;
vector <int> arr(n+10);
int tab[200005][100];

int quer(int l, int r){
    int len = r - l + 1;

    int log = 0;
    while((1 << (log + 1)) <= len){
        log++;
    }
 
    return min(tab[l][log], tab[r-(1 << log)+1][log]);
}

int main(){

    //input reading
    cin >> n >> q;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    //sparse table preprocessing
    for(int i = 0; i < n; ++i)
        tab[i][0] = arr[i];
    
    for(int j = 1; (1 << j) <= n; ++j){
        for(int i = 0; i + (1 << j) <= n; ++i){
            tab[i][j] = min(tab[i][j-1], tab[i + (1 << (j-1))][j-1]);
        }
    }

    //computing queries
    for(int i = 0; i < q; ++i){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        cout << quer(tmp1-1, tmp2-1) << '\n';
    }

    return 0;
}