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

const int N = 310;
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

priority_queue<ld> sec[N][N];

void solve(){
    int n;
    cin >> n;
    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=n;j++){
    //         sec[i][j].clear();
    //     }
    // }
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
                vector<int> oid = {i, j, k};
                ll area1 = getarea(vec);
                ld cperim = getperim(vec);
                ll area2 = 0;

                bool ok = 1;
                vector<pair<pii, ld>> sim;
                for (int skip=0;skip<3;skip++){
                    vector<pii> temp;
                    vector<int> ids;
                    for (int id=0;id<3;id++){
                        if (id != skip){
                            temp.pb(vec[id]);
                            ids.pb(oid[id]);
                        }
                    }
                    temp.pb(mp(x, y));
                    auto are = getarea(temp);
                    area2 += are;
                    if (are == 0){
                        ok = 0;
                        if (temp[2] != temp[0] && temp[2] != temp[1]) sim.pb(mp(mp(ids[0], ids[1]), getdist(temp[0], temp[1])));
                    }
                }
                if (area2 == area1 && ok){
                    perim = min(perim, cperim);
                } else if (area2 == area1){
                    for (auto& x : sim){
                        int a = x.fi.fi;
                        int b = x.fi.se;
                        ld val = x.se;
                        // cout << a << " " << b << " " << cperim - val << el;
                        sec[a][b].push(cperim - val);
                        while (sec[a][b].size() > 2){
                            // auto temp = *sec[a][b].rbegin();
                            // sec[a][b].erase(temp);
                            sec[a][b].pop();
                        }
                    }
                }
            }
        }
    }
    // if (perim >= INF - EPS){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (sec[i][j].size() >= 2){
                // perim = min(perim, (*sec[i][j].begin()) + (*sec[i][j].rbegin()));
                ld temp = 0;
                while (sec[i][j].size()){
                    temp += sec[i][j].top();
                    sec[i][j].pop();
                }
                perim = min(perim, temp);
            }
        }
    }
    // }
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