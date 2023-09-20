#include <bits/stdc++.h>

#define pb push_back
#define ll long long
#define INF (ll) 1e17

using namespace std;

vector <ll> tree;
vector <ll> delta;

void propagate(int node){
    delta[2*node] += delta[node];
    delta[2*node+1] += delta[node];
    delta[node] = 0;
}

ll query(int node, int node_left, int node_right, int query_left, int query_right){
    if(query_left > node_right || query_right < node_left){
        return -INF;
    }

    if(query_left <= node_left && query_right >= node_right){
        return tree[node] + delta[node];
    }

    propagate(node);
    tree[node] = max(tree[2*node] + delta[2*node], tree[2*node+1] + delta[2*node+1]);

    int last_in_left = (node_left + node_right)/2;
    int first_in_right = last_in_left + 1;

    return max(query(2*node, node_left, last_in_left, query_left, query_right), 
               query(2*node+1, first_in_right, node_right, query_left, query_right));

}

void update(int node, int node_left, int node_right, int query_left, int query_right, int val){
    if(query_left > node_right || query_right < node_left){
        return;
    }

    if(query_left <= node_left && query_right >= node_right){
        delta[node] += val;
        return;
    }

    propagate(node);

    int last_in_left = (node_left + node_right)/2;
    int first_in_right = last_in_left + 1;

    update(2*node, node_left, last_in_left, query_left, query_right, val), 
    update(2*node+1, first_in_right, node_right, query_left, query_right, val);

    tree[node] = max(tree[2*node] + delta[2*node], tree[2*node+1] + delta[2*node+1]);
}