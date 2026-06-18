class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = 30.0 * (double)hour + 0.5 * (double)minutes;
        double m = 6.0 * (double)minutes;

        double diff = abs(m - h);

        return min(diff, 360.0 - diff);
    }
};