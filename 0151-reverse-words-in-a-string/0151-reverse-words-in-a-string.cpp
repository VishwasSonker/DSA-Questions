class Solution {
public:
    string reverseWords(string s) {
        // Step 1: remove leading & trailing spaces
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < n && s[left] == ' ') left++;
        while (right >= 0 && s[right] == ' ') right--;

        // Step 2: split words
        vector<string> words;
        string word = "";
        for (int i = left; i <= right; i++) {
            if (s[i] == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            } else {
                word += s[i];
            }
        }
        if (!word.empty()) words.push_back(word);

        // Step 3: reverse the words
        reverse(words.begin(), words.end());

        // Step 4: join with single space
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) result += " ";
        }
        return result;
    }
};