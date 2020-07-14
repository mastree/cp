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

int n;
ll ans;
int cnt;
string t;
vector<int> od, ev;
int c0[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    n = t.length();
    for (int i=0;i<n;i++){
        if (t[i] == '1'){
            cnt++;
            if (cnt & 1){
                ans += (cnt + 1) / 2;
            }
        } else{
            c0[cnt]++;
            if (cnt & 1){
                od.pb(cnt);
            } else{
                ev.pb(cnt);
            }
        }
    }
    

    return 0;
}