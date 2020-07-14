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

const int N = 2e5 + 10;

int n;
int ar[N], br[N], pos[N];
int _cnt[N + N];
int * cnt = _cnt + N;

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
        pos[br[i]] = i;
    }
    for (int i=1;i<=n;i++){
        int temp = (pos[ar[i]] - i + n) % n;
        cnt[temp]++;
    }
    int ans = 0;
    for (int i=0;i<=n;i++){
        ans = max(ans, cnt[i]);
    }
    cout << ans << el;

    return 0;
}