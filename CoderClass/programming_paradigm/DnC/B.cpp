#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10, MX = 1e6 + 10;

int n, q;
bool ada[MX];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        ada[a] = 1;
    }
    while (q--){
        int a;
        cin >> a;
        if (ada[a]) cout << "ada" << el;
        else cout << "tidak ada" << el;
    }

    return 0;
}