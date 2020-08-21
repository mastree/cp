#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

int n;
pii ar[N];
map<int, int> getid;
set<int> bit[N];

void upd(int x, int col){
    while (x){
        bit[x].insert(col);
        x = x - (x & (-x));
    }
}
bool ask(int x, int col){
    while (x < N){
        if (bit[x].find(col) != bit[x].end()) return 1;
        x = x + (x & (-x));
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi >> ar[i].se;
        getid[ar[i].fi] = 1;
    } 
    int tempid = 0;
    for (auto& x : getid){
        x.se = ++tempid;
    }
    for (int i=1;i<=n;i++){
        ar[i].fi = getid[ar[i].fi];
    }
    bool ok = 1;
    for (int i=1;i<=n;i++){
        if (ask(ar[i].fi + 1, ar[i].se)){
            ok = 0;
            break;
        }
        upd(ar[i].fi, ar[i].se);
    }
    if (ok) cout << "YES" << el;
    else cout << "NO" << el;

    return 0;
}