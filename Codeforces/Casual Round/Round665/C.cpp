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
const int INF = 1e9 + 10;

int q;
int n;
int ar[N];

void solve(){
    cin >> n;
    int mn = INF;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        mn = min(mn, ar[i]);
    }
    if (n == 1){
        cout << "YES" << el;
        return;
    }
    vector<int> v;
    for (int i=1;i<=n;i++){
        if (ar[i] % mn == 0){
            v.pb(ar[i]);
        }
    }
    sort(v.begin(), v.end());
    int id = 0;
    for (int i=1;i<=n;i++){
        if (ar[i] % mn == 0){
            ar[i] = v[id++];
        }
    }

    bool ok = 1;
    for (int i=1;i<n;i++){
        if (ar[i] > ar[i + 1]){
            ok = 0;
            break;
        }
    }
    if (ok) cout << "YES" << el;
    else cout << "NO" << el;
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