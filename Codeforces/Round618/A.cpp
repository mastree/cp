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

const int N = 200;

int q, n;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        int c0 = 0, tot = 0;
        for (int i=0;i<n;i++){
            cin >> ar[i];
            tot+=ar[i];
            if (ar[i] == 0){
                c0++;
            }
        }

        if (c0){
            int ans = c0;
            tot += c0;
            if (tot == 0) ans++;
            cout << ans << el;
        } else{
            if (tot == 0){
                cout << 1 << el;
            } else{
                cout << 0 << el;
            }
        }
    }

    return 0;
}