// 2023/07/15 19:46:27
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, K;
        cin >> n >> K;
        string str;
        cin >> str;
        vector<pii> arr;
        int now = 0;
        for (int i = 0; i < K; i++)
        {
            if (str[i] == 'B')
                now++;
        }

        int ans = now;

        for (int i = K; i < n; i++)
        {
            if (str[i] == 'B')
                now++;
            if (str[i - K] == 'B')
                now--;
            ans = max(ans, now);
        }
        cout << K - ans << '\n';
        
    }

    cout << endl;
    return 0;
}