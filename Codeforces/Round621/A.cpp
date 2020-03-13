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
int n, d;
int ar[110];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> d;
        for (int i=0;i<n;i++){
            cin >> ar[i];
        }
        int ans = ar[0];
        for (int i=1;i<n;i++){
            if (d>0){
                ans += min(ar[i], d/i);
                d -= ar[i] * i;
            }
        }
        cout << ans << el;
    }

    return 0;
}