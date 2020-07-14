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

const int N = 100;

int q, n;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        int od = 0, ev = 0;
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            if (ar[i] & 1) od++;
            else ev++;
        }
        if ((od + ev) & 1){
            cout << "NO" << el;
            continue;
        }
        if (od % 2 == 0){
            cout << "YES" << el;
            continue;
        }
        bool bisa = 0;
        sort(ar + 1, ar + n + 1);
        for (int i=1;i<n;i++){
            if (ar[i + 1] - ar[i] == 1) bisa = 1;
        }
        if (bisa){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}