class Solution {
public:
const long long MOD = 1e9+7;

    long long pows(long long x, long long n, long long ans) {
        if(n==0) return ans % MOD;
        if(n%2==1){
            ans = (ans * x) % MOD;
            n--;
        } else {
            x = (x * x) % MOD;
            n /= 2;
        }
        return pows(x, n, ans);
    }

    long long myPow(long long x, long long n) {
        return pows(x % MOD, n, 1);
    }

    int countGoodNumbers(long long n) {
        long long even = (n+1)/2; // positions with even numbers
        long long odd = n/2;      // positions with prime numbers
        long long res1 = myPow(5, even);
        long long res2 = myPow(4, odd);
        return (res1 * res2) % MOD;
    }
};