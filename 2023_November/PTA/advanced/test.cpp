// 2023/11/07 17:51:23
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
#include <bitset>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int N = 1000005;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    // int y = 487;
    // printf("%02d:%02d\n", y / 60, y % 60);
    map<int, int> mp;
    mp[5] = 20;
    for(auto& [u, v] : mp) {
        v = 1000;
    }

    for(auto [u, v] : mp) {
        cout << v;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}