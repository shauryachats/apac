/**
	O(n) solution 
*/
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	for (int t = 1; t <= T; ++t)
	{
		string s;
		cin>>s;

		set<char> se;
		long long ans = 1;
		for (int i = 0; i < s.length(); ++i)
		{
			se.clear();
			if (i > 0) se.insert(s[i-1]);
			if (i < s.length()-1) se.insert(s[i+1]);
			se.insert(s[i]);
			ans *= se.size();
			ans %= MOD;
		}
		cout<<"Case #"<<t<<": "<<ans<<'\n';
	}
}