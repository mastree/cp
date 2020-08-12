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

const int N = 510;
const int INF = 1e9;

int n, m;
int ar1[N], ar2[N];
map<int, int> getid;
int idval[2 * N];

vector<pii> pos[N];
vector<int> vec[N][2];

pii dp[N][N];

set<pii> bit[N];

vector<pii> posdp[N];

void tambah(int x, pii val){
    if (bit[x].size() == 2){
        bit[x].insert(val);
        return;
    }
    auto it = bit[x].lower_bound(val);
    vector<pii> pus;
    if (it->se <= val.se){
        while (it != bit[x].end() && it->se < val.se){
            pus.pb(*it);
            it++;
        }
        bit[x].insert(val);
    } else{
        it--;
        if (it->se >= val.se) return;
        bit[x].insert(val);
    }
    for (auto xx : pus){
        bit[x].erase(xx);
    }
}
void upd(int x, pii val){
    while (x < N){
        tambah(x, val);
        x = x + (x & (-x));
    }
}
int ask(int r, int c){
    int ret = 0;
    while (r){
        auto it = bit[r].lower_bound(mp(c, 0));
        if (it != bit[r].begin()){
            it--;
            ret = max(ret, it->se);
        }
        r = r - (r & (-r));
    }
    return ret;
} 

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<N;i++){
        bit[i].insert(mp(0, 0));
        bit[i].insert(mp(INF, INF));
    }

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar1[i];
        getid[ar1[i]] = 1;
    }
    cin >> m;
    for (int i=1;i<=m;i++){
        cin >> ar2[i];
    }
    int tempid = 0;
    for (auto& x : getid){
        x.se = ++tempid;
        idval[tempid] = x.fi;
    }
    for (int i=1;i<=n;i++){
        ar1[i] = getid[ar1[i]];
        vec[ar1[i]][0].pb(i);
    }
    bool ada = 0;
    for (int i=1;i<=m;i++){
        ar2[i] = getid[ar2[i]];
        if (ar2[i]){
            vec[ar2[i]][1].pb(i);
            ada = 1;
        }
    }
    if (!ada){
        cout << 0 << el;
        return 0;
    }
    for (int num=1;num<N;num++){
        for (auto x : vec[num][0]){
            for (auto y : vec[num][1]){
                pos[num].pb(mp(x, y));
            }
        }
        sort(pos[num].begin(), pos[num].end());
    }
    for (int num=1;num<=n;num++){
        if (pos[num].empty()) continue;
        vector<piii> up;
        for (auto x : pos[num]){
            int temp = ask(x.fi, x.se);
            up.pb(mp3(temp + 1, x.fi, x.se));
            dp[x.fi][x.se] = mp(temp + 1, num);
        }
        for (auto x : up){
            upd(x.se.fi, mp(x.se.se, x.fi));
        }
    }
    int ansmx = 0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            ansmx = max(ansmx, dp[i][j].fi);
            if (dp[i][j].fi > 0){
                posdp[dp[i][j].fi].pb(mp(i, j));
            }
        }
    }
    cout << ansmx << el;
    vector<int> ans;
    pii cur = posdp[ansmx][0];
    ans.pb(dp[cur.fi][cur.se].se);
    for (int i=ansmx - 1;i>=1;i--){
        for (auto x : posdp[i]){
            if (x.fi < cur.fi && x.se < cur.se && dp[x.fi][x.se].se < dp[cur.fi][cur.se].se){
                cur = x;
                ans.pb(dp[cur.fi][cur.se].se);
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans) cout << idval[x] << " ";
    cout << el;

    return 0;
}