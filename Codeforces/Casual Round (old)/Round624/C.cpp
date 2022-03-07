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

int q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        int n, m;
        cin >> n >> m;

        string s;
        // ll ar[m + 5];
        ll tony[n + 5];
        ll ans[26];
        
        fill(tony, tony + n + 5, 0);
        fill(ans, ans + 26, 0);
        cin >> s;
        s = "*" + s;
        for (int i=1;i<=m;i++){
            // cin >> ar[i];
            int a;
            cin >> a;
            tony[1]++;
            tony[a + 1]--;
        }
        tony[1]++;
        tony[n+1]--;

        ll cur = 0;
        for (int i=1;i<=n;i++){
            cur += tony[i];
            int dig = s[i] - 'a';
            ans[dig] += cur;
        }

        for (int i=0;i<26;i++){
            cout << ans[i] << " ";
        }
        cout << el;

    }

    return 0;
}