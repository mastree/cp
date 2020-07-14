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

const int N = 2e5 + 10;

int n;
ll ar[N];
ll pc[N];

map <ll, ll> cnt;
ll ans;
ll salah;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=n;i++){
        pc[i] = pc[i - 1] + ar[i];
    }

    int l = 1;
    // vector <pii> v;
    cnt[0] = 1;
    for (int r=1;r<=n;r++){
        if (++cnt[pc[r]] == 2){
            // cout << cnt[pc[r]] << el;
            salah++;

            while (salah){
                if (--cnt[pc[l - 1]] == 1){
                    salah--;
                }
                l++;
            }
        }
        // cout << l << " " << r << el;
        if (l <= r){
            ans += r - l + 1;
        }

    }

    cout << ans << el;

    return 0;
}