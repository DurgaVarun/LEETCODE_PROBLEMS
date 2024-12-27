class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0;
        int bestPrev = values[0];

        for (int i=1; i<values.size(); i++) {
            bestPrev--;
            maxScore = max(maxScore, bestPrev + values[i]);
            bestPrev = max(bestPrev, values[i]);
        }

        return maxScore;
        
    }
};