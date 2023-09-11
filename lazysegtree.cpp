#include <bits/stdc++.h>

using namespace std;

#define n 10000
#define INF (int) 1e9

int low[4*n + 1]; //determines the l (as in [l, r]) of node i
int high[4*n + 1]; //determines the r (as in [l, r]) of node i
int delta[4*n + 1]; //determines the increment to a certain subtree
int value[4*n + 1]; //determines the value of the node (can be any operation)

//l = left; r = right;
void init(int node, int l, int r){
    low[node] = l;
    high[node] = r;

    //node is a leaf, so it has no children
    if(l == r)
        return;

    int mid = (l+r)/2;
    init(2*node, l, mid); //initializes the left child
    init(2*node + 1, mid+1, r); //initializes the right child
}

//pushes the change down to children
void prop(int node){
    //make sure to not pass leaves to prop!!
    delta[2*node] += delta[node];
    delta[2*node + 1] += delta[node];
    delta[node] = 0;
}
//updates the value of node on the segment tree. could be RMQ, range sum, etc...
void update(int node){
    //value[node] = value[2*node] + delta[2*node] + value[2*node+1] + delta[2*node+1]; //SUM
    value[node] = min(value[2*node] + delta[2*node], value[2*node + 1] + delta[2*node+1]); //RMQ
}

void increment(int node, int l, int r, int val){
    //disjoint ranges case
    if(l > high[node] || r < low[node])
        return;
    //complete cover case
    if(low[node] >= l && high[node] <= r){
        delta[node] += val;
        return;
    }
    //partical cover case
    prop(node);
    increment(2*node, l, r, val);
    increment(2*node+1, l, r, val);
    update(node);
}

int querie(int node, int l, int r){
    //disjoint ranges case
    if(l > high[node] || r < low[node])
        return INF;
    //complete cover case
    if(low[node] >= l && high[node] <= r){
        return value[node] + delta[node];
    }

    prop(node);
    int minL = querie(2*node, l, r);
    int minR = querie(2*node+1, l, r);
    update(node);

    return min(minL, minR);
}

int main(){

    //initializes a n-lenght array;
    init(1, 0, n-1);
    

    return 0;
}