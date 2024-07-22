// 2024/07/22 10:04:22
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;
#define x first
#define y second

bool cmp(pii& a, pii& b)
{
	return a.y - a.x < b.y - b.x;
}

void solve()
{
	int n;
	cin >> n;
	int nn = 2 * n;
	vector<int> arr(nn + 2);
	vector<pii> pos(n + 1);

	for (int i = 1; i <= nn; ++i)
	{
		cin >> arr[i];
		if (pos[arr[i]].x)
			pos[arr[i]].y = i;
		else
			pos[arr[i]].x = i;
	}

	vector<pii> up(n + 1);
	pos.push_back({0, nn + 1});

	up = pos;
	sort(up.begin(), up.end(), cmp);

	vector<int> tmp(nn + 2);
	vector<int> dp(nn + 2);

	for (auto [l, r] : up)
	{
		tmp[l] = arr[l];
		for (int i = l + 1; i <= r; ++i)
		{
			tmp[i] = tmp[i - 1] + arr[l];

			int left = pos[arr[i]].x;

			if (left != i && left > l)
			{
				tmp[i] = max(tmp[i], tmp[left - 1] + dp[i]);
			}
		}
		dp[r] = tmp[r];
	}

	cout << dp[nn + 1] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	tt = 1;
	while (tt--)
	{
		solve();
	}

#ifdef LOCAL
	cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
	return 0;
}