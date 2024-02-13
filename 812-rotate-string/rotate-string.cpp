class Solution {
public:
    bool rotateString(string s, string goal) {
        int s1 = s.size();

        for(int i =0; i < s1; i++)
        {
             s.push_back(s[0]);
            s.erase(0,1);
            if(s == goal) return true;
        }
        return false;
    }
};