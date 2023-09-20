#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define pb push_back
#define INF (ll) 1e18
 
int n, q;
vector <ll> tree;
vector <ll> delta;
 
void propagate(int node){
	delta[2*node] += delta[node];
	delta[2*node+1] += delta[node];
	delta[node] = 0;
}
 
ll query(int node, int node_left, int node_right, int query_left, int query_right){
	//case 1: disjoint intervals
	if(query_right < node_left || query_left > node_right){
		return -INF;
	}
	//case 2: [node_left, node_right] is a subset of [query_left, query_right]
	if(node_left >= query_left && node_right <= query_right){
		return tree[node] + delta[node]; //real(node);
	}
	//case 3: partial cover
	int last_in_left = (node_left + node_right)/2;
	int first_in_right = last_in_left + 1;
 
	//lazy propagation
	propagate(node);
	tree[node] = max(tree[2*node] + delta[2*node], tree[2*node+1] + delta[2*node+1]); //compute(node);
 
	return max(query(2*node, node_left, last_in_left, query_left, query_right),
	 		   query(2*node + 1, first_in_right, node_right, query_left, query_right));
}
 
//update should be increment
void update(int node, int node_left, int node_right, int query_left, int query_right, int val){
    //case 1: disjoint intervals
    if(query_right < node_left || query_left > node_right){
        return;
    }
    //case 2: [node_left, node_right] is a subset of [query_left, query_right]
    if(node_left >= query_left && node_right <= query_right){
        delta[node] += val; //there should be a function for this big boy
		return;
    }   
    //case 3: partial cover
 
    int last_in_left = (node_left + node_right)/2;
    int first_in_right = last_in_left + 1;
 
	//lazy propagation
	propagate(node);
 
    update(2*node, node_left, last_in_left, query_left, query_right, val);
 	update(2*node + 1, first_in_right, node_right, query_left, query_right, val);
	
	tree[node] = max(tree[2*node] + delta[2*node], tree[2*node+1] + delta[2*node+1]);
}
int main(){
 
	/*READS INPUT*/
 
	//reads the normal array
	cin >> n >> q;
	vector <ll> tmp(n);
	for(int i = 0; i < n; ++i){
		cin >> tmp[i];
	}
 
	//calculates the prefix sum array
	vector <ll> arr(n); 
	arr[0] = tmp[0];
	for(int i = 1; i < n; ++i){
		arr[i] = arr[i-1] + tmp[i];
	}
 
	/*BUILDS THE SEGMENT TREE*/
	
	//makes n a power of 2
	while(__builtin_popcount(n) != 1){
		n++;
		arr.pb(-INF);
	}
 
	tree.resize(2*n);
	delta.resize(2*n);
 
	//populates tree[n] to tree[2*n - 1]
	for(int i = 0; i < n; ++i){
		tree[n+i] = arr[i];
	}
	
	//populates tree[n-1] to tree[1]
	for(int i = n-1; i >= 1; --i){
		tree[i] = max(tree[2*i], tree[2*i + 1]);
	}
 
	/*COMPUTES QUERIES*/
	for(int i = 0; i < q; ++i){
		int type;
		cin >> type;
		
		if(type == 1){
			ll node, upd;
			cin >> node >> upd;
			node--;
 
			update(1, 0, n-1, node, n-1, upd - tmp[node]);
			tmp[node] = upd;
		}
		else{
			ll left, right;
			cin >> left >> right;
			left--; 
			right--;
 
			ll sla = 0;
			if(left != 0){
				sla = query(1, 0, n-1, left-1, left-1);
			}
 
			cout << max((ll) 0,  query(1, 0, n-1, left, right) - sla)  << endl;
		}
	}
	
	return 0;
}