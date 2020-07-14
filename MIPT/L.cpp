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
int n, k;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> k;
        if (n == 1){
            cout << 0 << el;
            continue;
        }
        if (k == 1){
            cout << -1 << el;
            continue;
        }

        set<int> fac;
        int ans = 0;
        for (int i=1;i * i <= n;i++){
            if (n % i == 0){
                int j = n / i;
                fac.insert(i);
                fac.insert(j);
            }
        }
        bool bisa = 1;
        while (n > 1){
            auto it = fac.upper_bound(k);
            it--;
            if (*it == 1){
                bisa = 0;
                break;
            }
            ans++;
            n /= *it;
            fac.clear();
            for (int i=1;i * i <= n;i++){
                if (n % i == 0){
                    int j = n / i;
                    fac.insert(i);
                    fac.insert(j);
                }
            }
        }
        if (!bisa){
            cout << -1 << el;
            continue;
        }
        cout << ans << el;
    }   

    return 0;
}