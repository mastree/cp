#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 810;
const int MX = 2e7;

int n;
bool ar[N][N], vis[N][N];
vector<int> vec;

vector<int> di = {0, 0, 1, -1};
vector<int> dj = {1, -1, 0, 0};

int dfs(int a, int b){
    int ret = 1;
    vis[a][b] = 1;
    for (int i=0;i<4;i++){
        int na = a + di[i];
        int nb = b + dj[i];
        if (na < 1 || n < na || nb < 1 || n < nb) continue;
        if (!ar[na][nb] || vis[na][nb]) continue;
        ret += dfs(na, nb);
    }
    return ret;
}

// vector<int> primes;
// bitset<MX> pbit;

// void init(){
//     pbit[0] = pbit[1] = 1;
//     primes.pb(1);
//     for (int i=2;i * i<MX;i++){
//         if (pbit[i]) continue;
//         primes.pb(i);
//         for (int j=i * i;j<MX;j+=i){
//             pbit[j] = 1;
//         }
//     }
// }

int lp[MX];
vector<int> primes;

void init(){
    int bnd = n * n;
    for (int i=2; primes.size() < bnd; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back(i);
        }
        for (int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<MX; ++j)
            lp[i * primes[j]] = primes[j];
    }
    reverse(primes.begin(), primes.end());
    primes.pb(1);
    reverse(primes.begin(), primes.end());
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            char c;
            cin >> c;
            ar[i][j] = (c == '.');
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (ar[i][j] && !vis[i][j]){
                vec.pb(dfs(i, j));
            }
        }
    }
    init();
    sort(vec.begin(), vec.end());
    pair<ll, int> cur = {0, 0};
    ll ans = 0;
    for (auto& x : vec){
        for (int i=cur.se;i<x;i++){
            cur.fi += primes[i];
        }
        ans += cur.fi;
        cur.se = x;
    }
    cout << ans << el;

    return 0;
}