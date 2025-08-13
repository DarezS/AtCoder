#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int N, A, B;
    cin >> N >> A >> B;

    string S;
    cin >> S;

    string result;

    rep(i, S.size())
    {
        if(i<A) continue;
        else if(i>S.size() - B-1) continue;
        else result += S[i];
    }

    cout << result <<endl;

    return 0;
}