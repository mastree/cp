#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const int N = 1e2 + 10;
const int MAXL = 1e3 + 10;
const int CORNER = 3;

int n, L;
int ar[N];
int dp[N][N][MAXL][CORNER];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> L;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    sort(ar + 1, ar + n + 1);
    dp[0][0][0][0] = 1;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            for (int k=0;k<L;k++){
                
            }
        }
    }

    return 0;
}