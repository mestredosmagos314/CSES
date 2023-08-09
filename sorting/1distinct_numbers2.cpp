#include <bits/stdc++.h>

using namespace std;

int main(){

    long long n, temp;
    cin >> n;

    set <long long> arr;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        arr.insert(temp);
    }

    cout << arr.size();

    return 0;
}