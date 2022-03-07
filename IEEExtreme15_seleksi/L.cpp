#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 2e5 + 10;
const ll INF = 1e18;

int n;
pii pos[N];
pii ab[N], rad[N];

vector<int> del[N], add[N];

ll dist(ll a, ll b){
    return abs(a - b);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> pos[i].fi >> pos[i].se >> ab[i].fi >> ab[i].se;
        pos[i].fi += N / 2;
        pos[i].se += N / 2;
        rad[i].fi = (int)sqrtl(ab[i].fi);
        rad[i].se = (int)sqrtl(ab[i].se);
    }

    // kiri-kanan (jumlah delta kuadrat, jumlah delta, count)

    // first
    ll ansx = INF, ansy = INF;
    {
        pll count;
        pll delta;
        pll delta2;
        ll sumab = 0;

        for (int i=1;i<=n;i++){
            int l = max(1, pos[i].fi - rad[i].fi);
            int r = min(N - 1, pos[i].fi + rad[i].fi);
            del[l].pb(i);
            if (r + 1 < N) add[r + 1].pb(i);
            count.se++;
            delta.se += pos[i].fi;
            delta2.se += 1LL * pos[i].fi * pos[i].fi;
        }
        for (int cur=1;cur<N;cur++){
            // kiri
            delta2.fi += delta.fi * 2 + count.fi;
            delta.fi += count.fi;

            // kanan
            delta2.se += -delta.se * 2 + count.se;
            delta.se -= count.se;

            for (auto& x : del[cur]){
                ll del = dist(pos[x].fi, cur);
                count.se--;
                delta.se -= del;
                delta2.se -= del * del;
                sumab += ab[x].fi;
            }
            for (auto& x : add[cur]){
                ll del = dist(pos[x].fi, cur);
                count.fi++;
                delta.fi += del;
                delta2.fi += del * del;
                sumab -= ab[x].fi;
            }

            ansx = min(ansx, delta2.fi + delta2.se + sumab);
        }
    }
    for (int i=0;i<N;i++){
        del[i].clear();
        add[i].clear();
    }
    // second
    {
        pll count;
        pll delta;
        pll delta2;
        ll sumab = 0;

        for (int i=1;i<=n;i++){
            int l = max(1, pos[i].se - rad[i].se);
            int r = min(N - 1, pos[i].se + rad[i].se);
            del[l].pb(i);
            if (r + 1 < N) add[r + 1].pb(i);
            count.se++;
            delta.se += pos[i].se;
            delta2.se += 1LL * pos[i].se * pos[i].se;
        }
        for (int cur=1;cur<N;cur++){
            // kiri
            delta2.fi += delta.fi * 2 + count.fi;
            delta.fi += count.fi;

            // kanan
            delta2.se += -delta.se * 2 + count.se;
            delta.se -= count.se;

            for (auto& x : del[cur]){
                ll del = dist(pos[x].se, cur);
                count.se--;
                delta.se -= del;
                delta2.se -= del * del;
                sumab += ab[x].se;
            }
            for (auto& x : add[cur]){
                ll del = dist(pos[x].se, cur);
                count.fi++;
                delta.fi += del;
                delta2.fi += del * del;
                sumab -= ab[x].se;
            }

            ansy = min(ansy, delta2.fi + delta2.se + sumab);
        }
    }
    cout << ansx + ansy << el;

    return 0;
}