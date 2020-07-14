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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        int n, k;
        cin >> n >> k;

        if (k > n){
            cout << "NO" << el;
            continue;
        }
        if (n & 1){
            if (k & 1){
                cout << "YES" << el;
                for (int i=1;i<k;i++){
                    cout << 1 << " ";
                }
                cout << n - k + 1 << el;
            } else{
                cout << "NO" << el;
                continue;
            }
        } else{
            if (k & 1){
                if (k * 2 > n){
                    cout << "NO" << el;
                    continue;
                }
                cout << "YES" << el;
                for (int i=1;i<k;i++){
                    cout << 2 << " ";
                }
                cout << n - 2 * (k - 1) << el;
            } else{
                cout << "YES" << el;
                for (int i=1;i<k;i++){
                    cout << 1 << " ";
                }
                cout << n - k + 1 << el;
            }
        }
    }

    return 0;
}