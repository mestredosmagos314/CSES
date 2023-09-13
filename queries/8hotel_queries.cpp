#include <bits/stdc++.h>

#define ll long long
#define NEUTRAL 0

using namespace std;

int n, m;
vector <int> tree;
int ans;

// [node_low, node_high] is the interval the node is resposible for
// [query_low, query_high] is the interval to be queried
void dfs(int node, int val){
    if(node >= n){
        ans = node - n;
        return;
    }
    if(tree[2*node] >= val)
        dfs(2*node, val);
    else
        dfs(2*node + 1, val);
    
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
    tree[node] = max(tree[2*node], tree[2*node + 1]);
}

int main(){
    
    /*READS INPUT*/
    cin >> n >> m;
    vector <int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    vector <int> quer(m);
    for(int i = 0; i < m; ++i){
        cin >> quer[i];
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
        tree[i] = max(tree[2*i], tree[2*i + 1]);
    
    /*COMPUTES QUERIES*/

    //step 1: find the first node in which the group can stay (RMQ + binary search)
    //step 2: update the hotel in which they stayed to hotel - group
    for(int i = 0; i < m; ++i){
        if(tree[1] < quer[i]){
            cout << 0 << endl;
            continue;
        }
        dfs(1, quer[i]);
        cout << ans + 1 << " ";
        update(1, 0, n-1, ans, ans, tree[ans+n] - quer[i]);
    }
    
    return 0;
}