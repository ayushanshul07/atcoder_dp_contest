//D - Knapsack 1

#include <iostream>
#include <vector>

using namespace std;
int main(){

    int n; cin >> n;
    int w; cin >> w;

    vector<int> weights(n), values(n);
    for(int i = 0; i < n; ++i) cin >> weights[i] >> values[i];

    //dp[i][j] is maximum value which can be acheived using first (i+1) items and with a knapsack of capacity j
    vector<vector<long long> > dp(n, vector<long long>(w+1));

    for(int i = 0; i <= w; ++i){
        if(i - weights[0] >= 0){
            dp[0][i] = values[0];
        }
    }

    for(int i = 1; i < n; ++i){
        for(int j = 0; j <= w; ++j){
            if( j - weights[i] >= 0){
                dp[i][j] = max(dp[i-1][j], values[i] + dp[i-1][j-weights[i]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n-1][w] << "\n";
    
    return 0;
}