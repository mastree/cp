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

const int N = 50;

int q;
int n;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        int od = 0, ev = 0;

        for (int i=0;i<n;i++){
            cin >> ar[i];
            ar[i] = (ar[i] & 1);
            if (ar[i]){
                od++;
            } else{
                ev++;
            }
        }
        if ((n + 1) / 2 != ev || n / 2 != od){
            cout << -1 << el;
            continue;
        }
        int ans = 0;
        for (int i=0;i<n;i++){
            if (ar[i] && i % 2 == 0) ans++;
        }
        cout << ans << el;
    }

    return 0;
}