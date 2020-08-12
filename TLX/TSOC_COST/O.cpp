#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 510;

int n = 500;
int ar[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            ar[i][j] = i + (j - 1) * 1000;
        }
    }
    freopen("astar.out", "w", stdout);
    cout << n << el;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout << ar[i][j] << " ";
        }
        cout << el;
    }

    return 0;
}