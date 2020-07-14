#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

typedef pair<double, double> pdd;

const int N = 1e3 + 10;
const double EPS = 1e-7;

int n;
pair<pii, pii> ar[N];
pdd line[N]; // m, c
ll ans = 0;

map<pii, ll> inter;
map<pii, bool> udh[N];

pdd get(pii a, pii b){
    double dely = (double)(b.se - a.se);
    double delx = (double)(b.fi - a.fi);
    double m = dely / delx;
    double c = (double)a.se - m * ((double)a.fi);
    return mp(m, c);
}

ll count(pii a, pii b){
    int delx = abs(a.fi - b.fi);
    int dely = abs(a.se - b.se);

    if (delx == 0) return (ll)dely + 1LL;
    if (dely == 0) return (ll)delx + 1LL;
    int gg = __gcd(delx, dely);
    ll ans = (ll)gg + 1LL;
    return ans;
}

bool is_round(double x, double y){
    return (abs(x - round(x)) <= EPS) && (abs(y - round(y)) <= EPS);
}

pii rpoint(double x, double y){
    int nx, ny;
    nx = (int)round(x);
    ny = (int)round(y);
    return mp(nx, ny);
}

bool is_inside(pii pos, pii a, pii b){
    int x1 = min(a.fi, b.fi);
    int x2 = max(a.fi, b.fi);
    int y1 = min(a.se, b.se);
    int y2 = max(a.se, b.se);

    return x1 <= pos.fi && pos.fi <= x2 && y1 <= pos.se && pos.se <= y2; 
}

void handle(int id1, int id2){
    pdd mc1 = line[id1];
    pdd mc2 = line[id2];

    double x, y;
    if (!isfinite(mc1.fi) || !isfinite(mc1.se) || !isfinite(mc2.fi) || !isfinite(mc2.se)){
        if (ar[id1].fi.fi == ar[id1].se.fi){
            x = (double)ar[id1].fi.fi;
            if (ar[id2].fi.se == ar[id2].se.se){
                y = (double)ar[id2].fi.se;
            } else{
                y = mc2.fi * x + mc2.se;
            }
            if (!isfinite(x) || !isfinite(y)) return;
            if (!is_round(x, y)) return;
            pii pos = rpoint(x, y); 
            if (is_inside(pos, ar[id1].fi, ar[id1].se) && is_inside(pos, ar[id2].fi, ar[id2].se)){
                if (!udh[id1][pos]){
                    inter[pos]++;
                    udh[id1][pos] = 1;
                }
                if (!udh[id2][pos]){
                    inter[pos]++;
                    udh[id2][pos] = 1;
                }
            }
            return;
        }
        if (ar[id1].fi.se == ar[id1].se.se){
            y = (double)ar[id1].fi.se;
            if (ar[id2].fi.fi == ar[id2].se.fi){
                x = (double)ar[id2].fi.fi;
            } else{
                x = (y - mc2.se) / mc2.fi;
            }
            if (!isfinite(x) || !isfinite(y)) return;
            if (!is_round(x, y)) return;
            pii pos = rpoint(x, y); 
            if (is_inside(pos, ar[id1].fi, ar[id1].se) && is_inside(pos, ar[id2].fi, ar[id2].se)){
                if (!udh[id1][pos]){
                    inter[pos]++;
                    udh[id1][pos] = 1;
                }
                if (!udh[id2][pos]){
                    inter[pos]++;
                    udh[id2][pos] = 1;
                }
            }
            return;
        } 
        if (ar[id2].fi.fi == ar[id2].se.fi){
            x = (double)ar[id2].fi.fi;
            if (ar[id1].fi.se == ar[id1].se.se){
                y = (double)ar[id1].fi.se;
            } else{
                y = mc1.fi * x + mc1.se;
            }
            if (!isfinite(x) || !isfinite(y)) return;
            if (!is_round(x, y)) return;
            pii pos = rpoint(x, y); 
            if (is_inside(pos, ar[id1].fi, ar[id1].se) && is_inside(pos, ar[id2].fi, ar[id2].se)){
                if (!udh[id1][pos]){
                    inter[pos]++;
                    udh[id1][pos] = 1;
                }
                if (!udh[id2][pos]){
                    inter[pos]++;
                    udh[id2][pos] = 1;
                }
            }
            return;
        } 
        if (ar[id2].fi.se == ar[id2].se.se){
            y = (double)ar[id2].fi.se;
            if (ar[id1].fi.fi == ar[id1].se.fi){
                x = (double)ar[id1].fi.fi;
            } else{
                x = (y - mc1.se) / mc1.fi;
            }
            if (!isfinite(x) || !isfinite(y)) return;
            if (!is_round(x, y)) return;
            pii pos = rpoint(x, y); 
            if (is_inside(pos, ar[id1].fi, ar[id1].se) && is_inside(pos, ar[id2].fi, ar[id2].se)){
                if (!udh[id1][pos]){
                    inter[pos]++;
                    udh[id1][pos] = 1;
                }
                if (!udh[id2][pos]){
                    inter[pos]++;
                    udh[id2][pos] = 1;
                }
            }
            return;
        } 
        return;
    } else{
        x = (mc2.se - mc1.se) / (mc1.fi - mc2.fi);
        y = mc1.fi * x + mc1.se;
    }

    if (!is_round(x, y)) return;
    pii pos = rpoint(x, y); 
    if (is_inside(pos, ar[id1].fi, ar[id1].se) && is_inside(pos, ar[id2].fi, ar[id2].se)){
        if (!udh[id1][pos]){
            inter[pos]++;
            udh[id1][pos] = 1;
        }
        if (!udh[id2][pos]){
            inter[pos]++;
            udh[id2][pos] = 1;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        pii a, b;
        cin >> a.fi >> a.se >> b.fi >> b.se;
        ar[i] = mp(a, b);
        line[i] = get(a, b);
        ans += count(a, b);
    }

    for (int i=1;i<n;i++){
        for (int j=i + 1;j<=n;j++){
            handle(i, j);
        }
    }
    for (auto x : inter){
        ans -= x.se - 1;
    }
    cout << ans << el;

    return 0;
}