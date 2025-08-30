class Solution {
public:

    void parentheses(int open, int close, string op, vector<string> &st){
        if(open==0&&close==0){
            st.push_back(op);
            return;
        }
        if(open<close)
            parentheses(open, close-1, op+')', st);
        if(open>0)
            parentheses(open-1, close, op+'(', st);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> st;
        parentheses(n, n, "", st);
        return st;
    }
};