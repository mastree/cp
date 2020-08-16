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
string s;

void solve(){
    cin >> n;
    cin >> s;

    // s = "*" + s;
    if (1){
        int id = -1;
        for (int i=0;i<n;i++){
            if (s[i] != s[(i - 1 + n) % n]){
                id = i;
                break;
            }
        }
        if (id != -1){
            string temp = s;
            for (int i=0;i<n;i++){
                s[i] = temp[(id + i) % n];
            }
        } else{
            cout << (n + 2) / 3 << el;
            return; 
        }
    }
    vector<int> v;
    int cur = 0;
    char bef = '*';
    for (int i=0;i<n;i++){
        if (bef == '*'){
            cur = 1;
            bef = s[i];
            continue;
        }
        if (bef == s[i]){
            cur++;
        } else{
            v.pb(cur);
            cur = 1;
            bef = s[i];
        }
    }
    v.pb(cur);
    int ans = 0;
    for (auto x : v){
        if (x > 2) ans += x / 3; 
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