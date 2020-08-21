#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10, M = 18, BF = 400;
const int INF = 1e9;

int tc;
int n, q;
int ar[N];

map<pii, pii> up[M];
pii bf[N][BF];

void initbf(int s){
    int l, r;
    l = s - 1;
    r = s;
    int cur = s;
    bf[s][0] = mp(l, r);
    for (int i=1;i<BF;i++){
        if (l == 0 && r == n) break;
        if (ar[l] < ar[r]){
            cur = l;
            l--;
        } else{
            r++;
            cur = r;
        }
        bf[s][i] = mp(l, r);
    }
}

void dfs(int l, int r){
    if (l == 0 && r == n) return;
    if (up[0].find(mp(l, r)) != up[0].end()) return;
    if (ar[l] < ar[r]){
        up[0][mp(l, r)] = mp(l - 1, r);
        dfs(l - 1, r);
    } else{
        up[0][mp(l, r)] = mp(l, r + 1);
        dfs(l, r + 1);
    }
}

void init(){
    for (int i=0;i<M;i++){
        up[i].clear();
    }
}

void init_up(){
    for (int i=1;i<M;i++){
        for (auto x : up[i - 1]){
            up[i][x.fi] = up[i - 1][x.se];
        }
    }
}

int jawab(int s, int k){
    if (k == 1) return s;
    if (k - 2 < BF){
        auto temp = bf[s][k - 2];
        if (ar[temp.fi] < ar[temp.se]) return temp.fi;
        return temp.se + 1;
    }
    pii cur = bf[s][BF - 1];
    k -= BF - 1 + 2;
    for (int i=M - 1;i>=0;i--){
        int bit = (1 << i);
        if (bit > k) continue;
        k -= bit;
        cur = up[i][cur];
    }
    if (ar[cur.fi] < ar[cur.se]) return cur.fi;
    return cur.se + 1;
}

void solve(){
    init();
    cin >> n >> q;
    ar[0] = ar[n] = INF;
    for (int i=1;i<n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<n;i++){
        initbf(i);
    }
    for (int i=1;i<n;i++){
        auto temp = bf[i][max(min(n - 5, BF - 1), 0)];
        dfs(temp.fi, temp.se);
    }
    init_up();
    while (q--){
        int s, k;
        cin >> s >> k;

        cout << jawab(s, k) << " ";
    }

    cout << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int cas=1;cas<=tc;cas++){
        cout << "Case #" << cas << ": ";
        solve();
    }

    return 0;
}