#include <bits/stdc++.h>

using namespace std;

//DEBUG THIS DOGSHIT 

int main(){

    //input
    int n, m;
    cin >> n >> m;

    unordered_map <int, int> map;
    int arr[200005];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        map[arr[i]] = i;
    }

    vector<pair <int, int>> quer;
    for(int i = 0; i < m; ++i){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        quer.push_back({temp1-1, temp2-1});
    }

    //processing
    unordered_set <int> set;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(set.find(arr[i]-1) == set.end())
            ans++;
        set.insert(arr[i]);
    }

    for(int i = 0; i < m; ++i){
        int a = max(quer[i].first, quer[i].second); //biggest position
        int b = min(quer[i].first, quer[i].second); //smalles position
        // arr[a] -> pos b (diminui de posicao)
        // arr[b] -> pos a (aumentou de posicao)

        bool aAntesMenor;
        bool aAntesMaior;
        if(arr[a] != 1){
            aAntesMenor = a < map[arr[a] - 1];
            if(aAntesMenor){
                if(b > map[arr[a]-1])
                    ans++;
            }
            else{
                if(b < map[arr[a]-1])
                    ans--;
            }
        }
        if(arr[a] != n){
            aAntesMaior = a < map[arr[a] + 1];
            if(aAntesMaior){
                if(b > map[arr[a]+1])
                    ans--;
            }
            else{
                if(b < map[arr[a]+1])
                    ans++;
            }
        }

        bool bAntesMenor;
        bool bAntesMaior;
        if(arr[b] != 1){
            bAntesMenor = b < map[arr[b] - 1];
            if(bAntesMenor){
                if(a > map[arr[b]-1])
                    ans++;
            }
            else{
                if(a < map[arr[b]-1])
                    ans--;
            }
        }
        if(arr[b] != n){
            bAntesMaior = b < map[arr[b] + 1];
            if(bAntesMaior){
                if(a > map[arr[a]+1])
                    ans--;
            }
            else{
                if(b < map[arr[a]+1])
                    ans++;
            }
        }

        map[arr[a]] = b; map[arr[b]] = a;
        swap(arr[a], arr[b]);

        cout << ans << endl;
    }

    return 0;
}