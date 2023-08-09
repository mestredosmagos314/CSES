#include <bits/stdc++.h>

using namespace std;

int main(){

    //input
    int n;
    cin >> n;

    vector <int> start;
    vector <int> endd;
    int temp1, temp2;
    for(int i = 0; i < n; ++i){
        cin >> temp1 >> temp2;
        start.push_back(temp1);
        endd.push_back(temp2);
    }

    //processing
    sort(start.begin(), start.end());
    sort(endd.begin(), endd.end());

    int p1, p2;
    p1 = p2 = 0;

    int curr, ans;
    curr = ans = 0;
    while(true){
        if(start[p1] < endd[p2]){
            curr++;
            p1++;
            ans = max(ans, curr);
        }
        else{
            p2++;
            curr--;
        }
        if(p1 >= n)
            break;
    }

    //output
    cout << ans;

    return 0;
}