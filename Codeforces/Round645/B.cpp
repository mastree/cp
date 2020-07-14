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
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        sort(ar + 1, ar + n + 1);
        int ans = 1;
        int carry = 0;
        // int mx = 0;
        for (int i=1;i<=n;i++){
            if (carry + ans >= ar[i]){
                ans += carry + 1;
                carry = 0;
                // mx = 0;
            } else{
                carry++;
            }
        }
        cout << ans << el;
    }

    return 0;
}