#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e3 + 10;
const int INF = 1e8;

int q;
int n;
string command;

pii nextPos(pii cur, char c){
    if (c == 'L'){
        cur.fi--;
    } else if (c == 'R'){
        cur.fi++;
    } else if (c == 'D'){
        cur.se--;
    } else{ //if (c == 'U'){
        cur.se++;
    }
    return cur;
}
bool simulate(pii obs){
    pii cur = mp(0, 0);
    for (auto x : command){
        pii nx = nextPos(cur, x);
        if (nx != obs) cur = nx;
    }
    return cur == mp(0, 0);
}

void solve(){
    cin >> command;
    n = command.size();
    vector<pii> candidate;
    candidate.pb(mp(INF, INF));
    {
        pii cur = mp(0, 0);
        for (auto x : command){
            cur = nextPos(cur, x);
            if (cur != mp(0, 0)){
                candidate.pb(cur);
            }
        }
    }
    for (auto x : candidate){
        if (simulate(x)){
            cout << x.fi << " " << x.se << el;
            return;
        }
    }
    cout << 0 << " " << 0 << el;
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