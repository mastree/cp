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
    int n;
    cin >> n;
    bool swap = 0;
    vector<int> totab(2, 0), totdice(2, 0);
    for (int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        totab[0] += a;
        totab[1] += b;
        if (swap){
            totdice[0] += (b == 6);
            totdice[1] += (a == 6);   
        } else{
            totdice[0] += (a == 6);
            totdice[1] += (b == 6);
        }
        if (totab[0] != totab[1]) swap = !swap;
    }
    if (totdice[0] >= totdice[1]) cout << 1 << el;
    else cout << 2 << el;
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