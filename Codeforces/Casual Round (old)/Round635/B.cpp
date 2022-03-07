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
int x, n, m;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> x >> n >> m;

        while (n > 0){
            int nx = (x / 2) + 10;
            if (nx < x){
                x = nx;
                n--;
            } else break;
        }
        x = x - 10 * m;
        if (x > 0){
            cout << "NO" << el;
        } else{
            cout << "YES" << el;
        }
    }

    return 0;
}