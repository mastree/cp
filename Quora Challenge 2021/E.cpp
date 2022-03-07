#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e6 + 10;

int n, m;
vector<int> adj[N];
int indeg[N], outdeg[N];
vector<int> dobel, kin, kout;
vector<pii> ans;
int dumpi = -1, dumpo = -1;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        indeg[b]++;
        outdeg[a]++;
    }
    if (n == 1){
        cout << 0 << el;
        return 0;
    }
    if (m == 0){
        for (int i=1;i<=n;i++){
            int ni = i + 1;
            if (ni > n) ni = 1;
            ans.pb(mp(i, ni));
        }
        cout << ans.size() << el;
        for (auto x : ans){
            cout << x.fi << " " << x.se << el;
        }
        return 0;
    }
    for (int i=1;i<=n;i++){
        if (indeg[i] == 0 && outdeg[i] == 0){
            dobel.pb(i);
        } else if (indeg[i] == 0){
            kin.pb(i);
            // dumpo = i;
        } else if (outdeg[i] == 0){
            kout.pb(i);
            // dumpi = i;
        } else{
            // dumpo = dumpi = i;
        }
    }
    // while (!kin.empty() || !kout.empty()){
    //     if (kin.size() > kout.size()){
    //         int pas = 1;
    //         if (kin.back() == pas) pas++;
    //         int ps = -1;
    //         if (!dobel.empty()){
    //             pas = dobel.back();
    //             dobel.pop_back();
    //             ps = pas;
    //         } else if (!kout.empty()){
    //             pas = kout.back();
    //             kout.pop_back();
    //         }
    //         ans.pb(mp(pas, kin.back()));
    //         kin.pop_back();
    //         if (ps != -1) kin.pb(ps);
    //     } else{
    //         int pas = 1;
    //         if (kout.back() == pas) pas++;
    //         int ps = -1;
    //         if (!dobel.empty()){
    //             pas = dobel.back();
    //             dobel.pop_back();
    //             ps = pas;
    //         } else if (!kin.empty()){
    //             pas = kin.back();
    //             kin.pop_back();
    //         }
    //         ans.pb(mp(kout.back(), pas));
    //         kout.pop_back();
    //         if (ps != -1) kout.pb(ps);
    //     }
    // }
    // if (dobel.size()){
    //     if (dobel.size() == 1){
    //         ans.pb(mp(dobel.back(), 1 + (dobel.back() == 1)));
    //         ans.pb(mp(1 + (dobel.back() == 1), dobel.back()));
    //     } else{
    //         int len = dobel.size();
    //         for (int i=0;i<len;i++){
    //             ans.pb(mp(dobel[i], dobel[(i + 1) % len]));
    //         }
    //     }
    // }
    while (!dobel.empty()){
        if (kin.size()){
            ans.pb(mp(dobel.back(), kin.back()));
            kin.pop_back();
            kin.pb(dobel.back());
            dobel.pop_back();
        } else{
            ans.pb(mp(kout.back(), dobel.back()));
            kout.pop_back();
            kout.pb(dobel.back());
            dobel.pop_back();
        }
    }
    while (kin.size() && kout.size()){
        ans.pb(mp(kout.back(), kin.back()));
        kout.pop_back();
        kin.pop_back();
    }
    for (auto& x : kin){
        ans.pb(mp(1 + (1 == x), x));
    }
    for (auto& x : kout){
        ans.pb(mp(x, 1 + (1 == x)));
    }
    cout << ans.size() << el;
    for (auto x : ans){
        cout << x.fi << " " << x.se << el;
    }

    return 0;
}