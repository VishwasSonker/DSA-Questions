class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int b;
        for(int i=n-1; i>=0; i--){
            int a=num[i]-'0';
            if(a%2!=0){
                b=i+1;
                break;
            }
            else{
                b=i;
            }
        }
        string result;
        for(int i=0; i<b; i++){
            result+=num[i];
        }
        return result;
    }
};