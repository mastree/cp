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

const int N = 1e3 + 10;

int n;
map <int, int> cnt;
int ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        if (a) cnt[a]++;
    }

    for (auto x : cnt){
        if (x.se > 2){
            cout << -1 << el;
            return 0;
        }
        ans += (x.se==2);
    }

    cout << ans << el;

    return 0;
}