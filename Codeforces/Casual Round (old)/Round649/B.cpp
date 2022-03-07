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

const int N = 1e5 + 10;

int q;
int n;
ll ar[N];
bool stat[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            if (i > 1){
                if (ar[i] == ar[i - 1]) stat[i] = stat[i - 1];
                else{
                    stat[i] = (ar[i] > ar[i - 1]);
                }
            }
        }
        // stat[1] = stat[2];
        ll ans = 0;
        // ll last = ar[i];
        // for (int i=2;i<=n;i++){
        //     cout << stat[i] << " ";
        // }
        // cout << el;
        vector<int> vans;
        vans.pb(ar[1]);
        for (int i=2;i<n;i++){
            if (stat[i] != stat[i + 1]){
                vans.pb(ar[i]);
            }
        }
        vans.pb(ar[n]);
        cout << vans.size() << el;
        for (auto x : vans){
            cout << x << " ";
        }
        cout << el;

        // int lastid = 1;
        // bool naik = 1;
        // for (int i=2;i<=n;i++){
        //     if (naik){
        //         if (ar[i] >= ar[i - 1]) continue;
        //         ans += abs(ar[i - 1] - ar[]);
        //     }
        // }
    }

    return 0;
}