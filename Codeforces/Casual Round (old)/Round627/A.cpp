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

const int N = 1e2 + 10;

int q, n;
// int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        int x = 0;
        for (int i=0;i<n;i++){
            int a;
            cin >> a;
            x += (a % 2);
        }

        if (x == n || x == 0){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}