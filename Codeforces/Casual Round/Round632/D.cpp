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

const int N = 3e3 + 10;

int n, k;
int ar[N];
string s;

vector <int> v[N];
vector <int> ans[N * 1000];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    cin >> s;
    for (int i=0;i<n;i++){
        if (s[i] == 'L'){
            ar[i + 1] = 0;
        } else{
            ar[i + 1] = 1;
        }
    }

    int last = 0;
    int tot = 0;
    for (int turn=1;turn<=n + 2;turn++){
        for (int i=1;i<n;i++){
            if (ar[i] == 1 && ar[i + 1] == 0){
                ar[i] = !ar[i];
                ar[i + 1] = !ar[i + 1];
                v[turn].pb(i);
                i += 1;
                tot++;
                // cout << i << " ";
            }
        }
        // cout << el;s
        if ((int)v[turn].size() > 0){
            last = turn;
        } else{
            break;
        }
    }

    // cout << last << " " << tot << el;
    if (last > k || tot < k){
        cout << -1 << el;
        return 0;
    }

    int kurang = k - last;
    int curid = 1;
    for (int i=1;i<=last;i++){
        int len = v[i].size();
        for (int j=0;j<len;j++){
            ans[curid].pb(v[i][j]);
            if (kurang && j != (len - 1)){
                curid++;
                kurang--;
            }
        }
        curid++;
    }

    if (kurang > 0){
        cout << -1 << el;
        return 0;
    }

    for (int i=1;i<=k;i++){
        int len = ans[i].size();
        cout << len << " ";
        for (auto x : ans[i]){
            cout << x << " ";
        }
        cout << el;
    }

    return 0;
}