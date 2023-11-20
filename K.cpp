//K - Stones

#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int>& opt, int k, int player, vector<vector<int> >& dp){
    
    if(k == 0){
        return dp[0][player] = (1-player);
    }

    if(dp[k][player] != -1) return dp[k][player];
    bool winning = false;
    for(int i = 0; i < opt.size(); ++i){
        if(opt[i] <= k){
            winning |= (player == solve(opt, k - opt[i], 1 - player, dp));
        }
    }

    if(winning) return dp[k][player] = player;
    return dp[k][player] = (1 - player);
}

int main(){

    int n; cin >> n;
    int k; cin >> k;

    vector<int> options(n);
    //dp[k][i] denotes who is winning when player i starts game with k stones on board
    vector<vector<int> > dp(k+1,vector<int>(2,-1));
    for(int i = 0; i < n; ++i) cin >> options[i];

    solve(options, k, 0, dp);

    if(dp[k][0] == 0) cout << "First\n";
    else cout << "Second\n";

    return 0;
}