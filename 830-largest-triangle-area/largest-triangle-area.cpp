class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double mx = 0.00000;

        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                for (int k = j + 1; k < points.size(); ++k) {
                    double area = 0.5 * abs(points[i][0]*(points[j][1]-points[k][1]) +
                                            points[j][0]*(points[k][1]-points[i][1]) +
                                            points[k][0]*(points[i][1]-points[j][1]));
                    mx = max(mx, area*1.00000);
                }
            }
        }
        return mx;
    }
};