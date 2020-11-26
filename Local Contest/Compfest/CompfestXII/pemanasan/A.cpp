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

int n, k;
int a[N], b[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        int temp;
        cin >> temp;
        a[temp]++;
    }
    for (int i=1;i<=n;i++){
        int temp;
        cin >> temp;
        b[temp]++;
    }
    bool ok = 1;
    for (int i=1;i<N;i++){
        if ((a[i] + b[i]) > n + k) ok = 0;
    }
    cout << (ok ? "Ya" : "Tidak") << el;

    return 0;
}