class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        if(k == n) return sum;

        int window = n - k;
        int currSum = 0, minSum = INT_MAX;

        for( int i = 0 ; i < window ; i++ ) {
            currSum += cardPoints[i];
        }

        minSum = min(minSum, currSum);

        for( int i = window ; i < n ; i++ ){
            currSum += cardPoints[i];
            currSum -= cardPoints[i - window];
            minSum = min(minSum, currSum);
        }

        return sum - minSum;
    }
};