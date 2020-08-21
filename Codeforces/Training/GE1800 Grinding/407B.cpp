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

const int N = 1e3 + 7;
const ll MOD = 1e9 + 7;

int n;
int ar[N];
ll dp[N];
ll pc[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }

    dp[1] = 2;
    pc[1] = 2;
    for (int i=2;i<=n;i++){
        dp[i] = ((pc[i-1] - pc[ar[i]-1] + MOD) % MOD + 2) % MOD;
        pc[i] = (dp[i] + pc[i-1]) % MOD;
    }
    cout << pc[n] << el;

    return 0;
}