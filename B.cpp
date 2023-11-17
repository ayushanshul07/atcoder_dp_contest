//B - Frog 2

#include <iostream>
#include <vector>

using namespace std;
int main(){

    int n; cin >> n;
    int k; cin >> k;
    vector<int> heights(n);
    for(int i = 0; i < n; ++i) cin >> heights[i];

    vector<int> dp(n,1e9); // dp[i] is the minimum cost incurred to reach stone i
    dp[0] = 0;
    dp[1] = abs(heights[1]-heights[0]);

    for(int i = 2; i < n; ++i){
        for(int j = i-1; j >= max(0, i - k); --j){
            dp[i] = min(dp[i], dp[j] + abs(heights[i] - heights[j]));
        }
        
    }

    cout << dp[n-1] << "\n";

}