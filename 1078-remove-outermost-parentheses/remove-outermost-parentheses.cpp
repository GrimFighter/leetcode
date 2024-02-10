class Solution
{
    public:
        string removeOuterParentheses(string s)
        {
            int count = 0, startPos = 0, endPos = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '(')
                {
                    if (count == 0)
                    {
                        startPos = i;
                    }
                    count++;
                }
                else if (s[i] == ')')
                {   count--;
                    if (count == 0)
                    {
                        endPos = i;
                    }
                    
                }

                if (count == 0)
                {
                    s.erase(startPos, 1);
                    s.erase(endPos - 1, 1);
                    i = i-2;
                }
            }
            return s;
        }
};