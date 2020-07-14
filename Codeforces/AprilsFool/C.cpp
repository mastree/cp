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

int a;
int ar[6] = {1, 6, 4, 3, 5, 2}; 

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a;
    bitset<6> bit(a);

    int ans = 0;
    for (int i=0;i<6;i++){
        // cout << bit[i];
        if (bit[6 - ar[i]]){
            ans += (1 << (5 - i));
        }
    }
    // cout << el;
    cout << ans << el;

    return 0;
}