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

int q;

vector <int> adl[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        int n;
        cin >> n;

        set <int> setdah;
        vector <int> adl[n + 2];
        for (int i=1;i<=n;i++){
            setdah.insert(i);
            int k;
            cin >> k;
            for (int j=1;j<=k;j++){
                int temp;
                cin >> temp;
                adl[i].pb(temp);
            }
        }

        bool opt = 1;
        vector <int> sisa;
        for (int i=1;i<=n;i++){
            bool ada = 0;
            for (auto mau : adl[i]){
                if (setdah.find(mau) != setdah.end()){
                    setdah.erase(mau);
                    ada = 1;
                    break;
                }
            }
            if (!ada){
                opt = 0;
                sisa.pb(i);
            }
        }

        if (opt){
            cout << "OPTIMAL" << el;
        } else{
            cout << "IMPROVE" << el;
            cout << sisa[0] << " " << *setdah.begin() << el;
        }
    }

    return 0;
}