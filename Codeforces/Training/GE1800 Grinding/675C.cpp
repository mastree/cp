#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

const int N = 1e5 + 10;

int n;
ll ar[N];
ll pc[N];
map<ll, int> cek;
int ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=n;i++){
        pc[i] = pc[i - 1] + ar[i];
    }
    ans = n - 1;
    for (int i=1;i<=n;i++){
        cek[pc[i]]++;
        ans = min(ans, n - cek[pc[i]]);
    }
    cout << ans << el;

    return 0;
}