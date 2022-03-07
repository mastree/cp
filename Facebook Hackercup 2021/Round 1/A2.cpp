#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 8e5 + 10;
const int MOD = 1e9 + 7;

int q;
int n;
string s;

void solve(){
    cin >> n >> s;
    vector<char> vec;
    vec.pb('F');
    ll ans = 0;
    ll lasto = -1;
    ll lastx = -1;
    for (ll i=0;i<n;i++){
        if (s[i] == 'F') continue;
        if (vec.back() == s[i]){
            if (s[i] == 'O') lasto = i;
            else lastx = i;
            continue;
        }
        if (s[i] == 'O'){
            if (lastx != -1){
                ans = (ans + (lastx + 1) * ((ll)n - i)) % MOD;
            }
            lasto = i;
        } else{
            if (lasto != -1){
                ans = (ans + (lasto + 1) * ((ll)n - i)) % MOD;
            }
            lastx = i;
        }
        vec.pb(s[i]);
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