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
void solve(){
    string s, t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    
    int slen = s.size();
    int tlen = t.size();
    int cur = 0;
    for (int i=0;i<slen;i++){
        if (cur < tlen && s[i] == t[cur]){
            cur++;
        } else{
            i++;
        }
        if (cur == tlen) break;
    }
    if (cur == tlen) cout << "YES" << el;
    else cout << "NO" << el;
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