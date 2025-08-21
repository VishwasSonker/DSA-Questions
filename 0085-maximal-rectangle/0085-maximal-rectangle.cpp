class Solution {
public:
    int largesthistogram(vector<int> arr){
        stack<int> st;
        int maxarea=0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty()?-1:st.top();
                maxarea = max(arr[element]*(nse-pse-1),maxarea);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = n;
            int element = st.top();
            st.pop();
            int pse = st.empty()?-1:st.top();
            maxarea = max(arr[element]*(nse-pse-1),maxarea);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> psum(n,vector<int>(m));
        int maxarea = 0;
        for(int j=0; j<m; j++){
            int sum=0;
            for(int i=0; i<n; i++){
                sum+=(matrix[i][j]-'0');
                if(matrix[i][j]=='0') sum=0;
                psum[i][j]=sum;
            }
        }
        for(int i=0; i<n; i++){
            maxarea = max(maxarea, largesthistogram(psum[i]));
        }
        return maxarea;
    }
};