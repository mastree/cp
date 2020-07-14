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

const int N = 3e5 + 10;
int n;
ll w, b;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        ll temp;
        cin >> temp;
        if (i & 1){
            w += (temp + 1) / 2;
            b += temp / 2;
        } else{
            w += temp / 2;
            b += (temp + 1) / 2;
        }
    }
    cout << min(w, b) << el;

    return 0;
}