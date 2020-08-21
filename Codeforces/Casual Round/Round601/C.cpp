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
int ar[N][3];

int cnt[N];
bool visNode[N], visItem[N];

vector <int> v1, v2;
vector <int> adl[N];
vector <int> ans, ansNode;
int len;

void printUrutan(){
    for (int i=0;i<n-2;i++){
        for (int j=0;j<3;j++){
            cout << ar[i][j] << " ";
        }
    } cout << el;
}

void printVis(){
    for (int i=0;i<n-2;i++){
        cout << visNode[i] << " ";
    }cout << el;
}

bool cek(int node, int id){
    for (auto x : adl[id]){
        if (x==node){
            return 1;
        }
    }

    return 0;
}

int hitung(int id){
    int res=3;
    for (auto x : adl[id]){
        if (visNode[x]){
            res--;
        }
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i=0;i<n-2;i++){
        for (int j=0;j<3;j++){
            cin >> ar[i][j];
            cnt[ar[i][j]]++;
            adl[ar[i][j]].pb(i);
        }
    }    

    for (int i=1;i<=n;i++){
        if (cnt[i]==1){
            v1.pb(i);
            // cout << i << el;
        } else if (cnt[i]==2){
            v2.pb(i);
        }
    }

    int pertama=-1, idi, idj;
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            for (auto x : adl[v1[i]]){
                for (auto y : adl[v2[j]]){
                    if (x == y){
                        visNode[x] = 1;
                        pertama=x;
                        idi=i;
                        idj=j;
                        break;
                    }
                }
                if (pertama!=-1) break;
            }
            if (pertama!=-1) break;
        }
        if (pertama!=-1) break;
    }

    ans.pb(v1[idi]);
    ans.pb(v2[idj]);
    visItem[v1[idi]]=1;
    visItem[v2[idj]]=1;
    len=2;

    while (len<n-2){
        // printVis();
        int node;
        for (auto x : adl[ans[len-1]]){
            if (visNode[x]){
                continue;
            } 
            node = x;
            break;
        }

        visNode[node]=1;
        int num=0;
        for (int i=0;i<3;i++){
            if (visItem[ar[node][i]]) continue;
            int tm = ar[node][i];
            // for (auto x : adl[tm]){
            //     for (int j=0;j<3;j++){
            //         if (())
            //         if (ar[ans[len-1]][i] == ar[node][j]){
            //             num = ar[node][j];
            //             break;
            //         }
            //     }
            // }

            if (hitung(tm)==1){
                num=tm;
            }
            if (num) break;
        }        

        ans.pb(num);
        visItem[num]=1;
        len++;
    }

    ans.pb(v2[(idj+1)%2]);
    ans.pb(v1[(idi+1)%2]);

    for (auto x : ans){
        cout << x << " ";
    }

    cout << el;

    return 0;
}