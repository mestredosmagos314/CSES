#include <bits/stdc++.h>

#define ll long long
#define NEUTRAL 0

using namespace std;

int n, q;
vector <ll> tree;

// [node_low, node_high] is the interval the node is resposible for
// [query_low, query_high] is the interval to be queried
ll query(int node, int node_low, int node_high, int query_low, int query_high){
    /*node is completely within [query_low , query_high]*/
    if(query_low <= node_low && query_high >= node_high)
        return tree[node];
    /*node is disjoint from [query_low, query_high]*/
    if(node_high < query_low || query_high < node_low)
        return NEUTRAL;
    
    int last_in_left = (node_low + node_high)/2;
    int first_in_right = last_in_left + 1;
    return query(2*node, node_low, last_in_left, query_low, query_high)
         + query(2*node + 1, first_in_right, node_high, query_low, query_high);
}

void update(int node, int node_low, int node_high, int query_low, int query_high, int val){
    if(query_low <= node_low && query_high >= node_high){
        tree[node] = val;
        return;
    }
    if(node_high < query_low || query_high < node_low)
        return;
    
    int last_in_left = (node_low + node_high)/2;
    int first_in_right = last_in_left + 1;
    update(2*node, node_low, last_in_left, query_low, query_high, val);
    update(2*node + 1, first_in_right, node_high, query_low, query_high, val);
    tree[node] = tree[2*node] + tree[2*node + 1];
}

int main(){
    
    /*READS INPUT*/
    cin >> n >> q;
    vector <int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    //makes lenght of the array a power of 2
    while(__builtin_popcount(n) != 1){
        arr.push_back(NEUTRAL);
        n++;
    }

    /*BUILDS THE TREE*/
    tree.resize(2*n);
    //fills the indices n to 2*n -1 with the array values
    for(int i = 0; i < n; ++i)
        tree[n+i] = arr[i]; 

    //fills the indices n-1 to 1
    for(int i = n-1; i >= 1; --i)
        tree[i] = tree[2*i] + tree[2*i + 1];
    
    /*COMPUTES QUERIES*/
    for(int i = 0; i < q; ++i){
        int type, tmp1, tmp2;
        cin >> type >> tmp1 >> tmp2;
        tmp1--;
        if(type == 1){
            update(1, 0, n-1, tmp1, tmp1, tmp2);
        }
        else{
            tmp2--;
            cout << query(1, 0, n-1, tmp1, tmp2) << '\n';
        }
    }
    return 0;
}