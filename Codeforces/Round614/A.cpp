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

const int N = 3e3 + 7;
// const int ZERO = 1005;

int q;
int n, s, k;
int ZERO;

bool ada[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    ZERO = 1500;
    while (q--){
        cin >> n >> s >> k;
        for (int i=0;i<N;i++){
            ada[i]=1;
        }
        for (int i=0;i<k;i++){
            int a;
            cin >> a;
            int plus = (a-s);
            if (abs(plus) > 1000) continue;
            else {
                ada[ZERO + plus] = 0;
            }
        }
        // for (int i=1;i<=n;i++){
        //     cout << ada[i - s + ZERO] << " ";
        // } cout << el;
        int ans = MOD;
        for (int plus=0;plus<=n-s;plus++){
            if (ada[ZERO + plus]){
                ans=plus;
                break;
            }
        }
        for (int plus=0;plus>-s;plus--){
            if (ada[ZERO + plus]){
                ans=min(ans, abs(plus));
                break;
            }
        }
        cout << ans << el;
    }

    return 0;
}