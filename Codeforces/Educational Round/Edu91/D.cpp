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

int n, m;
int ar[N], br[N];
ll x, k, y;
vector<int> pos;

ll ans;

ll calc(int l, int r){
    if (l > r) return 0;
    int bord = max(ar[l - 1], ar[r + 1]);
    int mx = 0;
    for (int i=l;i<=r;i++){
        mx = max(mx, ar[i]);
    }
    ll ret = 0;
    if (mx < bord){
        ll range = r - l + 1;
        if (x >= k * y){
            ret += range * y;
        } else{
            ret += (range / k) * x;
            range %= k;
            ret += range * y;
        }
    } else{
        ll range = r - l + 1;
        if (range < k) return INF;
        ll sisa = range % k;
        range -= sisa;
        ret += sisa * y;
        if (x >= k * y){
            if (range > k){
                ret += (range - k) * y;
                range = k;
            }
        } 
        ret += (range / k) * x;
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> x >> k >> y;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=m;i++){
        cin >> br[i];
    }
    bool ok = 1;
    pos.pb(0);
    for (int i=1, j=1;i<=m;i++){
        while (j <= n && ar[j] != br[i]) j++;
        if (j > n){
            ok = 0;
            break;
        }
        pos.pb(j);
        j++;
    }
    if (!ok){
        cout << -1 << el;
        return 0;
    }
    pos.pb(n + 1);
    // for (auto x : pos){
    //     cout << x << " ";
    // }
    // cout << el;
    int len = pos.size();
    for (int i=0;i<len - 1;i++){
        ans += calc(pos[i] + 1, pos[i + 1] - 1);
        if (ans >= INF){
            ok = 0;
            break;
        }
    }
    if (!ok){
        cout << -1 << el;
        return 0;
    }
    cout << ans << el;

    return 0;
}