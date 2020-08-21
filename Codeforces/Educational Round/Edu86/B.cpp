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

const int N = 110;

int n, q;
string t;
int ar[N];
int ans[2 * N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> t;
        n = t.length();
        int c0 = 0, c1 = 0;
        for (int i=1;i<=n;i++){
            ar[i] = (t[i - 1] == '1');
            if (ar[i]) c1++;
            else c0++;
        }
        if (!c0){
            cout << t << el;
            continue;
        } else if (!c1){
            cout << t << el;
            continue;
        }
        for (int i=1;i<=n;i++){
            cout << 1 << 0;
        }
        cout << el; 

    }

    return 0;
}