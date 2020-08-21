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
ll n, k;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> k;

        ll len = 2;
        while (len * (len - 1LL) / 2LL < k){
            len++;
        }
        // len--;

        char ans[n];
        fill(ans, ans + n, 'a');
        ans[len - 1] = 'b';
        ll lebih = len * (len - 1LL) / 2LL - k;
        int id = len - 2;
        // cout << lebih << el;
        while (lebih){
            lebih--;
            id--;
        }   
        ans[id] = 'b';
        for (int i=n - 1;i>=0;i--){
            cout << ans[i];
        }
        cout << el;
    }

    return 0;
}