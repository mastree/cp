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

int q;
int n;

void solve(){
    cin >> n;
    string ans;
    for (int i=0;i<n;i++){
        ans.pb('9');
    }
    int id = n - 1;
    int sisa = n;
    while (sisa >= 4){
        ans[id] = '8';
        id--;
        sisa -= 4;
    }
    if (sisa) ans[id] = '8';
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