#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int N, L, R;
    cin >> N >> L >> R;

    string S;
    cin >> S;

    bool isOk = true;

    rep(i, N)
    {
        int idx = i+1;
        if(idx >=L && idx <= R)
        {
            if(S[i] != 'o')
            {
                isOk = false;
            }
        }
    }

    if(isOk) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}