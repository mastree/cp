#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 55;
const string poss = "Possible";
const string imposs = "Impossible";

int q;
int n, m, a, b;

void solve(){
    cin >> n >> m >> a >> b;
    vector<vector<int>> mat(n + 1, vector<int>(m + 1, 1));
    a -= n + m - 1;
    b -= n + m - 1;
    if (a < 0 || b < 0){
        cout << imposs << el;
        return;
    }
    cout << poss << el;
    mat[n][m] += a;
    mat[n][1] += b;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cout << mat[i][j] << ' ';
        }
        cout << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}