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
const ll INF = 1e18;

ll n;
ll a, r, m; // add, remove, move
ll ar[N], pre[N];

ll calc(int id){
    ll cnta = id - 1, cntb = n - id;
    ll tota = pre[id - 1], totb = pre[n] - pre[id];
    ll tam = cnta * ar[id] - tota;
    ll kur = totb - cntb * ar[id];

    ll ret1 = 0, ret2 = INF;
    if (m < a + r){
        ll mn = min(tam, kur);
        tam -= mn;
        kur -= mn;
        ret1 += mn * m;
        ret2 = ret1;

        if (kur > 0){
            ll expect = kur / n;
            if (expect + ar[id] <= ar[id + 1]){
                ll le = expect * (cnta + 1LL);

                ret2 += le * m;
                ll sisa = (kur % n);
                ll temp = sisa * r;
                if (expect + ar[id] < ar[id + 1]){
                    if (sisa > cntb){
                        sisa -= cntb;
                        temp = min(temp, sisa * m + (cnta + 1LL - sisa) * a);
                    } else{
                        temp = min(temp, (n - sisa) * a);
                    }
                }
                ret2 += temp;
            } else ret2 = INF;
        } else ret2 = INF;
    }
    ret1 += tam * a;
    ret1 += kur * r;
    return min(ret1, ret2);
}
ll calc2(ll hh){
    ll cnta = 0, cntb = 0;
    for (int i=1;i<=n;i++){
        if (ar[i] <= hh) cnta += hh - ar[i];
        else cntb += ar[i] - hh;
    }
    ll ret = 0;
    if (m < a + r){
        ll mn = min(cnta, cntb);
        ret += m * mn;
        cnta -= mn;
        cntb -= mn;
    }
    ret += cnta * a;
    ret += cntb * r;
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> r >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    sort(ar + 1, ar + n + 1);
    for (int i=1;i<=n;i++){
        pre[i] = pre[i - 1] + ar[i];
    }
    ll ans = INF;
    ans = min(ans, calc2(pre[n] / n));
    ans = min(ans, calc2((pre[n] + n - 1) / n));

    for (int i=1;i<=n;i++){
        ans = min(ans, calc(i));
    }
    cout << ans << el;

    return 0;
}