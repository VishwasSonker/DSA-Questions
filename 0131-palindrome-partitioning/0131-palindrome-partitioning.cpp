class Solution {
public:

    bool ispalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }

    void partitionhelper(int index, string s, vector<vector<string>> &res, vector<string> &path){
        if(index==s.size()){
            res.push_back(path);
            return;
        }
        for(int i=index; i<s.size(); i++){
            if(ispalindrome(s, index, i)){
                path.push_back(s.substr(index, i-index+1));
                partitionhelper(i+1, s, res, path);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        partitionhelper(0, s, res, path);
        return res;
    }
};