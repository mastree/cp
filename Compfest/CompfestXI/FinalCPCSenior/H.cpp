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

int tc, q;
ll n, m;

vector<int> quer[N];

int bitx[N], bity[N];

void updx(int x){
    while (x < N){
        bitx[x]++;
        x = x + (x & (-x));
    }
}
void updy(int x){
    while (x < N){
        bity[x]++;
        x = x + (x & (-x));
    }
}

int askx(int a, int b){
    int ret = 0;
    while (b){
        ret += bitx[b];
        b = b - (b & (-b));
    }
    a--;
    while (a){
        ret -= bitx[a];
        a = a - (a & (-a));
    }
    return ret;
}
int asky(int a, int b){
    int ret = 0;
    while (b){
        ret += bity[b];
        b = b - (b & (-b));
    }
    a--;
    while (a){
        ret -= bity[a];
        a = a - (a & (-a));
    }
    return ret;
}

void init(){
    for (int i=0;i<N;i++){
        quer[i].clear();
        bitx[i] = bity[i] = 0;
    }
}

void solve(){
    cin >> n >> m >> q;
    init();
    map<int, int> getidx, getidy;
    for (int i=1;i<=q;i++){
        int tipe;
        cin >> tipe;
        quer[i].pb(tipe);
        if (tipe == 1){
            int a;
            cin >> a;
            quer[i].pb(a);
            getidx[a] = 1;
        } else if (tipe == 2){
            int a;
            cin >> a;
            quer[i].pb(a);
            getidy[a] = 1;
        } else{
            int xa, ya, xb, yb;
            cin >> xa >> ya >> xb >> yb;
            quer[i].pb(xa);
            quer[i].pb(ya);
            quer[i].pb(xb);
            quer[i].pb(yb);
            getidx[xa] = 1;
            getidx[xb] = 1;
            getidy[ya] = 1;
            getidy[yb] = 1;
        }
    }
    int tempid;
    tempid = 0;
    for (auto x : getidx){
        getidx[x.fi] = ++tempid;
    }
    tempid = 0;
    for (auto x : getidy){
        getidy[x.fi] = ++tempid;
    }

    for (int i=1;i<=q;i++){
        int tipe = quer[i][0];
        if (tipe == 1){
            int x = quer[i][1];

            updx(getidx[x]);
        } else if (tipe == 2){
            int y = quer[i][1];
            
            updy(getidy[y]);
        } else{
            int xa = quer[i][1];
            int ya = quer[i][2];
            int xb = quer[i][3];
            int yb = quer[i][4];
            if (xa > xb) swap(xa, xb);
            if (ya > yb) swap(ya, yb);

            ll cntx = askx(getidx[xa], getidx[xb]);
            ll cnty = asky(getidy[ya], getidy[yb]);
            ll ans = cntx * ((ll)(yb - ya + 1)) + cnty * ((ll)(xb - xa + 1)) - cntx * cnty;

            cout << ans << el;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--){
        solve();
    }

    return 0;
}