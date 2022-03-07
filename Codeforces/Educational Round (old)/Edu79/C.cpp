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
int n, m;
int ar[N], b[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> m;

        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        for (int i=1;i<=m;i++){
            cin >> b[i];
        }

        map <int, bool> udah;
        ll ans = 0;
        ll id = 0, atas = 0;
        for (int i=1;i<=m;i++){
            if (udah[b[i]]){
                atas--;
            } else{
                while (ar[id] != b[i]){
                    id++;
                    atas++;
                    udah[ar[id]] = 1;
                }
                atas--;
                ans+=atas * 2;
            }
            // cout << ans << " ";
        }
        // cout << el;
        cout << ans + m << el;
    }

    return 0;
}