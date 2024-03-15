#include <iostream>
#include <math.h>

using namespace std;

//!underOrInside == aboveNotInside
bool underOrInside(pair<int, int> coord, pair<int, int> f1, pair<int, int> f2, int majorAxis) {
    pair<int, int> center((f1.first + f2.first)/2, (f1.second + f2.second)/2);
    float distance1 = sqrt(pow(abs(coord.first - f1.first), 2) + pow(abs(coord.second - f1.second) * 5/2, 2));
    float distance2 = sqrt(pow(abs(coord.first - f2.first), 2) + pow(abs(coord.second - f2.second) * 5/2, 2));
    return abs(distance1 + distance2) <= majorAxis || 
            (coord.first < center.first + majorAxis/2 && coord.first > center.first - majorAxis/2 && coord.second >= center.second);
}


//!underNotInside == aboveOrInside
bool underNotInside(pair<int, int> coord, pair<int, int> f1, pair<int, int> f2, int majorAxis) {
    pair<int, int> center((f1.first + f2.first)/2, (f1.second + f2.second)/2);
    float distance1 = sqrt(pow(abs(coord.first - f1.first), 2) + pow(abs(coord.second - f1.second) * 5/2, 2));
    float distance2 = sqrt(pow(abs(coord.first - f2.first), 2) + pow(abs(coord.second - f2.second) * 5/2, 2));
    return !(abs(distance1 + distance2) <= majorAxis) 
            && coord.first <= center.first + majorAxis/2 
            && coord.first >= center.first - majorAxis/2
            && coord.second > center.second;
}


bool aboveOrInside(pair<int, int> coord, pair<int, int> f1, pair<int, int> f2, int majorAxis) {
    pair<int, int> center((f1.first + f2.first)/2, (f1.second + f2.second)/2);
    float distance1 = sqrt(pow(abs(coord.first - f1.first), 2) + pow(abs(coord.second - f1.second) * 5/2, 2));
    float distance2 = sqrt(pow(abs(coord.first - f2.first), 2) + pow(abs(coord.second - f2.second) * 5/2, 2));
    return (abs(distance1 + distance2) <= majorAxis) 
            && coord.first <= center.first + majorAxis/2 
            && coord.first >= center.first - majorAxis/2
            && coord.second < center.second;
}


bool aboveNotInside(pair<int, int> coord, pair<int, int> f1, pair<int, int> f2, int majorAxis) {
    pair<int, int> center((f1.first + f2.first)/2, (f1.second + f2.second)/2);
    float distance1 = sqrt(pow(abs(coord.first - f1.first), 2) + pow(abs(coord.second - f1.second) * 5/2, 2));
    float distance2 = sqrt(pow(abs(coord.first - f2.first), 2) + pow(abs(coord.second - f2.second) * 5/2, 2));
    return !(abs(distance1 + distance2) <= majorAxis) || 
            (coord.first < center.first + majorAxis/2 && coord.first > center.first - majorAxis/2 && !(coord.second >= center.second));
}

bool aboveEdge(pair<int, int> coord, pair<int, int> p1, pair<int, int> p2) {
    return coord.first < max(p1.first, p2.first)
        && coord.first > min(p1.first, p2.first)
        && coord.second <= (p2.second - p1.second) / (double)(p2.first - p1.first) * (coord.first - p1.first) + p1.second; // = < p1.y
}


void printPie() {
    int pieRadius = 45;
    // int panRadius = (int)pieRadius * 4 / 5;
    int degreeOffset = 70; //degrees offset from the z axis
    pair<int, int> center(75, 25);
    int flatCrustHeight = 5;
    int panHeight = 10; //double crustHeight is nice

    double radOffset = degreeOffset * M_PI / 180;

    int riseMajorAxis = pieRadius * 2;
    int riseMinorAxis = (riseMajorAxis - flatCrustHeight * 2) * cos(radOffset) + flatCrustHeight * 2;

    int crustMajorAxis = pieRadius * 2;
    int crustMinorAxis = crustMajorAxis * cos(radOffset);

    int panMajorAxis = (int)(pieRadius * 2 * ((float)4 / 5));
    int panMinorAxis = panMajorAxis * cos(radOffset);


    pair<int, int> riseFocal1(center.first - sqrt(pow(pieRadius, 2) - pow(riseMinorAxis/2, 2)), center.second);
    pair<int, int> riseFocal2(center.first + sqrt(pow(pieRadius, 2) - pow(riseMinorAxis/2, 2)), center.second);

    pair<int, int> crustFocal1(center.first - sqrt(pow(pieRadius, 2) - pow(crustMinorAxis/2, 2)), center.second);
    pair<int, int> crustFocal2(center.first + sqrt(pow(pieRadius, 2) - pow(crustMinorAxis/2, 2)), center.second);

    pair<int, int> panFocal1(center.first - sqrt(pow((panMajorAxis/2), 2) - pow(panMinorAxis/2, 2)), center.second + panHeight * sin(radOffset));
    pair<int, int> panFocal2(center.first + sqrt(pow((panMajorAxis/2), 2) - pow(panMinorAxis/2, 2)), center.second + panHeight * sin(radOffset));

    cout << panFocal1.first << " " << panFocal1.second << endl << panFocal2.first << " " << panFocal2.second << " " << endl;

    for(size_t yIndex = 0; yIndex < 60; ++yIndex) {
        for(size_t xIndex = 0; xIndex < 150; ++xIndex) {
            pair<int, int> coord(xIndex, yIndex);
            if(coord == panFocal1 || coord == panFocal2) {
                cout << "f";
            } else if(underOrInside(coord, riseFocal1, riseFocal2, riseMajorAxis) && aboveOrInside(coord, riseFocal1, riseFocal2, riseMajorAxis)) {
                cout << "e";
            // } else if(underOrInside(coord, riseFocal1, riseFocal2, riseMajorAxis) && 
            // aboveOrInside(coord, crustFocal1, crustFocal2, crustMajorAxis)) {
            //     cout << "c";
            // } else if( 
            // aboveOrInside(coord, panFocal1, panFocal2, panMajorAxis)) {
            //     cout << "p";
            } else {
                cout << "-";
            }
        }
        cout << endl;
    }
    
}



int main() {
    cout << "Happy pi day!" << endl;
    printPie();
}