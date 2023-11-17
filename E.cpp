//E - Knapsack 2

#include <iostream>
#include <vector>

using namespace std;
int main(){

    int n; cin >> n;
    int w; cin >> w;

    vector<int> weights(n), values(n);
    for(int i = 0; i < n; ++i) cin >> weights[i] >> values[i];

    //dp[i][j] is minimum weight which will be required to acheived value j, using only first (i+1) items
    vector<vector<long long> > dp(n, vector<long long>(1e5+1, 1e12));

    for(int i = 0; i <= 1e5; ++i){
        if(values[0] == i){
            dp[0][i] = weights[0];
        }
    }

    for(int i = 0; i < n; ++i) dp[i][0] = 0;

    for(int i = 1; i < n; ++i){
        for(int j = 1; j <= 1e5; ++j){

            if(j - values[i] >= 0){
                dp[i][j] = min(dp[i-1][j], dp[i-1][j - values[i]] + weights[i]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    for(int i = 1e5; i >= 0; --i){
        if(dp[n-1][i] <= w && dp[n-1][i] != -1){
            cout << i << "\n";
            break;
        }
    }
    
    return 0;
}