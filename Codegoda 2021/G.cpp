#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9;

struct Voucher{
    int id;
    string a, b;
    int val; // <= 1e6
};

int q;
int n;

string get_date(){
    string ret = "", temp;
    cin >> ret;
    cin >> temp;
    for (auto& x : temp) ret.pb(x);
    cin >> temp;
    for (auto& x : temp) ret.pb(x);
    return ret;
}

void solve(){
    cin >> n;
    map<string, int> conv;
    vector<string> rconv;
    string ss, se;
    ss = get_date();
    se = get_date();
    conv[ss] = 1;
    conv[se] = 1;

    vector<Voucher> voucs(n);
    for (int i=0;i<n;i++){
        cin >> voucs[i].id;
        voucs[i].a = get_date();
        voucs[i].b = get_date();
        cin >> voucs[i].val;
        conv[voucs[i].a] = 1;
        conv[voucs[i].b] = 1;
    }
    vector<vector<pair<int, pii>>> vec((int)conv.size() + 1); // id, right, val 
    int dline = 0;
    int idss;
    int idse;
    {
        rconv.resize((int)conv.size() + 1);
        for (auto& x : conv){
            x.se = ++dline;
            rconv[dline] = x.fi;
        }
        idss = conv[ss];
        idse = conv[se];
        for (auto& vo : voucs){
            int le = conv[vo.a];
            pair<int, pii> temp = mp(vo.id, mp(conv[vo.b], vo.val));
            if (le < idss || idse < temp.se.fi) continue;
            vec[le].pb(temp);
        }
    }
    dline = conv[se];
    vector<ll> dp(dline + 1, 0);
    for (int i=1;i<=dline;i++){
        dp[i] = max(dp[i], dp[i - 1]);
        for (auto& x : vec[i]){
            int j = x.se.fi;
            if (j > dline) continue;
            int val = x.se.se;
            dp[j] = max(dp[j], dp[i] + val);
        }
    }
    vector<bool> mark(dline + 1, 0);
    // pii awal = mp(INF, INF); // id-awal, pos dp
    for (int i=dline;i>=0;i--){
        if (dp[i] == dp[dline]){
            mark[i] = 1;
            continue;
        }
        if (mark[i + 1] && dp[i] == dp[i + 1]) mark[i] = 1;
        for (auto& x : vec[i]){
            int id = x.fi;
            int j = x.se.fi;
            if (j > dline) continue;
            int val = x.se.se;
            // dp[j] = max(dp[j], dp[i] + val);
            if (mark[j] && dp[i] + val == dp[j]){
                mark[i] = 1;
                // cout << i << " " << j << " " << dp[i] << " " << val << el;
                // if (dp[i] == 0){
                //     awal = min(awal, mp(id, j));
                // }
            }
        }
    }
    // assert(awal != mp(INF, INF));
    vector<int> urut;
    int cur = 0;
    while (dp[cur] != dp[dline]){
        pii nambil = mp(INF, cur + 1);
        for (auto& x : vec[cur]){
            int id = x.fi;
            int j = x.se.fi;
            if (j > dline) continue;
            int val = x.se.se;
            if (!mark[j]) continue;
            if (dp[cur] + val == dp[j]){
                nambil = min(nambil, mp(j, id));
            }
        }
        if (nambil.fi == INF){
            cur = cur + 1;
        } else{
            urut.pb(nambil.se);
            cur = nambil.fi;
        }
    }

    cout << dp[dline] << " - ";
    int ulen = urut.size();
    for (int i=0;i<ulen;i++){
        cout << urut[i];
        if (i < ulen - 1) cout << ' ';
    }
    cout << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}