// 2023/07/27 15:40:21
// #pragma GCC optimize(2)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e4 + 7);
const int N = 10000005;
int Case = 1;

int fast_pow(int a, int n)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        n /= 2;
    }

    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int ans1 = 0, ans2 = 0;
    
    ans2 = fast_pow(n, k) % 1000;
    
    


    cout << "Case " << Case++ << ": " << ans1 << ' ' << ans2 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }

    cout << flush;
    return 0;
}