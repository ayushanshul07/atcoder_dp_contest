//A - Frog 1

#include <iostream>
#include <vector>

using namespace std;
int main(){

    int n; cin >> n;
    vector<int> heights(n);
    for(int i = 0; i < n; ++i) cin >> heights[i];

    vector<int> dp(n,0); // dp[i] is the minimum cost incurred to reach stone i
    dp[0] = 0;
    dp[1] = abs(heights[1]-heights[0]);

    for(int i = 2; i < n; ++i){
        dp[i] = min(dp[i-1] + abs(heights[i] - heights[i-1]), dp[i-2] + abs(heights[i] - heights[i-2]));
    }

    cout << dp[n-1] << "\n";

}