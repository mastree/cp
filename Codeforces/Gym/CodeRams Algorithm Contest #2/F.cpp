#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

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
const int MX = 1e4;

int n, k;
ll cnt[MX + 5];
ll take[MX + 5];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        cnt[a]++;
    }
    ll ans = 0;
    for (int a=1;a<=min(MX, k);a++){
        if (cnt[a] == 0) continue;
        for (int b=a;a * b<=k;b++){
            if (k % (a * b)) continue;
            int c = k / (a * b);
            if (c < b || MX < c) continue;
            ll cur = 1;
            cur = cur * cnt[a]-- / ++take[a];
            cur = cur * cnt[b]-- / ++take[b];
            cur = cur * cnt[c]-- / ++take[c];
            cnt[a]++;
            cnt[b]++;
            cnt[c]++;
            take[a]--;
            take[b]--;
            take[c]--;
            ans += cur;
        }
    }
    cout << ans << el;

    return 0;
}