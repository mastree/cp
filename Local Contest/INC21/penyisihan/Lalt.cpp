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

const int N = 1e5 + 10;

int n, m;
vector<pii> allvec;
vector<pii> vec;

map<int, int> _ada[N];
map<int, int>* ada = _ada + 2;

vector<int> m1[N];
int last[N];
set<pii> udh;
int tot[N], tot2[N];

pii hehe = {1, 1};
void inchehe(){
    if (hehe.se < m) hehe.se++;
    else{
        hehe.fi++;
        hehe.se = 1;
    }
}

unordered_map<int, bool> cek[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1){}
        else vec.emplace_back(a, b); // proses yang selain -1, -1
        allvec.emplace_back(a, b);
    }
    // bikin array map counter
    for (auto& x : vec){
        if (x.fi > 0) tot[x.fi]++;
        if (x.se > 0) tot2[x.se]++;
        ++ada[x.fi][x.se];
    }
    fill(last + 1, last + m + 1, 1);
    vector<pii> ans;
    // assign untuk x, -1
    for (auto& x : allvec){
        if (x.fi != -1 && x.se == -1){
            while (ada[x.fi][last[x.fi]] || tot2[last[x.fi]] >= m) last[x.fi]++;
            ada[x.fi][last[x.fi]]++;
            tot2[last[x.fi]]++;
            ans.pb(mp(x.fi, last[x.fi]));
        } else{
            ans.pb(x);
        }
    }
    fill(last + 1, last + m + 1, 1);
    // assign untuk -1, x
    for (auto& x : ans){
        if (x.fi == -1 && x.se != -1){
            while (ada[last[x.se]][x.se] || tot[last[x.se]] >= m) last[x.se]++;
            ada[last[x.se]][x.se]++;
            tot[last[x.se]]++;
            x = mp(last[x.se], x.se);
        }
    }
    // assign untuk -1, -1 sambil cek valid
    set<pii> setdah;
    for (auto& x : ans){
        if (x.fi == -1 && x.se == -1){
            while (ada[hehe.fi][hehe.se]) inchehe();
            x = hehe;
            ada[hehe.fi][hehe.se]++;
        } 
        if (x.fi < 1 || x.se < 1 || x.fi > m || x.se > m){
            cout << "NO" << el;
            return 0;
        }
        setdah.insert(x);
    }
    for (int i=0;i<n;i++){
        if ((allvec[i].fi != -1 && allvec[i].fi != ans[i].fi) || (allvec[i].se != -1 && allvec[i].se != ans[i].se)){
            cout << "NO" << el;
            return 0;
        }
    }
    if (setdah.size() == n){
        cout << "YES" << el;
        for (auto& x : ans) cout << x.fi << " " << x.se << el;
    } else{
        cout << "NO" << el;
    }

    return 0;
}