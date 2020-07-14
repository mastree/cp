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

vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int temp;
    while (cin >> temp){
        v.pb(temp);
    }

    int n = v.size();
    for (int i=n - 1;i>=0;i--){
        printf("f(%d) = %.2f\n", v[i], v[i]);
    }

    return 0;
}