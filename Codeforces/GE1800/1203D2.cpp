#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 2e5 + 10;

string s, t;
int slen, tlen;

int le[N], ri[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;
    slen = s.length();
    tlen = t.length();
    s = "*" + s;
    t = "*" + t;

    int cur = tlen;
    ri[tlen + 1] = slen + 1;
    for (int i=slen;i>0;i--){
        if (s[i] == t[cur]){
            ri[cur] = i;
            cur--;
        }
        if (cur == 0) break;
    }
    cur = 1;
    le[0] = 0;
    for (int i=1;i<=slen;i++){
        if (s[i] == t[cur]){
            le[cur] = i;
            cur++;
        }
        if (cur == tlen + 1) break;
    }

    int ans = 0;
    for (int i=0;i<=tlen;i++){
        ans = max(ans, ri[i+1] - le[i] - 1);
    }
    cout << ans << el;

    return 0;
}