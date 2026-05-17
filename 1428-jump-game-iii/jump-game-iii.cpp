class Solution {
private:
    bool search(int idx, int n, vector<bool> &visited, vector<int> &arr) {
        if(idx >= n || idx < 0 || visited[idx]) return false;

        if(arr[idx] == 0) return true;

        visited[idx] = true;

        return search(idx + arr[idx], n, visited, arr) || search(idx - arr[idx], n, visited, arr);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        return search(start, n, visited, arr);
    }
};