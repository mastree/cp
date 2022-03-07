#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string VOW = "AIUEO";
int q;

bool is_vow(const char& c){
    for (auto& x : VOW) if (c == x) return 1;
    return 0;
}

void solve(){
    string s;
    cin >> s;
    int ans = s.size() * 2;
    for (char i='A';i<='Z';i++){
        bool tar = is_vow(i);
        int cur = 0;
        for (auto& x : s){
            if (x == i) continue;
            if (is_vow(x) == tar) cur += 2;
            else cur += 1;
        }
        ans = min(ans, cur);
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