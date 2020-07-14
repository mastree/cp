#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
// #define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 3e3 + 10;
const ll MOD = 998244353;

int n, s;
int ar[N];

int cnt[N];
ll dp[N][N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }

    for (int i=1;i<=n;i++){
        fill(cnt, cnt + N, 0);
        cnt[0] = 1;
        for (int j)
    }

    return 0;
}