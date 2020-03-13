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

const int N = 6e5 + 10;
const ll M1 = 999995959, M2 = 1e9 + 9;
const ll P1 = 79, P2 = 47;

int n, m;
unordered_map <ll, bool> cek[N];
string s;
ll len;

ll hashing(){
    ll curp1 = 1, curp2 = 1;
    ll cur1 = 0, cur2 = 0;
    for (int i=0;i<len;i++){
        ll temp = s[i] - 'a' + 1;
        cur1 = (cur1 + temp * curp1) % M1;
        cur2 = (cur2 + temp * curp2) % M2;

        curp1 = curp1 * P1 % M1;
        curp2 = curp2 * P2 % M2;
    }
    return (cur1 << 31) + cur2;
}

// ll fpow(ll a, ll b, ll M){
//     if (b == 0) return 1;
//     ll tm = fpow(a, b/2, M);
//     tm = tm * tm % M;
//     if (b & 1){
//         tm = tm * a % M;
//     }
//     return tm;
// }

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0;i<n;i++){
        // string s;
        cin >> s; 
        len = s.length();

        ll temp = hashing();
        cek[len][temp]=1;
    }

    for (int i=0;i<m;i++){
        cin >> s;
        len = s.length();

        ll temp = hashing();
        ll h1 = (temp >> 31), h2 = temp % (1LL << 31);
        bool bisa = 0;
        ll curp1 = 1, curp2 = 1;
        for (int j=0;j<len;j++){
            ll dig = s[j] - 'a' + 1;
            ll cur1 = (h1 - dig * curp1 + M1 + M1 + M1) % M1;
            ll cur2 = (h2 - dig * curp2 + M2 + M2 + M2) % M2;

            for (ll k=1;k<=3;k++){
                if (k == dig) continue;
                ll now = (cur1 + k * curp1) % M1;
                now <<= 31;
                now += (cur2 + k * curp2) % M2;

                if (cek[len][now]){
                    bisa = 1;
                    break;
                }
            }
            if (bisa) break;

            curp1 = curp1 * P1 % M1;
            curp2 = curp2 * P2 % M2; 
        }

        if (bisa){
            cout << "YES" << el;
        } else{
            cout << "NO" << el;
        }
    }

    return 0;
}