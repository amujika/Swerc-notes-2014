#include <vector>
#include <algorithm>
#include <math.h>

typedef struct { int x; int y;} point;

using namespace std;

point pivot; // global variable
vector<point> polygon, CH;

int area2(point a, point b, point c) {
    return a.x * b.y - a.y * b.x + b.x * c.y - b.y * c.x + c.x * a.y - c.y * a.x;
}

int dist2(point a, point b) { // function to compute distance between 2 points
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

bool angle_cmp(point a, point b) { // important angle-sorting function
    if (area2(pivot, a, b) == 0) // collinear
        return dist2(pivot, a) < dist2(pivot, b); // which one closer
    int d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    int d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2((double)d1y, (double)d1x) - atan2((double)d2y, (double)d2x)) < 0;
}

vector<point> GrahamScan(vector<point> Polygon) {
// first, find P0 = point with lowest Y and if tie: rightmost X
    int i, P0 = 0, N = Polygon.size();
    for (i = 1; i < N; i++)
        if (Polygon[i].y < Polygon[P0].y ||
                (Polygon[i].y == Polygon[P0].y && Polygon[i].x > Polygon[P0].x))
            P0=i;
    point temp = Polygon[0]; // swap selected vertex with Polygon[0]
    Polygon[0] = Polygon[P0];
    Polygon[P0] = temp;
// second, sort points by angle w.r.t. P0, skipping Polygon [0]
    pivot = Polygon[0]; // use this global variable as reference
    sort(++Polygon.begin(), Polygon.end(), angle_cmp);
// third, the ccw tests
    stack<point> S;
    point prev, now;
    S.push(Polygon[N - 1]); // put two starting vertices into stack S
    S.push(Polygon[0]);
    i = 1; // and start checking the rest
    while (i < N) { // note: N must be >= 3 for this method to work
        now = S.top();
        S.pop();
        prev = S.top();
        S.push(now); // trick to get the 2nd item from top of S
        if (ccw(prev, now, Polygon[i])) { // if these 3 points make a left turn
            S.push(Polygon[i]); // accept
            i++;
        }
        else // otherwise
            S.pop(); // pop this point until we have a left turn
    }
    vector<point> ConvexHull;
    while (!S.empty()) { // from stack back to vector
        ConvexHull.push_back(S.top());
        S.pop();
    }
    ConvexHull.pop_back(); // the last one is a duplicate of first one
    return ConvexHull; // return the result
}
