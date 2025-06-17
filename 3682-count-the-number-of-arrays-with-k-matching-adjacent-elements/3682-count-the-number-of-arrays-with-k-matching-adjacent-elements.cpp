const int mod=1e9+7;
class Solution {
public:
    long long findPow(long long a,long long b){
        if(b==0) return 1;
        long long half=findPow(a,b/2);
        long long res=(half*half)%mod;
        if(b%2==1) res=(res*a)%mod;
        return res;
    }
    long long nCr(int n,int r,vector<long long> &factorial,vector<long long>& fermatFactorial){
        return (((factorial[n]*fermatFactorial[n-r])%mod)*fermatFactorial[r])%mod;
    }
    int countGoodArrays(int n, int m, int k) {
        vector<long long> factorial(n+1,1);
        for(int i=2;i<=n;i++){
            factorial[i]=(factorial[i-1]*i)%mod;
        }
        vector<long long> fermatFactorial(n+1,1);
        for(int i=0;i<=n;i++){
            fermatFactorial[i]=findPow(factorial[i],mod-2);
        }
        long long res=nCr(n-1,k,factorial,fermatFactorial);
        res=(res*m)%mod;
        res=(res*findPow(m-1,n-k-1)%mod);
        return res;
    }
};