#include <math.h>
#ifndef PI_FUNCTIONS_H
#define PI_FUNCTIONS_H

using namespace std;

bool underOrInside(pair<int, int> coord, pair<int, int> f1, pair<int, int> f2, int majorAxis);
bool aboveOrInside(pair<int, int> coord, pair<int, int> f1, pair<int, int> f2, int majorAxis);
bool underNotInside(pair<int, int> coord, pair<int, int> f1, pair<int, int> f2, int majorAxis);
bool aboveNotInside(pair<int, int> coord, pair<int, int> f1, pair<int, int> f2, int majorAxis);
bool aboveEdge(pair<int, int> coord, pair<int, int> p1, pair<int, int> p2);
bool underEdge(pair<int, int> coord, pair<int, int> p1, pair<int, int> p2);
bool betweenInnerPoints(pair<int, int> coord, pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4);

#endif