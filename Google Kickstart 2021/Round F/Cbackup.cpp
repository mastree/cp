#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 300;
const ld INF = 1e18;
const ld EPS = 1e-10;

int q;

ll getarea(const vector<pii>& vec){
    ll ret = 0;
    int len = vec.size();
    for (int i=0;i<len;i++){
        int ni = (i + 1) % len;
        ret += 1LL * vec[i].fi * vec[ni].se;
        ret -= 1LL * vec[ni].fi * vec[i].se;
    }
    return abs(ret);
}
ld getdist(const pii& a, const pii& b){
    ld delx = abs(a.fi - b.fi);
    ld dely = abs(a.se - b.se);
    return sqrtl(delx * delx + dely * dely);
}
ld getperim(const vector<pii>& vec){
    ld ret = 0;
    int len = vec.size();
    for (int i=0;i<len;i++){
        int ni = (i + 1) % len;
        ret += getdist(vec[i], vec[ni]);
    }
    return ret;
}

void solve(){
    int n;
    cin >> n;
    vector<pii> pts(n + 1);
    for (int i=1;i<=n;i++){
        cin >> pts[i].fi >> pts[i].se;
    }
    int x, y;
    cin >> x >> y;
    ld perim = INF;
    for (int i=1;i<=n;i++){
        for (int j=i + 1;j<=n;j++){
            for (int k=j + 1;k<=n;k++){
                vector<pii> vec = {pts[i], pts[j], pts[k]};
                vector<vector<pii>> vecs(3);
                for (int id=0;id<3;id++){
                    for (int jd=0;jd<3;jd++){
                        if (jd == id){
                            vecs[id].pb(mp(x, y));
                        }
                        vecs[id].pb(vec[jd]);
                    }
                }
                // sort(vec.begin(), vec.end(), [] (pii a, pii b) {
                //     bool ba = make_pair(a.fi,a.se) < pair<int,int>(), bb = make_pair(b.fi,b.se) < pair<int,int>();
                //     if (ba != bb) { return ba < bb; }
                //     return 1LL * a.fi * b.se > 1LL * a.fi * b.se;
                // });
                // sort(vec.begin(), vec.end(), [] (pii a, pii b) {
                //     bool x = a < mp(0, 0), y = b < mp(0, 0);
                //     return x == y ? 1LL * a.fi * b.se > 1LL * a.se * b.fi : x < y;
                // });
                ll area1 = getarea(vec);
                ld cperim = getperim(vec);
                vec.pb(mp(x, y));
                // sort(vec.begin(), vec.end(), [] (pii a, pii b) {
                //     bool ba = make_pair(a.fi,a.se) < pair<int,int>(), bb = make_pair(b.fi,b.se) < pair<int,int>();
                //     if (ba != bb) { return ba < bb; }
                //     return 1LL * a.fi * b.se > 1LL * a.fi * b.se;
                // });
                // sort(vec.begin(), vec.end(), [] (pii a, pii b) {
                //     bool x = a < mp(0, 0), y = b < mp(0, 0);
                //     return x == y ? 1LL * a.fi * b.se > 1LL * a.se * b.fi : x < y;
                // });
                ll area2 = 0;
                for (auto& v : vecs) area2 = max(area2, getarea(v));
                // for (auto& x : vec) cout << x.fi << ":" << x.se << " ";
                // cout << area1 << " " << area2 << el;
                if (area2 < area1){
                    perim = min(perim, cperim);
                }
            }
        }
    }
    if (perim < INF - EPS){
        cout << perim << el;
    } else{
        cout << "IMPOSSIBLE" << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(7);
    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 300;
const ld INF = 1e18;
const ld EPS = 1e-10;

int q;

ll getarea(const vector<pii>& vec){
    ll ret = 0;
    int len = vec.size();
    for (int i=0;i<len;i++){
        int ni = (i + 1) % len;
        ret += 1LL * vec[i].fi * vec[ni].se;
        ret -= 1LL * vec[ni].fi * vec[i].se;
    }
    return abs(ret);
}
ld getdist(const pii& a, const pii& b){
    ld delx = abs(a.fi - b.fi);
    ld dely = abs(a.se - b.se);
    return sqrtl(delx * delx + dely * dely);
}
ld getperim(const vector<pii>& vec){
    ld ret = 0;
    int len = vec.size();
    for (int i=0;i<len;i++){
        int ni = (i + 1) % len;
        ret += getdist(vec[i], vec[ni]);
    }
    return ret;
}
bool inside(pii pt, vector<pii> line){
    pii a = line[0];
    pii b = line[0];
    if (pt.fi < min(a.fi, b.fi) || max(a.fi, b.fi) < pt.fi || pt.se < min(a.se, b.se) || max(a.se, b.se) < pt.fi) return 0;
    
}

void solve(){
    int n;
    cin >> n;
    vector<pii> pts(n + 1);
    for (int i=1;i<=n;i++){
        cin >> pts[i].fi >> pts[i].se;
    }
    int x, y;
    cin >> x >> y;
    ld perim = INF;
    for (int i=1;i<=n;i++){
        for (int j=i + 1;j<=n;j++){
            for (int k=j + 1;k<=n;k++){
                vector<pii> vec = {pts[i], pts[j], pts[k]};
                ll area1 = getarea(vec);
                ld cperim = getperim(vec);
                ll area2 = 0;

                bool ok = 1;
                for (int skip=0;skip<3;skip++){
                    vector<pii> temp;
                    for (int id=0;id<3;id++){
                        if (id != skip) temp.pb(vec[id]);
                    }
                    if (inside(mp(x, y), temp)){
                        ok = 0;
                        break;
                    }
                    temp.pb(mp(x, y));
                    area2 += getarea(temp);
                }
                if (area2 == area1 && ok){
                    perim = min(perim, cperim);
                }
            }
        }
    }
    if (perim < INF - EPS){
        cout << perim << el;
    } else{
        cout << "IMPOSSIBLE" << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(7);
    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}