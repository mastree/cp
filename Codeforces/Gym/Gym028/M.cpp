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

int q;
int n;
vector<int> out[N], in[N];
map<int, int> getid;

void reset(){
    for (int i=1;i<=n;i++){
        out[i].clear();
        out[i].shrink_to_fit();
    }
}

void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        int len;
        cin >> len;
        for (int j=0;j<len;j++){
            int a;
            cin >> a;
            out[i].pb(a);
            getid[a] = 1;
        }
    }
    {
        int tempid = 0;
        for (auto& x : getid){
            x.se = ++tempid;
        }
        for (int i=1;i<=n;i++){
            for (auto& x : out[i]){
                x = getid[x];
                in[x].pb(i);
            }
        }
    }

    reset();
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