#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution {
private:
    int calculateMaxPath(vector<vector<int>>& grid) {
        int size = grid.size();
        vector<int> previousRow(size, INT_MIN), currentRow(size, INT_MIN);
        previousRow[size - 1] = grid[0][size - 1];
        
        for (int row = 1; row < size - 1; ++row) {
            fill(currentRow.begin(), currentRow.end(), INT_MIN);
            for (int col = max(size - 1 - row, row + 1); col < size; ++col) {
                int maxFromPrev = previousRow[col];
                if (col - 1 >= 0) {
                    maxFromPrev = max(maxFromPrev, previousRow[col - 1]);
                }
                if (col + 1 < size) {
                    maxFromPrev = max(maxFromPrev, previousRow[col + 1]);
                }
                currentRow[col] = maxFromPrev + grid[row][col];
            }
            swap(previousRow, currentRow);
        }
        return previousRow[size - 1];
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int result = 0;
        
        for (int idx = 0; idx < n; ++idx) {
            result += fruits[idx][idx];
        }
        
        result += calculateMaxPath(fruits);
        
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < row; ++col) {
                swap(fruits[col][row], fruits[row][col]);
            }
        }
        
        result += calculateMaxPath(fruits);
        
        return result;
    }
};