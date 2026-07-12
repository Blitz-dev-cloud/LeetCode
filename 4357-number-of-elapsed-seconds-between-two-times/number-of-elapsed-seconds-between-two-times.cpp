class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int st_h = stoi(startTime.substr(0, 2));
        int end_h = stoi(endTime.substr(0, 2));

        int st_m = stoi(startTime.substr(3, 2));
        int end_m = stoi(endTime.substr(3, 2));

        int st_s = stoi(startTime.substr(6, 2));
        int end_s = stoi(endTime.substr(6, 2));

        return 3600 * (end_h - st_h) + 60 * (end_m - st_m) + (end_s - st_s);
    }
};