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

int n;
int ar[N];
vector <int> ans;
int tot=0;
bool bisa=1;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ar[i];
    }

    int len=0;
    while (tot<n && bisa){
        int i=tot;
        // cout << tot << el;
        map <int, int> cek, cntin;

        for (i;i<n;i++){
            // cout << i << " ";
            int tm = abs(ar[i]);
            if (ar[i]>0){
                cntin[tm]++;
                cek[tm]++;
            } else{
                cek[tm]--;
            }

            if (cntin[tm]>1 || cek[tm]<0){
                if (ar[i]>0){
                    cntin[tm]--;
                    cek[tm]--;
                } else{
                    cek[tm]++;
                }
                break;
            }
        }
        // cout << el;
        ans.pb(i-tot);
        if (ans[len]==0){
            bisa=0;
        }
        
        for (auto x : cek){
            if (x.se>0){
                bisa=0;
            }
        }
        len++;
        tot=i;
    }

    if (bisa==0){
        cout << -1 << el;
        return 0;
    }
    
    cout << len << el;
    for (auto x : ans){
        cout << x << " ";
    }
    cout << el;

    return 0;
}