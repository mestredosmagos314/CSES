#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int n, q;
vector <ll> tree;

ll query(int node){
    if(node == 1)
        return tree[node];
    return query(node/2) + tree[node];
}

void update(int node, int node_low, int node_high, int query_low, int query_high, int val){
    //case 1: disjoint intervals
    if(node_low > query_high || node_high < query_low){
        return;
    }

    //case 2: [node_low, node_high] is a subset of [query_low, query_high]
    if(node_low >= query_low && node_high <= query_high){
        tree[node] += val;
        return;
    }

    //case 3: none of the above
    int last_in_left = (node_low + node_high)/2;
    int first_in_right = last_in_left + 1;

    update(2*node, node_low, last_in_left, query_low, query_high, val);
    update(2*node + 1, first_in_right, node_high, query_low, query_high, val);
}

int main(){

    /*READS THE ARRAY*/
    cin >> n >> q;
    vector <int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    /*INITIALIZES THE SEGTREE*/
    while(__builtin_popcount(n) != 1){
        n++;
        arr.pb(0);
    }

    tree.resize(2*n);
    for(int i = 0; i < n; ++i){
        tree[n + i] = arr[i];
    }

    /*READS & COMPUTES QUERIES*/
    for(int i = 0; i < q; ++i){
        int type;
        cin >> type;

        if(type == 1){
            int low, high, val;
            cin >> low >> high >> val;
            update(1, 0, n-1, low-1, high-1, val);
        }
        else{
            int node;
            cin >> node;
            cout << query(n + node-1) << endl;    
        }
    }

    return 0;
}