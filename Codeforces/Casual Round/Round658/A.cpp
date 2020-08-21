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

int q, n;
string a, b;

char flip(char c){
    if (c == '1') return '0';
    return '1';
}

void solve(){
    cin >> n;
    cin >> a >> b;
    vector<int> ans;
    bool on = 0;

    for (int i=n - 1;i>=0;i--){
        if (!on){
            if (a[0] == b[i]){
                a[0] = flip(a[0]);
                ans.pb(1);
            }
            ans.pb(i + 1);
            reverse(a.begin(), a.begin() + i + 1);
            // for (int j=0;j<i + 1;j++){
            //     a[j] = flip(a[j]);
            // }
        } else{

        }
        // cout << a << el;
    }
    cout << ans.size() << " ";
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