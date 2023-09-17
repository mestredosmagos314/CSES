#include <bits/stdc++.h>

#define ll long long
#define NEUTRAL 0

using namespace std;

int n, q;
ll tree[900005][4];

// [node_low, node_high] is the interval the node is resposible for
// [query_low, query_high] is the interval to be queried
void aux(int i){
    tree[i][0] = tree[2*i][0] + tree[2*i + 1][0];
    tree[i][1] = max( max(tree[2*i][1], tree[2*i+1][1]), tree[2*i][3] + tree[2*i+1][2] );
    tree[i][2] = max(tree[2*i][2], tree[2*i][0] + tree[2*i+1][2]);
    tree[i][3] = max(tree[2*i+1][3], tree[2*i+1][0] + tree[2*i][3]);
}

void update(int node, int node_low, int node_high, int query_low, int query_high, int val){
    if(query_low <= node_low && query_high >= node_high){
        for(int i = 0; i < 4; ++i)
            tree[node][i] = val;
        return;
    }
    if(node_high < query_low || query_high < node_low)
        return;
    
    int last_in_left = (node_low + node_high)/2;
    int first_in_right = last_in_left + 1;

    update(2*node, node_low, last_in_left, query_low, query_high, val);
    update(2*node + 1, first_in_right, node_high, query_low, query_high, val);

    aux(node);
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

    //fills the indices n to 2*n -1 with the array values
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 4; ++j)
            tree[n+i][j] = arr[i];
    }

    //fills the indices n-1 to 1
    for(int i = n-1; i >= 1; --i){
        aux(i);
    }
    
    /*COMPUTES QUERIES*/
    for(int i = 0; i < q; ++i){
        int node, val;
        cin >> node >> val;

        update(1, 0, n-1, node-1, node-1, val);
        cout << max(tree[1][1], (ll) 0) << '\n';
    }

    return 0;
}