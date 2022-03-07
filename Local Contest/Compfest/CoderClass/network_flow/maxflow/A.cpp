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

int n;
int ar[N], br[N];
int pen[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=n;i++){
        cin >> br[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> pen[i][j];
        }
    }

    return 0;
}