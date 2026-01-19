class Solution
{
    unordered_set<int> getEdges(vector<int> &fences, int border)
    {
        unordered_set<int> st;
        fences.push_back(1);
        fences.push_back(border);
        sort(fences.begin(), fences.end());
        for (int i = 0; i < fences.size(); i++)
        {
            for (int j = i + 1; j < fences.size(); j++)
            {
                st.insert(fences[j] - fences[i]);
            }
        }
        return st;
    }

public:
    int maximizeSquareArea(int m, int n, vector<int> &hFences,
                           vector<int> &vFences)
    {
        auto hEdges = getEdges(hFences, m);
        auto vEdges = getEdges(vFences, n);
        int res = 0;
        for (auto e : hEdges)
        {
            if (vEdges.contains(e))
            {
                res = max(res, e);
            }
        }
        if (res == 0)
        {
            res = -1;
        }
        else
        {
            res = 1ll * res * res % 1000000007;
        }
        return res;
    }
};

// Dry run
// Input: m = 5, n = 5, hFences = [2,3], vFences = [2,4]
// hEdges: {1,2,3,4}
// vEdges: {1,2,3}
// Common edges: {1,2,3}
// Max edge: 3
