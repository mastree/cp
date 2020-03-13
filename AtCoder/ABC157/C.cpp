#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

const int N = 7;

int n, m;
int dig[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<N;i++){
        dig[i] = -1;
    }

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        if (a > n){
            cout << -1 << el;
            return 0;
        }
        if (dig[a] == -1) dig[a] = b;
        else if (dig[a] != b){
            cout << -1 << el;
            return 0;
        }
    }

    if (dig[1] <= 0){
        if (n > 1){
            if (dig[1] == 0) cout << -1 << el;
            else{
                cout << 1;
                for (int i=2;i<=n;i++){
                    cout << max(dig[i], 0);
                }
                cout << el;
            }
        } else{
            cout << 0 << el;
        }
        return 0;
    }

    for (int i=1;i<=n;i++){
        cout << max(dig[i], 0);
    }
    cout << el;

    return 0;
}