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

const int INF = 1e9 + 10;
const int N = 5e3 + 10;
const int K = 1e6 + 10;

int q;
int n, k;

int le[K];

void solve(){
    cin >> n >> k;
    vector<int> vec(n + 2);
    vector<ll> pre(n + 2, 0);
    for (int i=1;i<=n;i++){
        cin >> vec[i];
        pre[i] = pre[i - 1] + vec[i];
    }
    pre[n + 1] = pre[n];

    if (k == 0){
        cout << 0 << el;
        return;
    }
    int ans = INF;
    fill(le, le + k + 1, INF);
    le[0] = 0;
    for (int l=1;l<=n;l++){
        {
            int j = l - 2;
            for (int i=j;i>=1;i--){
                ll cur = pre[j] - pre[i - 1];
                if (cur > k) break;
                le[cur] = min(le[cur], j - i + 1);
            }
        }
        for (int r=l;r<=n;r++){
            ll cur = pre[r] - pre[l - 1];
            if (cur > k) break;
            int need = k - cur;
            ans = min(ans, r - l + 1 + le[need]);
        }
    }
    if (ans < INF) cout << ans << el;
    else cout << -1 << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}