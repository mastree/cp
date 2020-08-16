#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int n, d;
ll m;
ll ans = 0;
vector<ll> a, b;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d >> m;
    for (int i=1;i<=n;i++){
        ll temp;
        cin >> temp;
        if (temp <= m) a.pb(temp);
        else b.pb(temp);
    }
    a.pb(0);
    b.pb(0);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i=1;i<a.size();i++){
        a[i] += a[i - 1];
    }
    for (int i=1;i<b.size();i++){
        b[i] += b[i - 1];
    }
    int alen = (int)a.size() - 1;
    int blen = (int)b.size() - 1;
    ans = a[alen];
    for (int i=0;i<=alen;i++){
        int total = blen + i;
        int dapet = (total + d) / (d + 1);
        if (dapet > blen) continue;
        ll cur = b[blen] - b[blen - dapet] + a[alen] - a[i];
        ans = max(ans, cur);
    }
    cout << ans << el;

    return 0;
}