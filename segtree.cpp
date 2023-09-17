#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define NEUTRAL 0

using namespace std;

int n;
vector <int> tree;
vector <int> delta;

void recurrence(int node){
    tree[node] = min(tree[2*node] + delta[2*node], tree[2*node+1] + delta[2*node+1]);
}

void propagate(int node){
    delta[2*node] += delta[node];
    delta[2*node+1] += delta[node];
    delta[node] = 0;
}

ll query(int node, int node_left, int node_right, int query_left, int query_right){
//case 1: disjoint intervals
    if(node_left > query_right || node_right < query_left){
        return NEUTRAL;
    }

    //case 2: complete cover
    if(node_left >= query_left && node_right <= query_right){
        return tree[node] + delta[node];
    }

    //case 3: partial cover

    int last_in_left = (node_left + node_right)/2;
    int first_in_right = last_in_left + 1;

    query(2*node, node_left, last_in_left, query_left, query_right);
    query(2*node+1, first_in_right, node_right, query_left, query_right);

    recurrence(node);
    return tree[node];  
}

void update(int node, int node_left, int node_right, int query_left, int query_right, int val){
    //case 1: disjoint intervals
    if(node_left > query_right || node_right < query_left){
        return;
    }

    //case 2: complete cover
    if(node_left >= query_left && node_right <= query_right){
        delta[node] += val;
    }

    //case 3: partial cover
    propagate(node);

    int last_in_left = (node_left + node_right)/2;
    int first_in_right = last_in_left + 1;

    update(2*node, node_left, last_in_left, query_left, query_right, val);
    update(2*node+1, first_in_right, node_right, query_left, query_right, val);

    recurrence(node);
}

int main(){

    /*READS THE INPUT ARRAY*/
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    /*COMPUTES THE TREE*/

    //makes n a power of 2
    while(__builtin_popcount(n) != 1){
        n++;
        arr.pb(NEUTRAL);
    }

    tree.resize(2*n);
    delta.resize(2*n);

    //initializes tree[n] to tree[2*n-1]
    for(int i = 0; i < n; ++i){
        tree[n+i] = arr[i];
    }

    //initializes tree[1] to tree[n-1]
    for(int i = n-1; i >= 1; --i){
        recurrence(i);
    }

    return 0;
}