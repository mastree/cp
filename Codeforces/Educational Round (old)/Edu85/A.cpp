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

int q;
int n;
pii ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> ar[i].fi >> ar[i].se;
        }

        int lastp = 0, lastw = 0;
        bool bisa = 1;
        for (int i=1;i<=n;i++){
            if (ar[i].fi >= lastp && ar[i].se >= lastw && (ar[i].fi - lastp) >= (ar[i].se - lastw)){
                lastp = ar[i].fi;
                lastw = ar[i].se;
            } else{
                bisa = 0;
                break;
            }
        }
        if (bisa){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}