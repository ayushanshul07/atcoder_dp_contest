//I - Coins

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(){

    int n; cin >> n;
    vector<double> prob(n+1);
    for(int i = 1; i <= n; ++i) cin >> prob[i];

    //dp[i][j] probablity of having exactly j heads in i coin tosses
    vector<vector<double> > dp(n+1, vector<double>(n+1,0.0));

    dp[0][0] = 1.0;

    for(int i = 1; i <= n; ++i){
        dp[i][0] = dp[i-1][0] * ( 1 - prob[i]);
    }

    dp[1][1] = prob[1];

    for(int i = 2; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            
            dp[i][j] += dp[i-1][j-1] * (prob[i]);
            dp[i][j] += dp[i-1][j] * (1.0-prob[i]);
        }
    }

    double ans = 0.0;
    for(int i = n/2+1; i <= n; ++i) ans += dp[n][i];
    //was giving WA due to this :(
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}