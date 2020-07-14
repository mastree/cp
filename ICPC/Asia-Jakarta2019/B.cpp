#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
// #define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 1e5 + 10;
const ll MOD = 1e9 + 7;

struct hue{
    ll tur, headtur, head;
    hue(){
        tur = headtur = head = 0;
    }
    hue(ll a, ll b, ll c){
        tur = a;
        headtur = b;
        head = c;
    }
};

int n;
vector<int> adl[N];
hue dp[N]; // node as path, node as leaf
ll tth[N];
int pred[N];

hue tambah(hue a, hue b){
    return hue((a.tur + b.tur) % MOD, (a.headtur + b.headtur) % MOD, (a.head + b.head) % MOD);
}

ll fpow(ll a, ll b){
    if (b == 0) return 1LL;
    ll temp = fpow(a, b / 2);
    temp = temp * temp % MOD;
    if (b & 1) temp = temp * a % MOD;
    return temp;
}

ll inv(ll a){
    return fpow(a, MOD - 2);
}

pair<ll, ll> tambah(pair<ll, ll> a, pair<ll, ll> b){
    return mp((a.fi + b.fi) % MOD, (a.se + b.se) % MOD);
}

void dfs_pred(int node, int p){
    for (auto x : adl[node]){
        if (x == p) continue;
        pred[node]++;
        dfs_pred(x, node);
    }
}

void dfs(int node, int p){
    if (pred[node] == 0){
        dp[node] = hue(0, 0, 1);
        return;
    }
    for (auto x : adl[node]){
        if (x == p) continue;
        dfs(x, node);
    }
    if (pred[node] == 1){
        for (auto x : adl[node]){
            if (x == p) continue;
            dp[node] = hue(0LL, 0LL, (dp[x].tur + dp[x].headtur + dp[x].head) % MOD);
        }
    } else{
        vector <hue> v;
        for (auto x : adl[node]){
            if (x == p) continue;
            v.pb(dp[x]);
        }
        int len = v.size();
        hue pc[len + 1];
        for (int i=1;i<=len;i++){
            pc[i] = tambah(pc[i - 1], v[i - 1]);
        }
        ll prodtur[len + 2][2];
        ll prodall[len + 2][2];
        ll prodturhed[len + 2][2];
        prodtur[0][0] = 1;
        prodall[0][0] = 1;
        prodturhed[0][0] = 1;
        prodtur[len + 1][1] = 1;
        prodall[len + 1][1] = 1;
        prodturhed[len + 1][1] = 1;
        for (int i=1;i<=len;i++){
            hue x = v[i - 1];
            prodtur[i][0] = prodtur[i - 1][0] * x.tur % MOD;
            prodall[i][0] = prodall[i - 1][0] * (x.tur + x.head + x.headtur) % MOD;
            prodturhed[i][0] = prodturhed[i - 1][0] * (x.tur + x.head) % MOD;
        }
        for (int i=len;i>=1;i--){
            hue x = v[i - 1];
            prodtur[i][1] = prodtur[i + 1][1] * x.tur % MOD;
            prodall[i][1] = prodall[i + 1][1] * (x.tur + x.head + x.headtur) % MOD;
            prodturhed[i][1] = prodturhed[i + 1][1] * (x.tur + x.head) % MOD;
        }
        ll toth = 0;
        vector <int> id0;
        for (int i=1;i<=len;i++){
            ll temp = prodturhed[i - 1][0] * prodturhed[i + 1][1] % MOD;
            hue x = v[i - 1];
            tth[i] = (temp) * (x.headtur + x.head) % MOD;
            toth = (toth + tth[i]) % MOD;
            if ((x.tur + x.head) % MOD == 0) id0.pb(i);
        }
        if ((int) id0.size() == 2){
            ll temp1 = 1;
            for (int i=1;i<=len;i++){
                bool ambil = 1;
                for (auto x : id0) if (i == x) ambil = 0;
                if (ambil){
                    hue x = v[i - 1];
                    temp1 = temp1 * (x.tur + x.head) % MOD;
                } else{
                    hue x = v[i - 1];
                    temp1 = temp1 * (x.head + x.headtur) % MOD;
                }
            }
            dp[node].tur = temp1;
        } else{
            for (int i=1;i<=len;i++){
                hue x = v[i - 1];
                dp[node].tur = (dp[node].tur + ((x.head + x.headtur) * (toth - tth[i] + MOD) % MOD) * inv((x.tur + x.head) % MOD) % MOD) % MOD;
            }
            if ((int) id0.size() == 0) dp[node].tur = dp[node].tur * inv(2) % MOD;
        }
        // head
        // headtur
        for (int i=1;i<=len;i++){
            ll temp1 = prodtur[i - 1][0] * prodtur[i + 1][1] % MOD;
            ll temp2 = prodturhed[i - 1][0] * prodturhed[i + 1][1] % MOD;;//prodall[i - 1][0] * prodall[i + 1][1] % MOD;
            dp[node].head = (dp[node].head + (temp1) * (v[i - 1].headtur + v[i - 1].head) % MOD) % MOD;
            dp[node].headtur = (dp[node].headtur + (temp2) * (v[i - 1].headtur + v[i - 1].head) % MOD) % MOD;
        }
        dp[node].headtur = (dp[node].headtur - dp[node].head + MOD) % MOD;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }
    dfs_pred(1, 1);
    dfs(1, 1);
    cout << (dp[1].tur + dp[1].head) % MOD << el;

    return 0;
}