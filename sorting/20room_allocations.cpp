#include <bits/stdc++.h>

using namespace std;

bool aux(pair <int, int> a, pair <int, int> b){
    if(a.first != a.second){
        return a < b;
    }
    return b.second < a.second;
}

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    //input
    int n;
    cin >> n;

    vector <pair <int, int>> arr(n);
    for(int i = 0; i < n; ++i){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        arr[i] = {temp1, temp2};
    }

    //processing
    vector <pair <int, int>> copia = arr; 
    vector <int> pos(n); //o indice do copia[i] em arr vai ser guardado em pos[i]

    vector <bool> visitado(n);
    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; ++i){
        int suicidio = lower_bound(arr.begin(), arr.end(), copia[i]) - arr.begin();
        while(visitado[suicidio])
            suicidio++;
        visitado[suicidio] = true;
        pos[i] = suicidio;
    }

    vector <int> ans(n);

    priority_queue <pair <int, int>> pq;
    int curr = 1;

    for(int i = 0; i < n; ++i){
        if(pq.empty()){
            pq.push({-arr[i].second, curr});
            ans[i] = curr;
            curr++;
            continue;
        }
        if(-pq.top().first < arr[i].first){
            pair <int, int> temp = pq.top();
            pq.pop();
            ans[i] = temp.second;
            pq.push({-arr[i].second, temp.second});
        }
        else{
            pq.push({-arr[i].second, curr});
            ans[i] = curr;
            curr++;
        }
    }

    //output
    cout << curr - 1 << endl; //off by one?

    for(int i = 0; i < n; ++i){
        cout << ans[pos[i]] << " ";
    }

    return 0;
}