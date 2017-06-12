#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	for (int t = 1; t <= T; ++t)
	{
		string s;
		cin>>s;
		//cerr<<s<<'\n';
		long long I, J;
		cin>>I>>J;
		J--, I--;
		long long totalb = 0;
		for (int i = 0; i < (int)s.length(); ++i)
		{
			if (s[i] == 'B') 
				++totalb;
		}
		cout<<"Case #"<<t<<": ";
		if (totalb == 0)
		{
			cout<<0<<'\n';
			continue;
		}
		long long v = (J - I);
		v /= s.length();
		totalb *= v;
		I %= s.length();
		J %= s.length();
		if (I <= J)
		{
			for (long long i = I; i <= J; ++i)
				if (s[i%s.length()] == 'B')
					++totalb;
		}
		else
		{
			J += s.length();
			for (long long i = I; i <= J; ++i)
				if (s[i%s.length()] == 'B')
					++totalb;
		}
		cout<<totalb<<'\n';
	}
}