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

const int N = 1e5 + 10;

int q, n;
int ar1[N], ar2[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> ar1[i];
        }
        for (int i=1;i<=n;i++){
            cin >> ar2[i];
        }

        bool _ada[3] = {0, 0, 0};
        bool * ada = _ada + 1;
        // cout << ada[-1] << " " << ada[0] << " " << ada[1] << el;
        bool bisa = 1;
        for (int i=1;i<=n;i++){
            // cout << ar1[i] << " " << ar2[i] << el;
            if (ar1[i] == ar2[i]){
                ada[ar1[i]] = 1;
            } else if (ar1[i] < ar2[i]){
                if (ada[1]){
                    ada[ar1[i]] = 1;
                } else{
                    bisa = 0;
                    break;
                }
            } else{
                if (ada[-1]){
                    ada[ar1[i]] = 1;
                } else{
                    bisa = 0;
                    break;
                }
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