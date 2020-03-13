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

const int N = 1e5 + 7;

int t, n;
ll ar[N];
ll pc[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--){
        cin >> n;

        ll tot = 0;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            tot+=ar[i];
        }

        for (int i=1;i<=n;i++){
            pc[i] = pc[i-1] + ar[i];
        }

        ll mn = 0;
        bool yes = 1;
        for (int i=1;i<n;i++){
            if (pc[i] - mn >= tot){
                yes = 0;
                break;
            }
            mn = min(mn, pc[i]);
        }

        if (!yes){
            cout << "NO" << el;
            continue;
        }

        for (int i=1;i<n;i++){
            if (pc[n] - pc[i] >= tot){
                yes = 0;
                break;
            }
        }
        if (yes){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}