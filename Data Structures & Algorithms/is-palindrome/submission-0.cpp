class Solution {
public:
    bool isPalindrome(string s) {
        string newS = "";

        for(char& c : s){
            if(isalnum(c)){
                c = tolower(c);
                newS += c;
            }
        }

        int i = 0, j = newS.size() - 1;        

        while(i < j){
            if(newS[i] != newS[j]) return false;
            i++, j--;
        }

        return true;
    }
};
