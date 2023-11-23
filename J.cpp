//J - Sushi

#include <iostream>
#include <iomanip>

using namespace std;

double dp[310][310][310];
int N;
double solve(int a, int b, int c){
	if(a+b+c == 0) return 0;
	
	if(dp[a][b][c] > -0.5) return dp[a][b][c];
	double x1 = 0.0, x2 = 0.0, x3 = 0.0;
	if(a){
		x1 = a * solve(a-1, b, c);
	}
	if(b){
		x2 = b * solve(a+1, b-1, c);
	}
	if(c){
		x3 = c * solve(a, b+1, c-1);
	}
	
	return dp[a][b][c] = (N + x1 + x2 + x3)/(a+b+c);
}

int main() {
	cin >> N;
	for(int i = 0; i <= N; ++i) for(int j = 0; j <= N; ++j) for(int k = 0; k <= N; ++k) dp[i][j][k] = -1.0;
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < N; ++i){
		int x; cin >> x;
		if(x == 1) ++a;
		if(x == 2) ++b;
		if(x == 3) ++c;
	}
	
    cout << fixed << setprecision(10) << solve(a, b, c) << endl;
	return 0;
}