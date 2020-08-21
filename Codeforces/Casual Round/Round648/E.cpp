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

const int N = 5e2 + 10, M = 60;

int n;
ll ar[N];
bool ada[M];
bitset<N> bset[M];
bitset<N> cur, cur1, cur2, cur3, temp1, temp2;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        for (int j=0;j<M;j++){
            ll bit = (1LL << j);
            if (ar[i] & bit){
                ada[j] = 1;
                bset[j][i] = 1;
            }
        }
    }
    
    ll ans = 0;
    ans = 0;
    // ll a = 0, b = 0, c = 0;
    for (int i=1;i<=n;i++){
        // if (cur1[i]){
            for (int j=1;j<=n;j++){
                // if (cur2[j]){
                    for (int k=1;k<=n;k++){
                        // if (cur3[k]){
                            ans = max(ans, ((ar[i] | ar[j]) | ar[k]));
                        // }
                    }
                // }
            }
        // }
    }
    cout << ans << el;
    return 0;
    int salah = 0;
    int hand = 0;
    for (int i=M - 1;i>=0;i--){
        if (ada[i]){
            // cout << i << " => " << el;
            if (ans == 0){
                ans = (1LL << i);
                cur = bset[i];
                continue;
            }
            if (salah == 0){
                cur1 = cur;
                cur2 = bset[i];
                cur &= bset[i];
                ans += (1LL << i);
                if (cur.count() == 0){
                    salah++;
                }
            } else if (salah == 1){
                temp1 = (cur1 & bset[i]);
                temp2 = (cur2 & bset[i]);
                if (temp1.count()){
                    cur1 = temp1;
                    if (temp2.count()){
                        cur2 = temp2;
                    }
                } else if (temp2.count()){
                    cur2 = temp2;
                    if (temp1.count()){
                        cur1 = temp1;
                    }
                } else{
                    cur3 = bset[i];
                    salah++;
                }
                ans += (1LL << i);
            } 
            // else if (salah == 2){
                // cur1 &= bset[i];
                // cur2 &= bset[i];
                // if (hand == 2 && cur1.count()){
                //     ans += (1LL << i);
                // } else if (hand == 1 && cur2.count()){
                //     ans += (1LL << i);
                // }
                // salah = 3;
            // }
            // cout << salah << el;

            if (salah >= 2) break;
        }
    }
    ans = 0;
    // ll a = 0, b = 0, c = 0;
    for (int i=1;i<=n;i++){
        if (cur1[i]){
            for (int j=1;j<=n;j++){
                if (cur2[j]){
                    for (int k=1;k<=n;k++){
                        if (cur3[k]){
                            ans = max(ans, ((ar[i] | ar[j]) | ar[k]));
                        }
                    }
                }
            }
        }
    }
    cout << ans << el;
    return 0;
}