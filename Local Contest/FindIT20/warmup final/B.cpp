#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if (n & 1){
        for (int i=n - 1;i>=0;i--){
            for (int j=0;j<i;j++){
                cout << ' ';
            }
            for (int j=0;j<2 * n - i - i - 1;j++){
                cout << '&';
            }
            for (int j=0;j<i;j++){
                cout << ' ';
            }
            cout << ' ' << el;
        }
    } else{
        for (int i=n - 1;i>=0;i--){
            for (int j=0;j<i;j++){
                cout << '*';
            }
            for (int j=0;j<2 * n - i - i - 1;j++){
                cout << '#';
            }
            for (int j=0;j<i;j++){
                cout << ' ';
            }
            cout << ' ' << el;
        }
    }

    return 0;
}