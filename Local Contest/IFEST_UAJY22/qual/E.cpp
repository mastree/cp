#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;
const int P = 31;
const int MOD = 1e9 + 7;

string s;
unordered_map<ll, int> cnt;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
ll inv(ll a) {
    return fpow(a, MOD - 2);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int n = s.size();
    vector<ll> pre(n + 1, 0);
    vector<ll> ipow(n + 1, 0);
    {
        ll p = 1;
        ipow[0] = 1;
        ipow[1] = inv(P);
        for (int i = 1; i <= n; i++) {
            ll dig = (s[i - 1] - 'a') + 1;
            pre[i] = (pre[i - 1] + p * dig % MOD) % MOD;
            ipow[i] = ipow[i - 1] * ipow[1] % MOD;

            p = p * P % MOD;
        }
    }
    auto get_hash = [&](int l, int r) -> ll {
        ll ret = (pre[r] - pre[l - 1] + MOD) % MOD;
        return ret * ipow[l - 1] % MOD;
    };
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cnt[get_hash(i, j)]++;
        }
    }
    vector<pair<string, int>> ans;
    for (int i = 1; i < n; i++) {
        string cur;
        cur.push_back(s[i - 1]);
        for (int j = i + 1; j <= n; j++) {
            cur.push_back(s[j - 1]);
            ll hash = get_hash(i, j);
            int& temp = cnt[hash];
            if (temp > 1) {
                ans.emplace_back(cur, temp);
                temp = 0;
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto& x : ans) {
        cout << x.fi << ' ' << x.se << '\n';
    }

    return 0;
}