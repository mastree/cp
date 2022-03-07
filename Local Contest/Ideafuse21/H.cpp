#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 10;
const int M = 4e4 + 10;
const int ALP = 26;

int q;
int n, r, c, m;
vector<string> vec;
vector<int> cr(ALP), cc (ALP);

void solve(){
    cin >> n >> r >> c >> m;
    r--;
    c--;
    vec.clear();
    cr.assign(ALP, 0);
    cc.assign(ALP, 0);
    for (int i=0;i<m;i++){
        string s;
        cin >> s;
        vec.pb(s);
    }
    for (auto& s : vec){
        cr[s[r] - 'A']++;
        cc[s[c] - 'A']++;
    }
    int ans = 0;
    for (auto& s : vec){
        int digr = s[r] - 'A';
        int digc = s[c] - 'A';
        cc[digc]--;
        ans += cc[digr];
        cc[digc]++;
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