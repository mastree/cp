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

int n;
int nx[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        nx[i] = a;
    }
    bool ada = 0;
    for (int i=1;i<=n;i++){
        if (nx[nx[nx[i]]] == i) ada = 1;
    }
    if (ada) cout << "YES" << el;
    else cout << "NO" << el;

    return 0;
}