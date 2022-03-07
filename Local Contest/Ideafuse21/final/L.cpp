#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 110;

int q;
int n;
int ar[N];

void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    sort(ar + 1, ar + n + 1, greater<int>());
    int ans = 0;
    vector<int> vec;
    for (int i=1;i<=n;i++){
        ans += ar[i];
        if (ar[i] & 1) vec.pb(ar[i]);
    }
    if (ans & 1){
        ans -= vec.back();
    }
    cout << ans << el;
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