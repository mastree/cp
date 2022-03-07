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

int q;
int n;
ll ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;

        ll tot = 0;
        ll xr = 0;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            tot+= ar[i];
            xr^= ar[i];
        }

        // if (xr==0){
        //     cout << 1 << el;
        //     cout << tot << el;
        //     continue;
        // }
        cout << 2 << el;
        cout << xr << " " << tot+xr << el;
    }

    return 0;
}