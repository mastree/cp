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
    int slen = s.size();
    int tlen = t.size();
    vector<int> le(slen + 2, 0), ri(slen + 2, 0);
    for (int i=0;i<slen;i++){
        int cur = 0;
        for (int j=0;j<tlen;j++){
            if (i + j < slen && s[i + j] == t[j]) cur++;
            else break;
        }
        le[i + 1] = cur;
    }
    for (int i=0;i<slen;i++){
        int cur = 0;
        for (int j=0;j<tlen;j++){
            if (i + j < slen && s[i + j] == t[tlen - j - 1]) cur++;
            else break;
        }
        ri[i + 1] = cur;
    }
    bool ok = 0;
    for (int i=1;i<=slen;i++){
        for (int j=1;j<=tlen;j++){
            if (i + j - 1 <= slen && le[i] >= j){
                int kur = tlen - j;
                if (i + j - kur - 1 >= 1 && ri[i + j - kur - 1] >= kur){
                    ok = 1;
                    break;
                }
            }
        }
        if (ok) break;
    }
    if (ok) cout << "YES" << el;
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