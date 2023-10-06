// 2023/10/05 19:15:37
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
#include <stack>
#include <array>
#include <fstream>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<ll> sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + arr[i - 1];
    }

    if (sum[n] % 3 != 0)
    {
        cout << 0 << endl;
        return 0;
    }

    ll target = sum[n] / 3;
    ll cnt = 0, ans = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        if (sum[i] == target * 2)
            ans += cnt;
        if (sum[i] == target)
            cnt++;
    }

    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}