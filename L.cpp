//L - Deque

#include <iostream>
#include <vector>

using namespace std;

long long dp[3010][3010];

int main(){

    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];

    for(int i = 0; i < n + 10; ++i) for(int j = 0; j < n + 10; ++j) dp[i][j] = -1;

    for(int L = n-1; L >= 0; --L){
        for(int R = L; R < n; ++R){
            if(L==R) dp[L][R] = arr[L];
            else{
                dp[L][R] = max(arr[L] - dp[L+1][R], arr[R] - dp[L][R-1]);
            }
        }
    }

    cout << dp[0][n-1] << "\n";

    return 0;
}