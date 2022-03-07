#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e5 + 10;
const int INF = 1e9;

int q;
int n, ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        if (ar[1] == 1 || ar[n] == n){
            cout << "YES" << el;
            continue;
        }
        vector<pii> v;
        int mn, last; 
        for (int i=1;i<=n;i++){
            if (i == 1){
                mn = ar[i]; 
                last = ar[i];
                continue;
            }
            if (ar[i] > last){
                last = ar[i];
            } else{
                v.pb(mp(mn, last));
                mn = ar[i];
                last = ar[i];
            }
        }
        v.pb(mp(mn, last));
        bool ok = 0;
        int len = v.size();
        vector<bool> le(len, 0), ri(len, 0);
        le[0] = 1;
        for (int i=1;i<len;i++){
            if (v[i].se >= v[0].fi) le[i] = 1;
        }
        ri[len - 1] = 1;
        for (int i=0;i<len - 1;i++){
            if (v[i].fi <= v[len - 1].se) ri[i] = 1;
        }
        if (ri[0] || le[len - 1]){
            cout << "YES" << el;
            continue;
        }
        for (int i=0;i<len - 1;i++){
            if (le[i] && ri[i + 1] && v[0].fi <= v[len - 1].se){
                ok = 1;
                break;
            }
        }
        if (ok) cout << "YES" << el;
        else cout << "NO" << el;
    }

    return 0;
}