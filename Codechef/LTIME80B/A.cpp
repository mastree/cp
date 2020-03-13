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

const int N = 110;

int q;
int s[N], v[N], p[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        int n;
        
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> s[i] >> p[i] >> v[i];
        }
        // for (int i=1;i<=n;i++){
        //     cin >> v[i];
        // }
        // for (int i=1;i<=n;i++){
        //     cin >> p[i];
        // }

        int ans = 0;
        for (int i=1;i<=n;i++){
            int cur = p[i] / (s[i] + 1);
            cur *= v[i];
            ans = max(ans, cur);
        }
        cout << ans << el;
    }

    return 0;
}