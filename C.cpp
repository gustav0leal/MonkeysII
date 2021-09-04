#include <bits/stdc++.h>
using namespace std;

const int MAX_BALDES = 1e3+5;
const int MAX_LIMITE = 200+5;

int N;
int massa[MAX_BALDES], minutos[MAX_BALDES], esforco[MAX_BALDES];
int dp[MAX_BALDES][MAX_LIMITE][MAX_LIMITE];

int solve(int i, int m, int e){
	if (i == N || (m == 0 && e == 0)) return 0;
	if (dp[i][m][e] != -1) return dp[i][m][e];
	int ans = solve(i+1, m, e);
	if (m >= minutos[i])
		ans = max(ans, massa[i] + solve(i+1, m - minutos[i], e));
	if (e >= esforco[i])
		ans = max(ans, massa[i] + solve(i+1, m, e - esforco[i]));
	return dp[i][m][e] = ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));
	int M, E;
	cin >> N >> M >> E;

	for (int i = 0; i < N; i++){
		cin >> massa[i] >> minutos[i] >> esforco[i];
	}

	cout << solve(0, M, E) << "\n";
	return 0;
}
