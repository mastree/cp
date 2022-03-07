#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 1e5 + 10;
const int P = 7;

int n, p, k;
ll a[N];
ll s[N][P];

ll dp[N][(1 << P)];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p >> k;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }

    for (int i=1;i<=n;i++){
        for (int j=0;j<p;j++){
            cin >> s[i][j];
        }
    }



    return 0;
}