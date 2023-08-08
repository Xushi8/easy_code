// 2023/08/07 20:04:55
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
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int N = 100005;

int n, m, R, mod;
int arr[N], son[N], siz[N], top[N], dfn[N], rev[N], deep[N], par[N], tmp[N];
ll d[4 * N], b[4 * N];
int tim;
vector<int> G[N];

void build(int l, int r, int p)
{
    if (l == r)
    {
        d[p] = tmp[l];
        return;
    }


    int mid = l + (r - l) / 2;
    build(l, mid, p * 2);
    build(mid + 1, r, p * 2 + 1);
    d[p] = d[p * 2] + d[p * 2 + 1];
}

void add(int l, int r, int nl, int nr, ll add_val, int p)
{
    if (l <= nl && nr <= r)
    {
        /*
        这里爆了int！！！！！！！
        */
        d[p] += add_val * (nr - nl + 1);
        b[p] += add_val;
        return;
    }

    int mid = nl + (nr - nl) / 2;
    if (b[p] != 0)
    {
        d[p * 2] += b[p] * (mid - nl + 1);
        b[p * 2] += b[p];
        d[p * 2 + 1] += b[p] * (nr - (mid + 1) + 1);
        b[p * 2 + 1] += b[p];
        b[p] = 0;
    }

    if (l <= mid)
        add(l, r, nl, mid, add_val, p * 2);
    if (mid + 1 <= r)
        add(l, r, mid + 1, nr, add_val, p * 2 + 1);

    d[p] = d[p * 2] + d[p * 2 + 1];
}

ll query(int l, int r, int nl, int nr, int p)
{
    if (l <= nl && nr <= r)
    {
        return d[p];
    }

    int mid = nl + (nr - nl) / 2;
    if (b[p] != 0)
    {
        d[p * 2] += b[p] * (mid - nl + 1);
        b[p * 2] += b[p];
        d[p * 2 + 1] += b[p] * (nr - (mid + 1) + 1);
        b[p * 2 + 1] += b[p];
        b[p] = 0;
    }

    ll sum = 0;
    if (l <= mid)
        sum += query(l, r, nl, mid, p * 2);
    if (mid + 1 <= r)
        sum += query(l, r, mid + 1, nr, p * 2 + 1);

    return sum;
}

void dfs1(int u, int from)
{
    deep[u] = deep[from] + 1;
    siz[u] = 1;
    par[u] = from;
    for (int v : G[u])
    {
        if (v == from)
            continue;

        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[son[u]] < siz[v])
            son[u] = v;
    }
}

void dfs2(int u, int tp)
{
    top[u] = tp;
    tim++;
    dfn[u] = tim;
    rev[tim] = u;
    if (son[u] == 0)
        return;

    dfs2(son[u], tp); // 重儿子
    for (int v : G[u])
    {
        if (v == son[u] || v == par[u])
            continue;

        dfs2(v, v); // 轻儿子
    }
}


void change(int x, int y, int add_val)
{
    while (top[x] != top[y])
    {
        if (deep[top[x]] < deep[top[y]])
            swap(x, y);

        add(dfn[top[x]], dfn[x], 1, n, add_val, 1);
        x = par[top[x]];
    }

    if (dfn[x] > dfn[y])
        swap(x, y);

    add(dfn[x], dfn[y], 1, n, add_val, 1);
}

ll query(int x, int y)
{
    ll res = 0;
    while (top[x] != top[y])
    {
        if (deep[top[x]] < deep[top[y]])
            swap(x, y);

        res += query(dfn[top[x]], dfn[x], 1, n, 1);
        x = par[top[x]];
    }
    if (dfn[x] > dfn[y])
        swap(x, y);

    res += query(dfn[x], dfn[y], 1, n, 1);
    return res;
}

void change(int x, int add_val)
{
    add(dfn[x], dfn[x] + siz[x] - 1, 1, n, add_val, 1);
}

ll query(int x)
{
    return query(dfn[x], dfn[x] + siz[x] - 1, 1, n, 1);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs1(1, 0);
    dfs2(1, 1);
    for (int i = 1; i <= n; i++)
    {
        tmp[dfn[i]] = arr[i];
    }
    build(1, n, 1);

    while (m--)
    {
        int op, x, add_val;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> add_val;
            change(x, x, add_val);
        }
        else if (op == 2)
        {
            cin >> x >> add_val;
            change(x, add_val);
        }
        else
        {
            cin >> x;
            cout << query(1, x) << '\n';
        }
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    cout << endl;
    return 0;
}