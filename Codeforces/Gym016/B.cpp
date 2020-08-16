#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 60;

int q;
int n;
pii ask(int i, int j){
    cout << "? " << i << " " << j << endl;
    char res;
    cin >> res;
    if (res == '<') return mp(i, j);
    return mp(j, i);
}

pii solve(int l, int r){
    if (l == r) return mp(l, l);
    else if (r - l == 1){
        pii ret = ask(l, r);
        return ret;
    }
    int m = (l + r) / 2;
    pii le = solve(l, m);
    pii ri = solve(m + 1, r);

    pii ret;
    ret.se = ask(le.se, ri.se).se;
    ret.fi = ask(le.fi, ri.fi).fi;
    return ret;
}

void query(){
    cin >> n;
    pii ans = mp(-1, -1);
    for (int i=5;i>=0;i--){
        int bit = (1 << i);
        pii cur;
        if (n >= bit){
            cur = solve(n - bit + 1, n);
            n -= bit;

            if (ans == mp(-1, -1)){
                ans = cur;
            } else{
                ans.fi = ask(ans.fi, cur.fi).fi;
                ans.se = ask(ans.se, cur.se).se;
            }
        }
    }
    cout << "! " <<  ans.fi << " " << ans.se << endl;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        query();
    }

    return 0;
}