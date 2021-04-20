/*
leet1563


*/


#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <climits>
#include <cassert>
#include <random>
#include <functional>
#include <utility>
// #include "../utils/LeetCpp.utils.hpp"

using namespace std;

#define POW2(X) (1<<(X))
#define CKBIT(S,X) (((S)&POW2(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){ a=min(a,b); }
template<class T> inline void ckmax(T &a,T b){ a=max(a,b); }
template<class T> inline T sqr(T x){ return x*x; }
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
template<class T> int CMP(T a[],const T b[],int n) { return memcmp(a,b,n*sizeof(T)); }
template<class T> void COPY(T a[],const T b[],int n) { memcpy(a,b,n*sizeof(T)); }
template<class T> void SET(T a[],int val,int n) { memset(a,val,n*sizeof(T)); }
using uint=unsigned int;
using int64=long long;
using uint64=unsigned long long;
using ipair=pair<int,int>;
using VI=vector<int>;
using VD=vector<double>;
using VVI=vector<VI>;
using VS=vector<string>;



class Solution {
public:
    int stoneGameV(const vector<int>& A) {
        int f[505][505]{};
        int sum[505]{};
        
        int N = A.size();

        for (int i = 0; i < N; i++)
            sum[i + 1] = sum[i] + A[i];
        
        
        for (int len = 1; len < N; len++)
        {
            for (int i = 0; i < N - len; i++)
            {
                auto j = i + len;
                for (int k = i; k <= j; k++)
                {
                    auto lft = sum[k + 1] - sum[i];
                    auto rht = sum[j + 1] - sum[k + 1];
                    if (lft <= rht) {
                        f[i][j] = max(f[i][j], f[i][k] + lft );
                    }
                    if (lft >= rht) {
                        f[i][j] = max(f[i][j], f[k+1][j] + rht );
                    }
                }
                
            }
            
        }
        return f[0][N-1];
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;   
    cout << sol.stoneGameV({6,2,3,4,5,5}) << endl;
    cout << sol.stoneGameV({7,7,7,7,7,7,7}) << endl;
    cout << sol.stoneGameV({4}) << endl;
    return 0;
}
