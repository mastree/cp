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
        if ((++ada[x.fi][x.se] >= 2 && x.fi != -1 && x.se != -1) || tot[x.fi] > m || tot2[x.se] > m){
            cout << "NO" << el;
            return 0;
        }
    }
    // assign untuk -1, x
    // {
    //     for (auto& x : ada[-1]){
    //         for (int i=1;i<=m;i++){
    //             if (x.se <= 0) break;
    //             if (!ada[i][x.fi] && tot[i] < m){
    //                 ada[i][x.fi]++;
    //                 tot[i]++;
    //                 x.se--;
    //                 m1[x.fi].pb(i);
    //             }
    //         }
    //     }
    //     for (auto& x : ada[-1]){
    //         if (x.se > 0){
    //             cout << "NO" << el;
    //             return 0;
    //         }
    //     }
    // }
    fill(last + 1, last + m + 1, 1);
    vector<pii> ans;
    for (auto& x : allvec){
        if (x.fi != -1 && x.se == -1){
            while (ada[x.fi][last[x.fi]]) last[x.fi]++;
            ans.pb(mp(x.fi, last[x.fi]));
            ada[x.fi][last[x.fi]]++;
        } else{
            ans.pb(x);
        }
    }
    fill(last + 1, last + m + 1, 1);
    for (auto& x : ans){
        if (x.fi == -1 && x.se != -1){
            while (ada[last[x.se]][x.se]) last[x.se]++;
            ans.pb(mp(last[x.se], x.se));
            ada[last[x.se]][x.se]++;
        }
    }
    // fill(last + 1, last + m + 1, 1);
    // vector<pii> ans;
    // // assign untuk x, -1
    // for (auto& x : allvec){
    //     if (x.fi != -1 && x.se != -1){
    //         ans.pb(x);
    //     } else if (x.se != -1){
    //         ans.pb(mp(m1[x.se].back(), x.se));
    //         m1[x.se].pop_back();
    //     } else if (x.fi != -1){
    //         while (ada[x.fi][last[x.fi]]) last[x.fi]++;
    //         ans.pb(mp(x.fi, last[x.fi]));
    //         ada[x.fi][last[x.fi]]++;
    //     } else{
    //         ans.emplace_back(-1, -1);
    //     }
    // }
    bool ok = 1;
    // assign untuk -1, -1 sambil cek valid
    for (auto& x : ans){
        if (x.fi == -1 || x.se == -1){
            while (ada[hehe.fi][hehe.se]) inchehe();
            x = hehe;
            ada[hehe.fi][hehe.se]++;
        }
        if (x.fi > m || x.se > m){
            ok = 0;
            break;
        } else if (cek[x.fi][x.se]){
            ok = 0;
            break;
        } 
        cek[x.fi][x.se] = 1;
    }
    if (ok){
        cout << "YES" << el;
        for (auto& x : ans) cout << x.fi << " " << x.se << el;
    } else{
        cout << "NO" << el;
    }

    return 0;
}