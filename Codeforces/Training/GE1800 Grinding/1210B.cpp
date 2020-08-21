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

const int N = 7010;

map <ll, int> cnt;

int n;
ll ar[N], br[N];

bitset <N> bit[N];
bitset <N> res;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        cnt[ar[i]]++;
    }
    for (int i=1;i<=n;i++){
        cin >> br[i];
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if ((ar[i] | ar[j]) == ar[i]){
                bit[i][j] = 1;
            } else{
                bit[i][j] = 0;
            }
        }
    }

    for (int i=1;i<=n;i++){
        if (cnt[ar[i]] >= 2){
            res = (res | bit[i]);
        }
    }

    ll ans = 0;
    for (int i=1;i<=n;i++){
        if (res[i]){
            ans += br[i];
        }
    }
    cout << ans << el;

    return 0;
}