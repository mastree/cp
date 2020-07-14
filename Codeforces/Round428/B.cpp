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

const int N = 1e4 + 10;
const int K = 200;

int n, k;
int ar[K];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    int slot4 = k;
    int slot2 = k * 2;
    int sisa[4] = {0, 0, 0, 0};
    sort(ar + 1, ar + n + 1, greater<int>());
    for (int i=1;i<=n;i++){
        int cur = ar[i];
        while (cur >= 4 && slot4){
            slot4--;
            cur -= 4;
        }
        while (cur >= 4 && slot2){
            slot2--;
            cur -= 2;
        }
        // if (cur == 2 && slot2){
        //     slot2--;
        //     cur = 0;
        // }
        sisa[cur]++;
    }
    // cout << sisa[1] << " " << sisa[2] << " " << sisa[3] << " " << slot2 << " " << slot4 << el;
    while (sisa[2] && slot2){
        sisa[2]--;
        slot2--;
    }
    while (sisa[1] && sisa[2] && slot4){
        slot4--;
        sisa[1]--;
        sisa[2]--;
    }
    while (sisa[2] > 1 && slot4){
        slot4--;
        sisa[2] -= 2;
        sisa[1]++;
    }
    while (sisa[3] && slot2){
        slot2--;
        sisa[3]--;
        sisa[1]++;
    }
    while (sisa[1] && sisa[2] && slot4){
        slot4--;
        sisa[1]--;
        sisa[2]--;
    }
    while (sisa[3] && slot4){
        slot4--;
        sisa[3]--;
    }
    while (sisa[1] && slot4){
        slot4--;
        sisa[1] = max(sisa[1] - 2, 0);
    }
    while (sisa[2] && slot4){
        slot4--;
        sisa[2]--;
    }
    while (sisa[1] && slot2){
        slot2--;
        sisa[1]--;
    }
    if (sisa[1] <= 0 && sisa[2] <= 0 && sisa[3] <= 0){
        cout << "YES" << el;
    } else{
        cout << "NO" << el;
    }

    return 0;
}