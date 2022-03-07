#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

int n, m;
int ar[N], pre[N];
int ada[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        ar[i] = a % m;
        pre[i] = (pre[i - 1] + ar[i]) % m;
    }
    fill(ada, ada + N, -1);
    int l = -1, r = -1;
    for (int i=1;i<=n;i++){
        ada[pre[i - 1]] = i - 1;
        int but = pre[i];
        if (ada[but] != -1){
            l = ada[but] + 1;
            r = i;
            break;
        }
    }
    if (l == -1){
        cout << -1 << el;
        return 0;
    }
    cout << r - l + 1 << el;
    for (int i=l;i<=r;i++){
        cout << i << ' ';
    }
    cout << el;

    return 0;
}