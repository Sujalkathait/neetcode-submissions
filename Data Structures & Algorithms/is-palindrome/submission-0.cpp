class Solution {
public:
    bool isPalindrome(string s) 
    {
          string rev = "";

        for (char c : s) {
            if (isalnum(c)) {
                rev += tolower(c);
            }
        }

        string original = rev;
        reverse(rev.begin(), rev.end());

        return original == rev;
    }
};
