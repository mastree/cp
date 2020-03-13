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

int n, m;
int ar1[2007], ar2[2007];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> ar1[i];
    }
    for (int i=0;i<n;i++){
        cin >> ar2[i];
    }

    sort(ar1, ar1 + n);
    sort(ar2, ar2 + n);

    // int id1=0;
    int ans=MOD;
    for (int mul=0;mul<n;mul++){
        int id1 = mul;
        int dif = (ar2[0] - ar1[id1] + m) % m;
        bool sama=1;
        for (int id2=0;id2<n;id2++){
            // cout << (ar1[id1]+dif) % m << " ";
            if (ar2[id2] != (ar1[id1] + dif) % m){
                sama = 0;
                break;
            }

            id1++;
            id1%=n;
        }
        // cout << el;
        if (sama) ans = min(ans, dif);
    }

    cout << ans << el;

    return 0;
}