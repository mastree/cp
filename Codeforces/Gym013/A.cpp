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

struct Circle{
    int x, y, r;
    Circle(){}
    Circle(int x, int y, int r) : x(x), y(y), r(r) {}
};

int m, n, k;
Circle ar[N];

int par[N], sz[N];
pair<bool, bool> stat[N]; // status nempel x dan y

bool satu(int a, int b){
    ll delx = ar[a].x - ar[b].x;
    ll dely = ar[a].y - ar[b].y;
    ll jarak = (delx * delx + dely * dely);
    ll mx = ar[a].r + ar[b].r;
    return mx * mx >= jarak;
}
bool nempelx(int a){
    int mny = ar[a].y - ar[a].r;
    int mxx = ar[a].x + ar[a].r;
    return (mny <= 0 || mxx >= m);
}
bool nempely(int a){
    int mnx = ar[a].x - ar[a].r;
    int mxy = ar[a].y + ar[a].r;
    return (mnx <= 0 || mxy >= n);
}
void init(){
    for (int i=1;i<=k;i++){
        par[i] = i;
        sz[i] = 1;
        stat[i] = mp(nempelx(i), nempely(i));
    }
}
int find(int a){
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}
void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    stat[a].fi |= stat[b].fi;
    stat[a].se |= stat[b].se;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> k;
    for (int i=1;i<=k;i++){
        int a, b, c;
        cin >> a >> b >> c;
        ar[i] = Circle(a, b, c);
    }
    init();
    for (int i=1;i<=k;i++){
        for (int j=1;j<=k;j++){
            if (satu(i, j)) make(i, j);
        }
    }
    bool ok = 1;
    for (int i=1;i<=k;i++){
        if (stat[i].fi && stat[i].se){
            ok = 0;
            break;
        }
    }
    if (ok) cout << 'S' << el;
    else cout << 'N' << el;

    return 0;
}