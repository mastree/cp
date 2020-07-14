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

const int N = 2e5 + 10, M = 21;

int n;
int ar[N];
int bit[M];
ll ans = 0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int j=0;j<M;j++){
        bit[j] = (1 << j);
    }
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        for (int j=0;j<M;j++){
            if (ar[i] & bit[j]){
                cnt[j]++;
            }
        }
    }
    for (int i=1;i<=n;i++){
        ll cur = 0;
        for (int j=0;j<M;j++){
            if (cnt[j]){
                cur += (ll)bit[j];
                cnt[j]--;
            }
        }
        ans += cur * cur;
    }
    cout << ans << el;

    return 0;
}