//C - Vacation

#include <iostream>
#include <vector>

using namespace std;
int main(){

    int n; cin >> n;
    vector<vector<int> > activities(n, vector<int>(3));

    for(int i = 0; i < n; ++i) cin >> activities[i][0] >> activities[i][1] >> activities[i][2];

    //dp[i][j] denotes maximum happiness she can gain by doing jth work on the ith day
    vector<vector<int> > dp(n, vector<int>(3));
    dp[0] = activities[0];

    for(int i = 1; i < n; ++i){
        dp[i][0] = activities[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = activities[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = activities[i][2] + max(dp[i-1][0], dp[i-1][1]);
    }

    cout << max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]) << "\n";
}