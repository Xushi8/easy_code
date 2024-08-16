// 2024/08/16 14:32:50
#ifdef LOCAL
#include <basic_std_lib.h>
#else
#include <bits/stdc++.h>
#endif
using namespace std;


void solve();

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

using i64 = int64_t;
using u64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<i64, i64>;
constexpr int N = 1000005;

int get_min(vector<int> const& a)
{
    vector<int> b(a.begin(), a.end());
    const int n = a.size();
    b.insert(b.end(), a.begin(), a.end());
    int i, j;
    for (i = 0, j = 1; i < n && j < n;)
    {
        // 跳过相同的
        int k;
        for (k = 0; k < n && b[i + k] == b[j + k]; k++) {}

        if (b[i + k] > b[j + k]) // i 更大, 于是 i 这段不可能成为最小的, 直接跳过
        {
            i = i + k + 1;
        }
        else
        {
            j = j + k + 1;
        }
        if (i == j)
            j++;
    }
    return min(i, j);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int k = get_min(a);
    rotate(a.begin(), a.begin() + k, a.end());
    for (auto x : a)
        cout << x << ' ';
    cout << '\n';
}