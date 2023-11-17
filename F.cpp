//F - LCS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int main(){

    string s; cin >> s; int l1 = s.size();
    string t; cin >> t; int l2 = t.size();

    //dp[i][j].first is maximum longest subsequence where first string is of length (i+1) and second string is of lenght (j+1)
    //dp[i][j].second is from which direction this came from, 0 being s[i-1] == t[j-1] and dp[i-1][j-1] gave max, 1 being dp[i-1][j].first gave max, and 2 being dp[i][j-1].first gave max
    vector<vector<pair<int,int> > > dp(l1+1, vector<pair<int,int> >(l2+1));

    for(int i = 1; i <= l1; ++i){
        for(int j = 1; j <= l2; ++j){
            if(s[i-1] != t[j-1]){
                if(dp[i-1][j].first > dp[i][j-1].first){
                    dp[i][j].first = dp[i-1][j].first;
                    dp[i][j].second = 1;
                }
                else{
                    dp[i][j].first = dp[i][j-1].first;
                    dp[i][j].second = 2;
                }
            }
            else{
                dp[i][j].first = 1 + dp[i-1][j-1].first;
                dp[i][j].second = 0;
            }
        }
    }

    string ans;

    int i = l1, j = l2;
    while(i > 0 && j > 0){
        if(dp[i][j].second == 0){
            ans = ans + s[i-1];
            --i;--j;
        }
        else if(dp[i][j].second == 1){
            --i;
        }
        else --j;
    }

    reverse(ans.begin(), ans.end());

    cout << ans << "\n";
    
    return 0;
}