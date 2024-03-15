#include <iostream>
#include <math.h>
#include "piFunctions.h"

using namespace std;

bool underOrInside(pair<int, int> coord, pair<int, int> f1, pair<int, int> f2, int majorAxis) {
    pair<int, int> center((f1.first + f2.first)/2, (f1.second + f2.second)/2);
    float distance1 = sqrt(pow(abs(coord.first - f1.first), 2) + pow(abs(coord.second - f1.second) * 5/2, 2));
    float distance2 = sqrt(pow(abs(coord.first - f2.first), 2) + pow(abs(coord.second - f2.second) * 5/2, 2));
    return abs(distance1 + distance2) <= majorAxis || 
            (coord.first <= center.first + majorAxis/2 
            && coord.first >= center.first - majorAxis/2 
            && coord.second >= center.second);
}


bool aboveOrInside(pair<int, int> coord, pair<int, int> f1, pair<int, int> f2, int majorAxis) {
    pair<int, int> center((f1.first + f2.first)/2, (f1.second + f2.second)/2);
    float distance1 = sqrt(pow(abs(coord.first - f1.first), 2) + pow(abs(coord.second - f1.second) * 5/2, 2));
    float distance2 = sqrt(pow(abs(coord.first - f2.first), 2) + pow(abs(coord.second - f2.second) * 5/2, 2));
    return !(!(abs(distance1 + distance2) <= majorAxis) 
            && coord.second > center.second)
            && coord.first <= center.first + majorAxis/2 
            && coord.first >= center.first - majorAxis/2;
}

bool underNotInside(pair<int, int> coord, pair<int, int> f1, pair<int, int> f2, int majorAxis) {
    pair<int, int> center((f1.first + f2.first)/2, (f1.second + f2.second)/2);
    float distance1 = sqrt(pow(abs(coord.first - f1.first), 2) + pow(abs(coord.second - f1.second) * 5/2, 2));
    float distance2 = sqrt(pow(abs(coord.first - f2.first), 2) + pow(abs(coord.second - f2.second) * 5/2, 2));
    return !(abs(distance1 + distance2) <= majorAxis) 
            && coord.first <= center.first + majorAxis/2 
            && coord.first >= center.first - majorAxis/2
            && coord.second > center.second;
}

bool aboveNotInside(pair<int, int> coord, pair<int, int> f1, pair<int, int> f2, int majorAxis) {
    pair<int, int> center((f1.first + f2.first)/2, (f1.second + f2.second)/2);
    float distance1 = sqrt(pow(abs(coord.first - f1.first), 2) + pow(abs(coord.second - f1.second) * 5/2, 2));
    float distance2 = sqrt(pow(abs(coord.first - f2.first), 2) + pow(abs(coord.second - f2.second) * 5/2, 2));
    return !(abs(distance1 + distance2) <= majorAxis) &&
            (!(coord.second >= center.second)
            && coord.first <= center.first + majorAxis/2 
            && coord.first >= center.first - majorAxis/2);
}

bool aboveEdge(pair<int, int> coord, pair<int, int> p1, pair<int, int> p2) {
    return coord.first <= max(p1.first, p2.first)
        && coord.first >= min(p1.first, p2.first)
        && coord.second <= (p2.second - p1.second) / (double)(p2.first - p1.first) * (coord.first - p1.first) + p1.second;
}

bool underEdge(pair<int, int> coord, pair<int, int> p1, pair<int, int> p2) {
    return coord.first <= max(p1.first, p2.first)
        && coord.first >= min(p1.first, p2.first)
        && coord.second >= (p2.second - p1.second) / (double)(p2.first - p1.first) * (coord.first - p1.first) + p1.second;
}

bool betweenInnerPoints(pair<int, int> coord, pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4) {
    return (coord.first > max(p1.first, p2.first)
                && coord.first <= min(p3.first, p4.first)
                && coord.second >= min(min(p1.second, p2.second), min(p3.second, p4.second))
                && coord.second <= max(max(p1.second, p2.second), max(p3.second, p4.second)));
}