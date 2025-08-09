class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for(int i=0; i<n; i++){
            st.push(s[i]);
            if(s[i]==')'||s[i]=='}'||s[i]==']'){
                char ch = st.top();
                st.pop();
                if(!st.empty() && st.top()=='(' && ch==')') st.pop();
                else if(!st.empty() && st.top()=='{' && ch=='}') st.pop();
                else if(!st.empty() && st.top()=='[' && ch==']') st.pop();
                else st.push(ch);
            }
        }
        return st.empty();
    }
};