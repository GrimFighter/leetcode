class Solution
{
    public:
        bool isIsomorphic(string s, string t)
        {
            unordered_map<char, char> umap1;
            unordered_map<char, char> umap2;
            int s1 = s.size();

            for (int i = 0; i < s1; i++)
            {
                if (umap1.find(s[i]) == umap1.end() and umap2.find(t[i]) == umap2.end())
                {
                    umap1[s[i]] = t[i];
                    umap2[t[i]] = s[i];
                }
                else if (umap1[s[i]] != t[i] or umap2[t[i]] != s[i])
                {
                    return false;
                }
            }

            return true;
        }
};