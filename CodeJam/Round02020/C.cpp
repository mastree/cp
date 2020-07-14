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

int q;
int n;
pair<pii, int> ar[N];
char ans[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int cas=1;cas<=q;cas++){
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> ar[i].fi.fi >> ar[i].fi.se;
            ar[i].se = i;
        }
        sort(ar + 1, ar + n + 1);

        int curC = 0;
        int curJ = 0;
        int bisa = 1;
        for (int i=1;i<=n;i++){
            if (ar[i].fi.fi >= curC){
                curC = ar[i].fi.se;
                ans[ar[i].se] = 'C';
            } else if (ar[i].fi.fi >= curJ){
                curJ = ar[i].fi.se;
                ans[ar[i].se] = 'J';
            } else{
                bisa = 0;
                break;
            }
        }

        cout << "Case #" << cas << ": ";
        if (bisa){
            for (int i=1;i<=n;i++){
                cout << ans[i];
            }
            cout << el;
        } else{
            cout << "IMPOSSIBLE" << el;
        }
    }

    return 0;
}