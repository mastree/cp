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

const int N = 1000007;

int n;
int ar[N];
ll od,ev,res;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ar[i];
        if (ar[i]&1) od++;
        else ev++;
    }

    if (od<=ev) res=od;
    else {
        res+=ev;
        od-=ev;
        res+=od/2;
    }

    cout << res << el;

    return 0;
}