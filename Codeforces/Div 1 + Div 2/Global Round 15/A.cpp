#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int q;
int n;
string s;

void solve(){
    cin >> n >> s;
    int ans = 0;
    string ss = s;
    sort(ss.begin(), ss.end());
    for (int i=0;i<n;i++){
        if (ss[i] != s[i]) ans++;
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