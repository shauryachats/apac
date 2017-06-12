#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int main()
{
	ios::sync_with_stdio(0);
	ll powof2[10001];
	powof2[0] = 1;
	for (int i = 1; i <= 10000; ++i)
	{
		powof2[i] = powof2[i-1] * 2;
		powof2[i] %= MOD;
	}
	int T;
	cin>>T;
	for (int t = 1; t <= T; ++t)
	{
		int N;
		cin>>N;
		ll arr[N];
		for (int i = 0; i < N; ++i)
		{
			cin>>arr[i];
		}
		ll ans = 0, temp;
		for (int i = 0; i < N; ++i)
		{
			temp = powof2[i] - powof2[N-1-i];
			while (temp < 0) temp += MOD;
			temp %= MOD;
			temp *= arr[i];
			temp %= MOD;
			ans += temp;
			ans %= MOD;
		}
		cout<<"Case #"<<t<<": "<<ans<<'\n';
	}
}