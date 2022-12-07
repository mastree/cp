#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll INF = 1e18;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> vec(n);
    for (auto& x : vec) {
        cin >> x;
        x %= m;
    }
    sort(vec.begin(), vec.end());
    vector<ll> svec(n + n);
    for (int i = 0; i < n + n; i++) {
        if (i < n) svec[i] = vec[i] - m;
        else svec[i] = vec[i - n];
    }
    ll ret = INF;
    for (int i = 0; i <= n; i++) {
        ret = min(ret, svec[i + n - 1] - svec[i]);
    }
    cout << ret << '\n';

    return 0;
}