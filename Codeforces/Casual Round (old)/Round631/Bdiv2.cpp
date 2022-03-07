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
int n;
int ar[N];
int cnt[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;

        fill(cnt, cnt + n + 1, 0);
        bool bisa = 1;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            if (++cnt[ar[i]] == 3){
                bisa = 0;
            }
        }
        if (cnt[1] <= 1){
            bisa = 0;
        }
        if (!bisa){
            cout << 0 << el;
            continue;
        }

        int last = 1;
        for (int i=2;i<=n;i++){
            if (cnt[i] > cnt[i - 1]){
                bisa = 0;
                break;
            }

            if (cnt[i] == 2) last = i;
        }
        if (!bisa){
            cout << 0 << el;
            continue;
        }

        vector <pii> ans;
        bool ada[n + 2];
        fill(ada, ada + n + 2, 0);
        for (int i=1;i<=last;i++){
            ada[ar[i]] = 1;
        }
        for (int i=1;i<=last;i++){
            if (!ada[i]){
                bisa = 0;
                break;
            }
        }
        if (bisa){
            ans.pb(mp(last, n - last));
        }
        if (last != n - last){
            bisa = 1;
            fill(ada, ada + n + 2, 0);
            for (int i=n;i>n - last;i--){
                ada[ar[i]] = 1;
            }
            for (int i=1;i<=last;i++){
                if (!ada[i]){
                    bisa = 0;
                    break;
                }
            }
            if (bisa){
                ans.pb(mp(n - last, last));
            }
        }
        cout << ans.size() << el;
        for (auto x : ans){
            cout << x.fi << " " << x.se << el;
        }
    }

    return 0;
}