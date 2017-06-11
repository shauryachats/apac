/**
	O(n) with a high constant.
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	for (int t = 1; t <= T; ++t)
	{
		long N, X, K, A, B, C;
		cin>>N>>X>>K>>A>>B>>C;

		map<long, long double> m, sm;
		m[X] = 1;

		for (int i = 0; i < N; ++i)
		{
			sm.clear();
			for (auto &x : m)
			{
				sm[x.first & K] += (x.second)*A/100.0;
				sm[x.first | K] += (x.second)*B/100.0;
				sm[x.first ^ K] += (x.second)*C/100.0;
			}
			m = sm;
		}

		long double ans = 0;
		for (auto &x : m)
			ans += x.first * x.second;

		cout<<"Case #"<<t<<": "<<fixed<<setprecision(10)<<ans<<'\n';
	}
}