#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 100;

int q;
int n;
bool mat[N][N];
string in, out;

void solve(){
    cin >> n;
    cin >> in >> out;
    in = "*" + in;
    out = "*" + out;
    for (int i=1;i<=n;i++){
        fill(mat[i], mat[i] + n + 2, 0);
    }
    for (int i=1;i<=n;i++){
        for (int j=max(1, i - 1);j<=min(n, i + 1);j++){
            if (i == j) mat[i][j] = 1;
            else{
                if (out[i] == 'Y' && in[j] == 'Y') mat[i][j] = 1;
                else mat[i][j] = 0;
            }
        }
    }
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                mat[i][j] |= (mat[i][k] & mat[k][j]);
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (mat[i][j]) cout << 'Y';
            else cout << 'N';
        }
        cout << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("travel_restrictions_input.txt", "r", stdin);
    freopen("A.out", "w", stdout);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ":\n";
        solve();
    }

    return 0;
}