#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;
const ll INF = 1e18;

int n, p;
ll k, c;
ll A[N], B[N];

pair<int, ll> ans[N];
// cost naik di i turun di j = |i - j|^p * C + Ai + Bj

void solve1(){
    int block = 500;
    {
        vector<ll> vec(n / block + 1, INF);
        int len = vec.size() - 1;
        for (int i=0;i<n;i++){
            int cblock = i / block;
            vec[cblock] = min(vec[cblock], B[i] - c * i);

            int best = -1;
            for (int j=0;j<=cblock;j++){
                if (vec[j] + c * i + A[i] <= k){
                    best = j;
                    break;
                }
            }
            if (best != -1){
                int l = best * block;
                int r = min((best + 1) * block, i);
                for (int j=l;j<=r;j++){
                    ll sisa = k - (B[j] + A[i] + c * (i - j));
                    if (sisa >= 0){
                        ans[i] = max(ans[i], mp(i - j + 1, sisa));
                        break;
                    }
                }
            }
        }
    }
    {
        vector<ll> vec(n / block + 1, INF);
        int len = vec.size() - 1;
        for (int i=n - 1;i>=0;i--){
            int cblock = i / block;
            vec[cblock] = min(vec[cblock], B[i] + c * i);

            int best = -1;
            for (int j=len;j>=cblock;j--){
                if (vec[j] - c * i + A[i] <= k){
                    best = j;
                    break;
                }
            }
            if (best != -1){
                int l = max(best * block, i);
                int r = min((best + 1) * block, n - 1);
                for (int j=r;j>=l;j--){
                    ll sisa = k - (B[j] + A[i] + c * (j - i));
                    if (sisa >= 0){
                        ans[i] = max(ans[i], mp(j - i + 1, sisa));
                        break;
                    }
                }
            }
        }
    }
    for (int i=0;i<n;i++){
        cout << ans[i].fi << ' ' << ans[i].se << el;
    }
}

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};
 
struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

// cost naik di i turun di j = |i - j|^2 + Ai + Bj = -2 * i * j * c + (i^2 * c + j^2 * c + Ai + Bi)
// = (-2 * j) * i

LineContainer t[N * 4];

void build(int v, int tl, int tr){
    if (tl == tr){
        t[v].add(2LL * tl * c, -(1LL * tl * tl * c + B[tl]));
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    for (auto& x : t[v * 2]) t[v].add(x.k, x.m);
    for (auto& x : t[v * 2 + 1]) t[v].add(x.k, x.m);
}
pair<int, ll> askle(int v, int tl, int tr, ll x, ll mx){
    if (tl == tr){
        pair<int, ll> ret = mp(tl, -t[v].query(x));
        return ret;
    }
    int tm = (tl + tr) / 2;
    auto testle = -t[v * 2].query(x);
    if (testle <= mx) return askle(v * 2, tl, tm, x, mx);
    return askle(v * 2 + 1, tm + 1, tr, x, mx);
}
pair<int, ll> askri(int v, int tl, int tr, ll x, ll mx){
    if (tl == tr){
        pair<int, ll> ret = mp(tl, -t[v].query(x));
        return ret;
    }
    int tm = (tl + tr) / 2;
    auto testri = -t[v * 2 + 1].query(x);
    if (testri <= mx) return askri(v * 2 + 1, tm + 1, tr, x, mx);
    return askri(v * 2, tl, tm, x, mx);
}

void solve2(){
    build(1, 0, n - 1);
    for (int i=0;i<n;i++){
        ll mx = k - (1LL * i * i * c + A[i]);
        auto le = askle(1, 0, n - 1, (ll)i, mx);
        auto ri = askri(1, 0, n - 1, (ll)i, mx);
        if (le.se <= mx) ans[i] = max(ans[i], mp(i - le.fi + 1, mx - le.se));
        if (ri.se <= mx) ans[i] = max(ans[i], mp(ri.fi - i + 1, mx - ri.se));
    }
    for (int i=0;i<n;i++){
        cout << ans[i].fi << ' ' << ans[i].se << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> c >> p; // len, koin, factor, degree
    fill(ans, ans + N, mp(0, k));
    for (int i=0;i<n;i++){
        cin >> A[i];
    }
    for (int i=0;i<n;i++){
        cin >> B[i];
    }
    if (p == 1) solve1();
    else solve2();

    return 0;
}