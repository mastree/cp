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
const ll INF = 1e18;

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
    ll id = -1;
    ll cur = 0, cnt = 0, cnttimes = 0;
    char fst = 'F';
    char lst = 'F';
    ll fpos = -1;
    for (auto& x : s){
        // cout << id << " " << x << " " << ans << el;
        // cout << "lasto: " << lasto << el;
        // cout << "lastx: " << lastx << el;
        // cout << id << " => " << ans << " " << cur << " " << cnt << " " << cnttimes << el;
        if (x == '.'){
            ll len = (id + 1) % MOD;
            ans = ((ans + cur * len) % MOD + (ans + cnttimes * len) % MOD) % MOD;
            cur = (cur + cur + cnt * len) % MOD;
            cnttimes = (cnttimes + cnt * len % MOD + cnttimes) % MOD;
            cnt = (cnt + cnt) % MOD;
            if (fst == 'O' && lastx != -1 && lst != fst){
                ans = (ans + (lastx + 1) * (len - fpos + MOD) % MOD) % MOD;
                cur = (cur + lastx + 1) % MOD;
                cnt = (cnt + 1) % MOD;
                cnttimes = (cnttimes + (len - fpos + MOD)) % MOD;
            } else if (fst == 'X' && lasto != -1 && lst != fst){
                ans = (ans + (lasto + 1) * (len - fpos + MOD) % MOD) % MOD;
                cur = (cur + lasto + 1) % MOD;
                cnt = (cnt + 1) % MOD;
                cnttimes = (cnttimes + (len - fpos + MOD)) % MOD;
            }
            if (lasto != -1) lasto = (lasto + len) % MOD;
            if (lastx != -1) lastx = (lastx + len) % MOD;
            id = (id + len) % MOD;
            continue;
        }
        id = (id + 1) % MOD;
        if (x == 'F'){
            ans = (ans + cur) % MOD;
            cnttimes = (cnttimes + cnt) % MOD;
            continue;
        }
        if (vec.back() == x){
            if (x == 'O') lasto = id;
            else lastx = id;
            ans = (ans + cur) % MOD;
            cnttimes = (cnttimes + cnt) % MOD;
            continue;
        }
        if (x == 'O'){
            if (lastx != -1){
                cur = (cur + lastx + 1) % MOD;
                cnt = (cnt + 1) % MOD;
            }
            lasto = id;
        } else{
            if (lasto != -1){
                cur = (cur + lasto + 1) % MOD;
                cnt = (cnt + 1) % MOD;
            }
            lastx = id;
        }
        if (fst == 'F'){
            fst = x;
            fpos = id;
        }
        lst = x;
        ans = (ans + cur) % MOD;
        cnttimes = (cnttimes + cnt) % MOD;
        vec.pb(x);
    }
    // cout << id << " => " << ans << " " << cur << " " << cnt << " " << cnttimes << el;
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