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

int x, y, a, b, c;
ll ar1[N], ar2[N], ar3[N]; 

vector <ll> ar12;
ll ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> y >> a >> b >> c;
    for (int i=1;i<=a;i++){
        cin >> ar1[i];
    }
    for (int i=1;i<=b;i++){
        cin >> ar2[i];
    }
    for (int i=0;i<c;i++){
        cin >> ar3[i];
    }
    sort(ar1 + 1, ar1 + a + 1);
    sort(ar2 + 1, ar2 + b + 1);
    sort(ar3, ar3 + c, greater<ll>());

    for (int i=1;i<=x;i++){
        ar12.pb(ar1[a - i + 1]);
    }
    for (int i=1;i<=y;i++){
        ar12.pb(ar2[b - i + 1]);
    }

    sort(ar12.begin(), ar12.end());
    for (int i=0;i<min(x + y, c);i++){
        if (ar12[i] < ar3[i]){
            ar12[i] = ar3[i];
        } else{
            break;
        }
    }

    for (auto x : ar12){
        ans += x;
    }
    cout << ans << el;

    return 0;
}