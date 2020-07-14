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

const int N = 1e5 + 10;

int n, a, b, c;
int op[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b >> c;
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        if (s == 'AB'){
            op[i] = 1;
        } else if (s == 'BC'){
            op[i] = 2;
        } else{
            op[i] = 3;
        }
    }
    for (int i=1;i<=n;i++){
        if (op[i] == 1){
            
        } else if (op[i] == 2){

        } else{

        }
    }

    return 0;
}