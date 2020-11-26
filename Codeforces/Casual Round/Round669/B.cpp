#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e3 + 10;

int q;
int n;
int ar[N];
bool udh[N];

void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    sort(ar + 1, ar + n + 1, greater<int>());
    int cur = 0;
    fill(udh, udh + n + 2, 0);
    vector<int> ans;
    for (int i=1;i<=n;i++){
        pii mx = mp(0, -1);
        for (int j=1;j<=n;j++){
            if (!udh[j] && __gcd(cur, ar[j]) > mx.fi){
                mx = mp(__gcd(cur, ar[j]), j);
            }
        }
        udh[mx.se] = 1;
        ans.pb(ar[mx.se]);
        cur = mx.fi;
    }
    for (auto x : ans) cout << x << " ";
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