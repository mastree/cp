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

const int N = 2e5 + 10;

int n, m;
int ar[N], br[N];
int pref[N];

void cons(){
    int l = 1;
    int r = 2;
    fill(pref, pref + m + 2, 1);
    for (r;r<=m;r++){
        while (br[l] != br[r] && l > 1){
            l = pref[l - 1];
        }
        if (br[l] == br[r]) l++;
        pref[r] = l;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=m;i++){
        cin >> br[i];
    }

    if (m == 1){
        cout << n << el;
        return 0;
    }

    for (int i=1;i<n;i++){
        ar[i] = ar[i+1] - ar[i];
    }
    for (int i=1;i<m;i++){
        br[i] = br[i+1] - br[i];
    }
    n--;
    m--;
    cons();

    int l = 1;
    int cnt = 0;
    for (int r=1;r<=n;r++){
        while (br[l] != ar[r] && l > 1){
            l = pref[l - 1];
        }
        if (br[l] == ar[r]) l++;
        if (l == m+1){
            cnt++;
            l = pref[l - 1];
        }
    }
    cout << cnt << el;

    return 0;
}