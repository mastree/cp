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

const int N = 3e5 + 7;

int q;
int n;
int ar[N];
int le[N], ri[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        fill(le, le + n + 2, 0);
        fill(ri, ri + n + 2, 0);
        
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            le[i] = ar[i];
            ri[i] = ar[i];
        }
        for (int i=2;i<=n;i++){
            le[i] = min(le[i-1] + 1, le[i]);
        }
        for (int i=n-1;i>=0;i--){
            ri[i] = min(ri[i+1] + 1, ri[i]);
        }
        bool ans = 0;
        for (int i=1;i<=n;i++){
            int l = i, r = n - i + 1;
            if ((le[i] >= l-1) && (ri[i] >= r-1)){
                ans = 1;
                break;
            }
        }
        if (ans){
            cout << "Yes" << el;
        } else{
            cout << "No" << el;
        }
    }

    return 0;
}