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

const ll INF = 2e18;

int q;
ll n, g, b;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> g >> b;
        ll low = 1, high = INF;
        while (low < high){
            ll mid = (low + high) / 2;
            ll temp = 0;
            temp = mid / (g + b);
            temp *= g;
            temp += min(mid % (g + b), g);
            if (temp >= (n + 1) / 2 && mid >= n){
                high = mid;
            } else{
                low = mid + 1;
            }
        }
        cout << high << el;
    }

    return 0;
}