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
		long long N, L, R, A, B, C1, C2, M;
		cin>>N>>L>>R>>A>>B>>C1>>C2>>M;
		pair<long long, long long> arr[N];
		arr[0].first = L;
		arr[0].second = R;
		long long temp = 0;
		for (int i = 1; i < N; ++i)
		{
			arr[i].first = (arr[i-1].first * A)%M;
			temp = (arr[i-1].second * B)%M;
			arr[i].first %= M;
			arr[i].first += temp;
			arr[i].first %= M;
			arr[i].first += C1;
			arr[i].first %= M;

			arr[i].second = (arr[i-1].second * A)%M;
			temp = (arr[i-1].first * B)%M;
			arr[i].second %= M;
			arr[i].second += temp;
			arr[i].second %= M;
			arr[i].second += C2;
			arr[i].second %= M;

		}
		vector<tuple<long long, int, int>> v;
		for (int i = 0; i < N; ++i)
		{
			v.emplace_back(min(arr[i].first,arr[i].second), 0, i);
			v.emplace_back(max(arr[i].second,arr[i].first) + 1, 1, i);
		}	
		sort(v.begin(), v.end());
		set<int> s;
		
		map<long long, int> arrx;

		long long totalarea = 0;
		long long timestamp, type, index;
		long long maxone = 0;
		long long last = 0;

		for (int i = 0; i < 2*N; ++i)
		{
			tie(timestamp, type, index) = v[i];

			if (s.size()) totalarea += timestamp - last;
			if (s.size() == 1)
			{
				arrx[*s.begin()] += timestamp - last;
				long long val = arrx[*s.begin()];
				maxone = max(maxone, val);
			}

			if (type == 0)
				s.insert(index);
			else
				s.erase(index);

			last = timestamp;
		}
		cout<<"Case #"<<t<<": "<<totalarea-maxone<<'\n';
	}
}