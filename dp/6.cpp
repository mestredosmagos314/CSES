#include <bits/stdc++.h>
#define ll long long
#define INF (int) 1e9 + 7

using namespace std;

int main(){

    //input
    int n;
    cin >> n;

    bool arr[1005][1005];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            char temp;
            cin >> temp;
            if(temp == '.')
                arr[i][j] = true;
            else
                arr[i][j] = false;
        }
    }

    //processing

    int dp[1005][1005];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++i){
            dp[i][j] = 0;
        }
    }
    dp[n-1][n-1] = 0;

    for(int i = 2*n -2; i > 0; --i){
        int lin, col;
        if(i < n){
            lin = 0;
            col = i - lin;

            while(col >= 0){
                //process (lin , col)

                if(arr[lin][col] && lin - 1 >= 0){
                    dp[lin-1][col] += dp[lin][col];
                }
                if(arr[lin][col] && col -1 >= 0){
                    dp[lin][col-1] += dp[lin][col];
                }

                col--;
                lin++;
            }
        }
        else{
            lin = n-1;
            col = i - lin;
            while(col <= n-1){
                //process (lin, col)

                if(arr[lin][col] && lin - 1 >= 0){
                    dp[lin-1][col] += dp[lin][col];
                }
                if(arr[lin][col] && col -1 >= 0){
                    dp[lin][col-1] += dp[lin][col];
                }

                col++;
                lin--;
            }
        }
    }

    //output
    cout << dp[0][0];

    return 0;
}