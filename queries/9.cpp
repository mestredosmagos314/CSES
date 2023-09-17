#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define NEUTRAL 0

using namespace std;

int n, q;
vector <ll> tree;
int queries[200005][3];

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

void println(int tam){

    cout << "----------------------" << endl;
    for(int i = tam; i < 2*tam; ++i){
        cout << tree[i] << " ";
    }
    cout << "\n----------------------" << endl;
}

int main(){
    
    /*READS INPUT ARRAY & QUERIES*/
    cin >> n >> q;

    vector <int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    
    for(int i = 0; i < q; ++i){
        char type;
        cin >> type;
        if(type == '!'){
            int employee, x;
            cin >> employee >> x;

            queries[i][0] = 1;
            queries[i][1] = employee-1;
            queries[i][2] = x;
        }
        else if(type == '?'){
            int left, right;
            cin >> left >> right;

            queries[i][0] = 2;
            queries[i][1] = left;
            queries[i][2] = right;
        }
    }

    /*COMPRESSES THE COORDINATES*/
    
    //reads all the used values
    vector <int> coord;
    for(int i = 0; i < n; ++i){
        coord.pb(arr[i]);
    }

    for(int i = 0; i < q; ++i){
        if(queries[i][0] == 1){
            coord.pb(queries[i][2]);
        }
    }

    sort(coord.begin(), coord.end());

    //creates the compressed map
    map <int, int> map;
    int cont = 0;
    for(int i = 0; i < coord.size(); ++i){
        if(map.find(coord[i]) == map.end())
            map[coord[i]] = cont++;
    }

    auto it = map.begin();
    while(it != map.end()){
        
    }

    /*BUILDS THE TREE*/

    //makes the size of the array a power of two
    int tam = map.size(); //sera que map.size() funciona
    while(__builtin_popcount(tam) != 1){
        arr.push_back(NEUTRAL);
        tam++;
    }
    tree.resize(2*tam);
    //fills the indices n to 2*n -1 with the array values
    for(int i = 0; i < n; ++i){
        tree[tam + map[arr[i]]] += 1; 
    }

    //fills the indices n-1 to 1
    for(int i = tam-1; i >= 1; --i)
        tree[i] = tree[2*i] + tree[2*i + 1];
    
    /*COMPUTES QUERIES*/
    println(tam);
    for(int i = 0; i < q; ++i){
        if(queries[i][0] == 1){
            int employee = queries[i][1];
            int old_salary = arr[employee];
            int new_salary = queries[i][2];

            int sub = map[old_salary];
            update(1, 0, tam-1, sub, sub, tree[tam + sub]-1);

            arr[employee] = new_salary;

            int add = map[new_salary];
            update(1, 0, tam-1, add, add, tree[tam + add] + 1);
            println(tam);
        }
        else if(queries[i][0] == 2){
            cout << query(1, 0, tam-1, map[queries[i][1]], map[queries[i][2]]) << '\n';
        }
        
    }
    return 0;
}