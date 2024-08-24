#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define a Point
struct Point {
    int x, y;
};

// A global point needed for sorting points with reference
// to the first point
Point p0;

// A utility function to find the next to top in a stack
Point nextToTop(vector<Point> &S) {
    Point p = S.back();
    S.pop_back();
    Point res = S.back();
    S.push_back(p);
    return res;
}

// A utility function to swap two points
void swap(Point &p1, Point &p2) {
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

// A utility function to return the square of the distance
// between p1 and p2
int distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) +
           (p1.y - p2.y) * (p1.y - p2.y);
}

// To find orientation of the ordered triplet (p, q, r).
// The function returns the following values:
// 0 -> p, q, and r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;          // collinear
    return (val > 0) ? 1 : 2;        // clock or counterclockwise
}

// A function used by sort() to sort the points with respect
// to the first point
bool compare(Point p1, Point p2) {
    // Find the orientation
    int o = orientation(p0, p1, p2);
    if (o == 0)
        return (distSq(p0, p2) >= distSq(p0, p1)) ? false : true;
    return (o == 2) ? true : false;
}

// Prints the convex hull of a set of n points.
void convexHull(vector<Point> points, int n) {
    // Find the bottom-most point
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;

        // Pick the bottom-most or chose the left most point in case of tie
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    // Place the bottom-most point at first position
    swap(points[0], points[min]);

    // Sort n-1 points with respect to the first point.
    p0 = points[0];
    sort(points.begin() + 1, points.end(), compare);

    // Create an empty stack and push first three points to it
    vector<Point> S;
    S.push_back(points[0]);
    S.push_back(points[1]);
    S.push_back(points[2]);

    // Process remaining n-3 points
    for (int i = 3; i < n; i++) {
        // Keep removing top while the angle formed by points next-to-top,
        // top, and points[i] makes a non-left turn
        while (S.size() > 1 && orientation(nextToTop(S), S.back(), points[i]) != 2)
            S.pop_back();
        S.push_back(points[i]);
    }

    // Now stack has the output points, print contents of stack
    while (!S.empty()) {
        Point p = S.back();
        cout << "(" << p.x << ", " << p.y << ")" << endl;
        S.pop_back();
    }
}

int main() {
    vector<Point> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = points.size();
    convexHull(points, n);
    return 0;
}
