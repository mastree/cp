#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e3 + 10;

int q;
int n;
int ar[N];
vector<int> pos[N];

void init(){
    for (int i=0;i<=n + 2;i++){
        pos[i].clear();
    }
}

void solve(){
    cin >> n;
    init();
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        pos[ar[i]].pb(i);
    }
    ll ans = 0;
    for (int i=1;i<=n;i++){
        ll cur = 0;

        int le = i + 1;
        for (int j=i + 1;j<=n;j++){
            if (ar[i] != ar[j]){
                continue;
            }
            while (le < j){
                // tambah ar[le]
                int len = pos[ar[le]].size();
                int l = 0, r = len;
                r--;
                while (l < r){
                    int m = (l + r) / 2;
                    if (pos[ar[le]][m] > le){
                        r = m;
                    } else{
                        l = m + 1;
                    }
                }
                if (pos[ar[le]][r] > le){
                    cur += len - r;
                }
                le++;
                auto itb = lower_bound(pos[ar[le]].begin(), pos[ar[le]].end(), le);
                auto ita = lower_bound(pos[ar[le]].begin(), pos[ar[le]].end(), i + 1);
                int range = (int)(itb - ita);
                cur -= range;
            }
            ans += cur;
        }
    }
    cout << ans << el;
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