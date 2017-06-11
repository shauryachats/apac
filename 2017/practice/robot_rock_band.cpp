/**
	O(n^2 lg n) solution
*/
#include <bits/stdc++.h>
using namespace std;
map<long, long> m[2];
map<long, long> mx;
unordered_map<long,long> lx;
int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	for (int t = 1; t <= T; ++t)
	{
		long N, K, val;
		cin>>N>>K;
		long xx;
		m[0].clear(), m[1].clear(), mx.clear(), lx.clear();
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin>>xx;
				m[i][xx]++;
			}
		}
		for (auto &x: m[0])
			for (auto &y: m[1])
				mx[x.first ^ y.first] += (x.second)*(y.second);
		
		m[0].clear();
		m[1].clear();
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin>>xx;
				m[i][xx]++;
			}
		}

		for (auto &x: m[0])
			for (auto &y: m[1])
				lx[x.first ^ y.first] += (x.second)*(y.second);

		unsigned long long ans = 0;
		for (auto &w: mx)
		{
			val = K ^ w.first;
			if (lx.find(val) != lx.end())
				ans += (w.second) * (lx[val]);
		}
		cout<<"Case #"<<t<<": "<<ans<<'\n';
	}
}