class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        for(int num : asteroids){
            if(st.empty()){
                st.push(num);
            }else if(num>0){
                st.push(num);
            }else{
                bool isalive = 1;
                while(!st.empty()&&st.top()>0&&isalive){
                    if(st.top()<abs(num)) st.pop();
                    else if(st.top()>abs(num)) isalive=0;
                    else{
                        st.pop();
                        isalive=0;
                    }
                }
                if(isalive){
                    st.push(num);
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};