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

const int N = 1e2 + 10;
const int INF = 1e9 + 7;

int n, m, q;
string ar[N];

bool check(string& s, int ra, int ca, int rb, int cb){
    if (ra < 1 || n < ra || rb < 1 || n < rb) return 0;
    if (ca < 1 || m < ca || cb < 1 || m < cb) return 0;
    int len = s.size();
    int id = 0;
    while (id < len){
        if (s[id] != ar[ra][ca]) return 0;
        if (ra != rb){
            if (ra > rb) ra--;
            else ra++;
        }
        if (ca != cb){
            if (ca > cb) ca--;
            else ca++;
        }
        id++;
    }
    return 1;
}

void solve(){
    string s;
    cin >> s;
    int len = s.size();
    vector<int> ans = {INF, INF, INF, INF};
    int dif = len - 1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            for (int si=-1;si<=1;si++){
                for (int sj=-1;sj<=1;sj++){
                    if (si == sj && si == 0) continue;
                    int ii = i + dif * si;
                    int jj = j + dif * sj;
                    if (check(s, i, j, ii, jj)){
                        ans = min(ans, vector<int>{i, j, ii, jj});
                    }
                }
            }
        }
    }
    if (ans[0] == INF){
        cout << -1 << el;
        return;
    }
    for (auto& x : ans) cout << x - 1 << ' '; cout << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        ar[i] = "*" + s + "*";
    }
    while (q--){
        solve();
    }

    return 0;
}