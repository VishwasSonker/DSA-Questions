class Solution {
public:

    int helper(string s, int i, long long num, int sign){
        if(i>=s.size() || !isdigit(s[i])){
            long long ans = num*sign;
            if(ans>INT_MAX) return INT_MAX;
            if(ans<INT_MIN) return INT_MIN;
            return (int)ans;
        }
        num=num*10+(s[i]-'0');
        long long ans = num*sign;
        if(ans>INT_MAX) return INT_MAX;
        if(ans<INT_MIN) return INT_MIN;
        
        return helper(s, i+1, num, sign);
    }

    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        while(i<n&&s[i]==' '){
            i++;
        }
        int sign=1;
        if(i<n&&(s[i]=='+'||s[i]=='-')){
            if(s[i]=='-') sign=-1;
            i++;
        }
        if(i<n&&isdigit(s[i])){
            return helper(s, i, 0, sign);
        }
        return 0;
    }
};