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

const int N = 1e3 + 20;

int q;
int n, x;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> x;
        int od = 0, ev;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            if (ar[i] & 1){
                od++;
            }
        }
        ev = n - od;
        if (od == 0){
            cout << "NO" << el;
            continue;
        }
        if (ev >= x){
            cout << "YES" << el;
            continue;
        }
        x -= ev;
        if (od == x && od % 2 == 0){
            cout << "NO" << el;
        } else if (od == x){
            cout << "YES" << el;
        } else if (ev){
            cout << "YES" << el;
        } else if (x & 1){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}