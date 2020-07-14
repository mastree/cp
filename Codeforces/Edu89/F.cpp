#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

typedef pair<ll, ll> pll;
typedef pair<long double, long double> pdd;

const int N = 2e3 + 10;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int n, m;
vector<pil> adl[N];
ll dp[N][N]; // turn, node
ll mx[N];
ll ans;

vector<pll> lines;
vector<pll> cht;

int q;

ll fpow(ll a, ll b){
    ll ret = 1;
    while (b){
        if (b & 1){
            ret = (ret * a) % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
ll inv(ll a){
    return fpow(a, MOD - 2);
}
long double interX(pll a, pll b){
    return ((long double)b.se - (long double)a.se) / ((long double)a.fi - (long double)b.fi);
}
void addcht(pll line){
    int len = cht.size();
    if (len <= 1){
        if (len == 0){
            cht.pb(line);
            return;
        }
        pll last = cht[len - 1];
        if (last.fi == line.fi){
            if (last.se < line.se){
                cht.pop_back();
                addcht(line);
            }
            return;
        }
        if (last.fi + last.se <= line.fi + line.se){
            cht.pop_back();
            cht.pb(line);
        } else{
            cht.pb(line);
        }
        return;
    }

    pll last = cht[len - 1];
    pll nlast = cht[len - 2];
    if (last.fi == line.fi){
        if (last.se < line.se){
            cht.pop_back();
            addcht(line);
        }
        return;
    }
    long double it1 = interX(nlast, line);
    long double it2 = interX(last, line);
    if (it1 < it2){
        cht.pb(line);
    } else{
        cht.pop_back();
        addcht(line);
    }
}
ll calc(int id, ll xa, ll xb){
    if (xb < xa) return 0;
    ll a = cht[id].fi; // coef
    ll c = cht[id].se; // base

    ll cnt = xb - xa + 1;
    ll ret = ((2 * c % MOD + a * xa % MOD + a * xb % MOD) * cnt % MOD) * inv(2) % MOD;
    return ret;
}
void solve(){
    for (int i=0;i<N;i++){
        fill(dp[i], dp[i] + N, -INF);
    }
    dp[0][1] = 0;
    for (int i=0;i<n;i++){
        for (int j=1;j<=n;j++){ // node asal
            if (dp[i][j] == -INF) continue;
            for (auto x : adl[j]){
                dp[i + 1][x.fi] = max(dp[i + 1][x.fi], dp[i][j] + x.se);
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            mx[i] = max(mx[i], dp[i][j]);
        }
    }
    for (int i=1;i<=n;i++){
        ll a = 0, c;
        c = dp[n][i]; // base
        if (c == -INF) continue;
        for (auto x : adl[i]){
            a = max(a, x.se);
        }
        pll nline = mp(a, c);
        lines.pb(nline);
    }
    sort(lines.begin(), lines.end());
    for (auto line : lines){
        addcht(line);
    }
    if (q <= n){
        for (int i=1;i<=q;i++){
            ans = (ans + mx[i]) % MOD;
        }
        return;
    }
    for (int i=1;i<=n;i++){
        ans = (ans + mx[i]) % MOD;
    }
    ll sisa = q - n;
    ll cur = 1;
    int len = cht.size();
    for (int i=0;i<len - 1;i++){
        if (cur > sisa) break;
        ll ncur = (ll)floor(interX(cht[i], cht[i + 1]));
        if (ncur <= sisa){
            ans = (ans + calc(i, cur, ncur)) % MOD;
        } else{
            ans = (ans + calc(i, cur, sisa)) % MOD;
        }
        cur = ncur + 1;
    }
    if (cur <= sisa){
        ans = (ans + calc(len - 1, cur, sisa)) % MOD;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    for (int i=1;i<=m;i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adl[a].pb(mp(b, w));
        adl[b].pb(mp(a, w));
    }
    solve();
    cout << ans << el;

    return 0;
}