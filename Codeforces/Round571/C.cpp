#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string s, t;
int slen, tlen;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;
    slen = s.length();
    tlen = t.length();
    s = "*" + s;
    t = "*" + t;

    int beda = 0;
    int cur = 0;
    for (int i=1;i<=tlen;i++){
        if (s[i] != t[i]) cur++;
        if (i != slen){
            if (s[i] != s[i + 1]) beda++;
        }
    }
    cur = (cur & 1);
    int ans = 0;
    for (int i=1;i + tlen - 1<=slen;i++){
        if (cur & 1 ^ 1) ans++;
        cur = (cur ^ (beda & 1));
        if (i + tlen + 1 <= slen){
            if (s[i + tlen] != s[i + tlen + 1]) beda++;
        }
        if (s[i] != s[i + 1]) beda--;
    }
    cout << ans << el;

    return 0;
}