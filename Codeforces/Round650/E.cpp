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

const int N = 2e3 + 10;
const int M = 30;

int q;
int n, k;
string s;
int cnt[M];
bool bisa[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> k;
        cin >> s;
        s = "*" + s;
        fill(cnt, cnt + M, 0);
        fill(bisa, bisa + N, 0);

        int ans = 0;
        for (int i=1;i<=n;i++){
            int dig = (int)(s[i] - 'a');
            cnt[dig]++;
        }

        for (int i=1;i<=min(n, k);i++){
            if (k % i != 0) continue;

            int low = 1, high = n / i;
            while (low < high){
                int mid = (low + high + 1) / 2;
                int frag = i * mid;
                for (int j=0;j<26;j++){
                    int temp = cnt[j];
                    frag -= (temp / mid) * mid;
                }
                if (frag <= 0){
                    low = mid;
                } else{
                    high = mid - 1;
                }
            }
            ans = max(ans, low * i);
        }
        cout << ans << el;
    }

    return 0;
}