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

const int N = 5010;

int q, n;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;

        fill(ar, ar + n + 1, 0);
        bool bisa = 0;
        int last = 0;
        for (int i=1;i<=n;i++){
            int a;
            cin >> a;
            if (ar[a] == 0){
                ar[a]++;
            } else{
                if (ar[a] >= 2){
                    ar[a]++;
                    bisa = 1;
                } else{
                    if (last != a) bisa = 1;
                    ar[a]++;
                }
            }

            last = a;
        }

        if (bisa){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}