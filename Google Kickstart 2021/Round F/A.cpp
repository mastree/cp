#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e5 + 10;
const int INF = 1e9;

int q;
int n;
int ar[N];

void solve(){
    cin >> n;
    ll tot = 0;
    for (int i=1;i<=n;i++){
        char c;
        cin >> c;
        ar[i] = (c == '1');
    }
    vector<int> ans(n + 1, INF);
    int last = -INF;
    for (int i=1;i<=n;i++){
        if (ar[i]) last = i;
        ans[i] = min(ans[i], i - last);
    }
    last = INF + INF;
    for (int i=n;i>=1;i--){
        if (ar[i]) last = i;
        ans[i] = min(ans[i], last - i);
    }
    for (int i=1;i<=n;i++){
        tot += ans[i];
    }
    cout << tot << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}