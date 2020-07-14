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

const int N = 1e3 + 10;
const int INF = 1e9;

int q;
int n;
string s;
int ar[N], pc[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> s;
        n = s.length();
        for (int i=1;i<=n;i++){
            ar[i] = (s[i - 1] == '1');
            pc[i] = pc[i - 1] + ar[i];
        }
        int ans = INF;
        for (int i=1;i<=n;i++){
            // cout << pc[i] << " ";
            // 10
            ans = min(ans, i - pc[i] + (pc[n] - pc[i]));
            // 01
            ans = min(ans, pc[i] + ((n - i) - (pc[n] - pc[i])));
        }
        cout << ans << el;
    }

    return 0;
}