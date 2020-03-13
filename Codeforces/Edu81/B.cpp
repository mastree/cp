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

const int N = 1e5 + 1;

int t;
int n, x;
string s;
int ar_[N * 2 + 7];
int * ar = ar_ + N;
bool yes_[N * 2 + 7];
bool * yes = yes + N;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    // cout << (-5) % (-3) << el;
    while (t--){
        cin >> n >> x;
        cin >> s;

        // cout << s << el;
        for (int i=-n;i<=n;i++){
            ar[i] = 0;
            // yes[i] = 0;
        }
        int tot=0;
        int ans = 0;
        for (int i=0;i<n;i++){
            if (s[i] == '0'){
                tot++;
            }
            else{
                tot--;
            }
            ar[tot]++;
        }
        // cout << tot << " " << x << el;
        if (x == 0){
            if (tot == 0){
                cout << -1 << el;
                continue;
            }
            ans++;
        }

        if (tot == 0){
            if (abs(x) < N){
                if (ar[x]){
                    cout << -1 << el;
                    continue;
                } 
            }
            cout << 0 << el;
            continue;
        }

        // if ((tot > 0 && x < 0) || (tot < 0 && x > 0)){
        //     if (abs(x) < N){
        //         cout << ar[x] << el;
        //         continue;
        //     } else{
        //         cout << 0 << el;
        //         continue;
        //     }
        // }

        for (int i=-n;i<=n;i++){
            int sisa = x - i;
            if ((sisa >= 0 && tot >= 0) || (sisa <= 0 && tot <= 0)){
                if (sisa % tot == 0) ans += ar[i];
            }
        }
        cout << ans << el;
    }

    return 0;
}