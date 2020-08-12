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

int q, n;
int ans[6] = {6, 10, 14, 15, 21, 22};

void solve(){
    cin >> n;
    vector<int> v;
    bool ok = 0;
    for (int i=0;i<6;i++){
        for (int j=i + 1;j<6;j++){
            for (int k=j + 1;k<6;k++){
                int tot = ans[i] + ans[j] + ans[k];
                if (tot < n){
                    int sisa = n - tot;
                    v.clear();
                    v.pb(ans[i]);
                    v.pb(ans[j]);
                    v.pb(ans[k]);
                    v.pb(sisa);
                    ok = 1;
                    for (int ii=0;ii<4;ii++){
                        for (int jj=ii + 1;jj<4;jj++){
                            if (v[ii] == v[jj]){
                                ok = 0;
                                break;
                            }
                        }
                        if (!ok) break;
                    }
                }
                if (ok) break;
            }
            if (ok) break;
        }
        if (ok) break;
    }
    if (!ok){
        cout << "NO" << el;
        return;
    } 
    cout << "YES" << el;
    for (auto x : v) cout << x << " "; cout << el;
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