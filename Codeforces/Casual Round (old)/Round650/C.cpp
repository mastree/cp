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

int q;
int n, k;
string s;

int ri[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> k;

        cin >> s;
        s = "*" + s;
        fill(ri, ri + n + 2, MOD);
        for (int i=n;i>=1;i--){
            if (s[i] == '1') ri[i] = i;
            else ri[i] = ri[i + 1];
        }
        int last = -MOD;
        int ans = 0;
        for (int i=1;i<=n;i++){
            if (s[i] == '1') last = i;
            if (i - last > k && ri[i] - i > k){
                last = i;
                ans++;
            }
        }
        cout << ans << el;
    }

    return 0;
}