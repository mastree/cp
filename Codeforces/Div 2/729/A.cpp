#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int q;
int n;
int ar[N];

void solve(){
    cin >> n;
    n = n * 2;
    int od = 0, ev = 0;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        if (a & 1) od++;
        else ev++;
    }
    if (od == ev){
        cout << "Yes" << el;
    } else{
        cout << "No" << el;
    }
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