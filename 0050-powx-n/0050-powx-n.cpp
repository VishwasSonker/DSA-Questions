class Solution {
public:

    double pows(double x, long long n, double ans){
        if(n==0){
            return ans;
        }
        if(n%2==1){
            ans*=x;
            n--;
        }else{
            x*=x;
            n/=2;
        }
        return pows(x, n, ans);
    }

    double myPow(double x, int n) {
        long long N = abs((long long)n);
        if(n<0) return 1/pows(x, N, 1);
        return pows(x, N, 1);
    }
};