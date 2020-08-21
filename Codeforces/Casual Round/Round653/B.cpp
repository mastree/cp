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
int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        int c3 = 0, c2 = 0;
        while (n % 3 == 0){
            c3++;
            n /= 3;
        }
        while (n % 2 == 0){
            c2++;
            n /= 2;
        }
        if (n != 1){
            cout << -1 << el;
            continue;
        }
        if (c2 > c3){
            cout << -1 << el;
            continue;
        }
        cout << c3 + (c3 - c2) << el;
    }

    return 0;
}