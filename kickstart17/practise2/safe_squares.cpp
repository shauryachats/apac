#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int grid[3002][3002];
int dp[3002][3002];
int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	for (int t = 1; t <= T; ++t)
	{
		int R, C, K;
		cin>>R>>C>>K;
		memset(dp, 0, sizeof dp);
		memset(grid, 0, sizeof grid);
		
		for (int i = 0; i < K; ++i)
		{
			int r, c;
			cin>>r>>c;
			grid[r+1][c+1] = 1;
		}

		long long sum = 0;

		for (int i = 1; i <= R; ++i)
		{
			for (int j = 1; j <= C; ++j)
			{
				if (grid[i][j] == 0)
					dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
				else
					dp[i][j] = 0;
				//cerr<<dp[i][j]<<' ';
				sum += dp[i][j];
			}
			//cerr<<'\n';
		}

		cout<<"Case #"<<t<<": "<<sum<<'\n';
	}
}