#include <bits/stdc++.h>
using namespace std;

/** START OF DESPERATE OPTIMIZATION **/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

template<typename T> void in(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void out(T n, char CC) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar(CC);
}
/** END OF DESPERATE OPTIMIZATION **/

/** START OF TEMPLATE DEBUGGER **/
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
/** END OF TEMPLATE DEBUGGER **/

const int N = 5e4 + 5;
const int T = 15;

int n, q;
int a[N];
int depth[N], last[N];
vector<int> adj[N];
vector<int> dnode[T];
int tin[N], tout[N], tim;
int lowest;

void dfs(int u) {
    tin[u] = ++tim;
    dnode[depth[u]].emplace_back(u);
    lowest = max(lowest, depth[u]);
    for (int v : adj[u]) {
        depth[v] = 1 + depth[u];
        dfs(v);
    }
    tout[u] = ++tim;
}

bool is_anc(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int main() {
    in(n), in(q);
    for (int i = 1; i <= n; i++) {
        in(a[i]);
    }
    for (int i = 2; i <= n; i++) {
        int p; in(p);
        adj[p].emplace_back(i);
        assert(p != i);
    }
    depth[1] = 1;
    dfs(1);
    // assert(lowest <= 11);
    for (int D = 1; D <= q; D++) {
        int x; in(x);
        int resnode = 0, resdepth = 0;
        for (int t = depth[x]; t <= lowest; t++) {
            int posL = -1, posR = -1;
            {
                int l = 0, r = (int) dnode[t].size() - 1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (tin[dnode[t][mid]] >= tin[x]) {
                        r = mid - 1;
                        posL = mid;
                    } else {
                        l = mid + 1;
                    }
                }
            }
            {
                int l = 0, r = (int) dnode[t].size() - 1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (tout[dnode[t][mid]] <= tout[x]) {
                        l = mid + 1;
                        posR = mid;
                    } else {
                        r = mid - 1;
                    }
                }
            }
            if (posL == -1 || posR == -1) continue;
            for (int i = posL; i <= posR; i++) {
                int curnode = dnode[t][i];
                if (last[curnode] <= D) {
                    resdepth += (t - depth[x]), resnode++;
                    last[curnode] = D + a[curnode];
                }
            }
        }
        out(resdepth, ' '); out(resnode, '\n');
    }
    return 0;
}