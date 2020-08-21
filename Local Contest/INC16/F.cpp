#include <bits/stdc++.h>

#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using piii = pair<int, pii>;

piii mp3(const int& a, const int& b, const int& c){
    return mp(a, mp(b, c));
}

const int N = 35, T = 10;
const int INF = 1e9;

int q;
int n, m, k, avail; // row, col, req. treasure, avail

string s[N], ar;

int bitCnt[(1 << T)];
int dp[N * N][(1 << T)];
int dpmask[(1 << T)], ans[(1 << T)], nans[(1 << T)];

int di[4] = {0, 0, 1, -1};

void solve(){
    cin >> n >> m >> k >> avail;
    ar = "";
    s[0] = "";
    s[n + 1] = "";
    for (int i=1;i<=n;i++){
        cin >> s[i];
        s[i] = "#" + s[i] + "#";
    }
    for (int i=0;i<=m + 1;i++){
        s[0].pb('#');
        s[n + 1].pb('#');
    }
    if (k == 0){
        cout << 0 << el;
        return;
    }
    for (int i=0;i<=n + 1;i++){
        for (auto x : s[i]) ar.pb(x);
    }
    n = ar.length();
    di[0] = (m + 2);
    di[1] = -(m + 2);

    int st;
    for (int i=0;i<n;i++){
        if (ar[i] == 'E'){
            st = i;
            break;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<(1 << T);j++){
            dp[i][j] = INF;
        }
    }
    dp[st][0] = 0;
    set<piii> setdah; // dp, node, mask
    setdah.insert(mp3(dp[st][0], st, 0));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);

        int dist = tp.fi;
        int node = tp.se.fi;
        int mask = tp.se.se;
        for (int i=0;i<4;i++){
            int nnode = node + di[i];
            if (ar[nnode] == '#') continue;
            int dig = -1;
            if ('0' <= ar[nnode] && ar[nnode] <= '9'){
                dig = (int)(ar[nnode] - '0');
            }
            int nmask = mask;
            if (dig >= 0){
                nmask = (nmask | (1 << dig));
            }

            if (dp[nnode][nmask] > dist + 1){
                setdah.erase(mp3(dp[nnode][nmask], nnode, nmask));
                dp[nnode][nmask] = dist + 1;
                setdah.insert(mp3(dp[nnode][nmask], nnode, nmask));
            }
        }
    }
    for (int i=0;i<(1 << T);i++){
        ans[i] = dpmask[i] = dp[st][i];
    }
    avail = min(avail, k);
    for (int lup=1;lup<avail;lup++){
        for (int i=0;i<(1 << T);i++) nans[i] = ans[i];
        for (int i=0;i<(1 << T);i++){
            for (int j=0;j<(1 << T);j++){
                int ij = (i | j);
                nans[ij] = min(nans[ij], max(ans[i], dpmask[j]));
            }
        }
        for (int i=0;i<(1 << T);i++) ans[i] = nans[i];
    }
    int mn = INF;
    for (int i=0;i<(1 << T);i++){
        if (bitCnt[i] >= k){
            mn = min(mn, ans[i]);
        }
    }
    if (mn < INF) cout << mn << el;
    else cout << -1 << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<(1 << T);i++){
        bitCnt[i] = __builtin_popcount(i);
    }

    cin >> q;
    for (int cas=1;cas<=q;cas++){
        cout << "Case #" << cas << ": ";
        solve();
    }

    return 0;
}