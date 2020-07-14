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

const int N = 1e6 + 10;
const int INF = 1e9;

int q;
int n, k;
string s;
int ar[N];
int pc[N];
int dp[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> k;
        cin >> s;
        int l = 0, r = n - 1;
        while (l != n && s[l] != '1') l++;
        while (r != -1 && s[r] != '1') r--;
        if (l >= r){
            cout << 0 << el;
            continue;
        }
        n = r - l + 1;
        for (int i=1;i<=n;i++){
            ar[i] = (s[l + i - 1] == '1');
        }
        fill(pc, pc + n + 2, 0);
        for (int i=1;i<=n;i++){
            pc[i] = pc[i - 1] + ar[i];
        }
        if (n <= k){
            cout << max(0, pc[n] - 1) << el;
            continue;
        }
        int ans = INF;
        for (int mul=1;mul<=k;mul++){
            int cur = 0;
            int i;
            for (i=mul;i<=n;i+=k){
                int le = max(1, i - k + 1);
                int bayar = pc[i - 1] - pc[le - 1];
                if (ar[i] == 0) bayar++;
                cur += bayar;
                cur = min(cur, pc[i - 1] + (ar[i] == 0));
                ans = min(ans, cur + pc[n] - pc[i]);
            }
            if (i != n){
                cur += pc[n] - pc[max(i - k, 0)];
            }
            cur = min(cur, pc[n]);
            ans = min(ans, cur);
        }
        cout << ans << el;
    }

    return 0;
}