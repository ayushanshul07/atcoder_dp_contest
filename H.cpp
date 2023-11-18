//H - Grid 1

#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

int main(){

    int r; cin >> r;
    int c; cin >> c;

    vector<vector<char> > table(r+1, vector<char>(c+1));

    for(int i = 1; i <= r; ++i){
        for(int j = 1; j <= c; ++j){
            cin >> table[i][j];
        }
    }

    //dp[i][j] denotes number of ways to reach row i and column j
    vector<vector<int> > dp(r+1, vector<int>(c+1));

    for(int i = 1; i <= c; ++i){
        if(table[1][i] == '.'){
            dp[1][i] = 1;
        }
        else break;
    }

    for(int i = 1; i <= r; ++i){
        if(table[i][1] == '.'){
            dp[i][1] = 1;
        }
        else break;
    }

    for(int i = 2; i <= r; ++i){
        for(int j = 2; j <= c; ++j){
            if(table[i][j] == '.'){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
            }
        }
    }

    cout << dp[r][c] << "\n";

    return 0;
}