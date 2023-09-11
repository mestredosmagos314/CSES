#include <bits/stdc++.h>

using namespace std;

int n, q;
vector <int> arr(n+10);

int sum(int k){
    int s = 0;
    while (k >= 1){
        s += arr[k];
        k -= (k & -k);
    }
    return s;
}

void add(int k, int x){
    while(k <= x){
        arr[k] += x;
        k += (k & -k);
    }
}

int main(){

    //reading the array
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        int tmp;
        cin >> tmp;
        add(i, tmp);
    }

    //processing queries
    for(int i = 0; i < q; ++i){
        int opc, tmp1, tmp2;
        cin >> opc >> tmp1 >> tmp2;

        if(opc == 1){
            int var = sum(tmp1) - sum(tmp1 - 1);
            add(tmp1, tmp2);
        }

        if(opc == 2)
            cout << sum(tmp2) - sum(tmp1 - 1) << endl;
    }

    return 0;
}