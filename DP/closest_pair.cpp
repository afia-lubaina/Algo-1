#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

double dist(Point p1, Point p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

double stripClosest(vector<Point>& strip, double d) {
    double min_dist = d;
    int n = strip.size();

    sort(strip.begin(), strip.end(), [](Point p1, Point p2) {
        return p1.y < p2.y;
    });

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && (strip[j].y - strip[i].y) < min_dist; ++j) {
            min_dist = min(min_dist, dist(strip[i], strip[j]));
        }
    }

    return min_dist;
}

double closestPairUtil(vector<Point>& points, int left, int right) {
    if (right - left <= 3) {
        double min_dist = DBL_MAX;
        for (int i = left; i < right; ++i) {
            for (int j = i + 1; j < right; ++j) {
                min_dist = min(min_dist, dist(points[i], points[j]));
            }
        }
        return min_dist;
    }

    int mid = (left + right) / 2;
    Point mid_point = points[mid];

    double left_dist = closestPairUtil(points, left, mid);
    double right_dist = closestPairUtil(points, mid, right);

    double min_dist = min(left_dist, right_dist);

    vector<Point> strip;
    for (int i = left; i < right; ++i) {
        if (abs(points[i].x - mid_point.x) < min_dist) {
            strip.push_back(points[i]);
        }
    }

    double strip_dist = stripClosest(strip, min_dist);

    return min(min_dist, strip_dist);
}

double closestPair(vector<Point>& points) {
    int n = points.size();

    sort(points.begin(), points.end(), [](Point p1, Point p2) {
        return p1.x < p2.x;
    });

    return closestPairUtil(points, 0, n);
}

int main() {
    vector<Point> points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}, {11, 12}};
    double min_dist = closestPair(points);
    cout << "The minimum distance between the closest pair of points is: " << min_dist << endl;
    return 0;
}
