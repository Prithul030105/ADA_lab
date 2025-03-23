#include <bits/stdc++.h>
using namespace std;

// Structure for a point
struct Point {
    int x, y;
};

// Helper function to find the orientation of three points
// 0 -> collinear, 1 -> clockwise, 2 -> counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;           // Collinear
    return (val > 0) ? 1 : 2;         // Clockwise or Counterclockwise
}

// Comparator function to sort points based on polar angle w.r.t the bottom-most point
bool compare(Point p1, Point p2) {
    static Point pivot;
    int o = orientation(pivot, p1, p2);
    if (o == 0) // If collinear, choose closer point
        return (p1.x - pivot.x) * (p1.x - pivot.x) + (p1.y - pivot.y) * (p1.y - pivot.y) <
               (p2.x - pivot.x) * (p2.x - pivot.x) + (p2.y - pivot.y) * (p2.y - pivot.y);
    return (o == 2);
}

// Function to compute the Convex Hull
void convexHull(vector<Point> &points) {
    int n = points.size();
    if (n < 3) {
        cout << "Convex hull is not possible\n";
        return;
    }

    // Find the point with the lowest y-coordinate (and leftmost in case of tie)
    int ymin = points[0].y, minIdx = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < ymin || (points[i].y == ymin && points[i].x < points[minIdx].x)) {
            ymin = points[i].y;
            minIdx = i;
        }
    }

    // Swap to bring this point to the first position
    swap(points[0], points[minIdx]);
    
    // Set pivot for sorting
    static Point pivot = points[0];

    // Sort points based on polar angle
    sort(points.begin() + 1, points.end(), compare);

    // If after sorting two points are the same, remove duplicates
    vector<Point> uniquePoints;
    uniquePoints.push_back(points[0]);
    for (int i = 1; i < n; i++) {
        while (i < n - 1 && orientation(pivot, points[i], points[i + 1]) == 0)
            i++;
        uniquePoints.push_back(points[i]);
    }

    // If fewer than 3 unique points, convex hull is not possible
    if (uniquePoints.size() < 3) {
        cout << "Convex hull is not possible\n";
        return;
    }

    // Use a stack to store hull points
    stack<Point> hull;
    hull.push(uniquePoints[0]);
    hull.push(uniquePoints[1]);
    hull.push(uniquePoints[2]);

    // Process remaining points
    for (int i = 3; i < uniquePoints.size(); i++) {
        while (hull.size() > 1) {
            Point second = hull.top();
            hull.pop();
            Point first = hull.top();
            if (orientation(first, second, uniquePoints[i]) != 1) { // If not right turn
                hull.push(second);
                break;
            }
        }
        hull.push(uniquePoints[i]);
    }

    // Print the Convex Hull
    cout << "Convex Hull Points:\n";
    while (!hull.empty()) {
        Point p = hull.top();
        cout << "(" << p.x << ", " << p.y << ")\n";
        hull.pop();
    }
}

int main() {
    vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    convexHull(points);
    return 0;
}
