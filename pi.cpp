#include <iostream>
#include <math.h>
#include <string>
#include "piFunctions.h"

using namespace std;

void printPie(int degreeOffset) {
    int pieRadius = 45;
    pair<int, int> center(75, 19);
    int flatCrustHeight = 5;
    int panHeight = 7; //double crustHeight is nice

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


    pair<int, int> crustLeftPoint(center.first - crustMajorAxis / 2, center.second);
    pair<int, int> crustRightPoint(center.first + crustMajorAxis / 2, center.second);
    pair<int, int> panLeftPoint(center.first - panMajorAxis / 2, panFocal1.second);
    pair<int, int> panRightPoint(center.first + panMajorAxis / 2, panFocal1.second);

    float slashProportionToEdge = 1.5;
    pair<int, int> crustMiddleLeftPoint(center.first - (float)crustMajorAxis / 6 * slashProportionToEdge, center.second);
    pair<int, int> crustMiddleRightPoint(center.first + (float)crustMajorAxis / 6 * slashProportionToEdge, center.second);
    pair<int, int> panMiddleLeftPoint(center.first - (float)panMajorAxis / 6 * slashProportionToEdge, panFocal1.second);
    pair<int, int> panMiddleRightPoint(center.first + (float)panMajorAxis / 6 * slashProportionToEdge, panFocal1.second);



    for(size_t yIndex = 0; yIndex < 39; ++yIndex) {
        for(size_t xIndex = 0; xIndex < 150; ++xIndex) {
            pair<int, int> coord(xIndex, yIndex);
            // if(coord == riseFocal1 || coord == riseFocal2) {
            //     cout << "f";
            // } else if (coord == crustLeftPoint || coord == crustRightPoint || coord == panLeftPoint || coord == panRightPoint) {
            //     cout << "d";
            // } else 
            if(underOrInside(coord, riseFocal1, riseFocal2, riseMajorAxis) 
                && aboveOrInside(coord, crustFocal1, crustFocal2, crustMajorAxis)) {
                cout << "π";
            } else if((aboveEdge(coord, crustLeftPoint, panLeftPoint)
                        && underNotInside(coord, crustFocal1, crustFocal2, crustMajorAxis))
                    || (underEdge(coord, crustMiddleLeftPoint, panMiddleLeftPoint)
                        && aboveOrInside(coord, panFocal1, panFocal2, panMajorAxis))
                    || (betweenInnerPoints(coord, crustLeftPoint, panLeftPoint, crustMiddleLeftPoint, panMiddleLeftPoint))) {
                    cout << "\\";
            } else if((aboveEdge(coord, crustRightPoint, panRightPoint)
                        && underNotInside(coord, crustFocal1, crustFocal2, crustMajorAxis))
                    || (underEdge(coord, crustMiddleRightPoint, panMiddleRightPoint)
                        && aboveOrInside(coord, panFocal1, panFocal2, panMajorAxis))
                    || (betweenInnerPoints(coord, crustMiddleRightPoint, panMiddleRightPoint, crustRightPoint, panRightPoint))) {
                    cout << "/";
            } else if((aboveOrInside(coord, panFocal1, panFocal2, panMajorAxis)
                        || aboveEdge(coord, crustLeftPoint, panLeftPoint)
                        || aboveEdge(coord, crustRightPoint, panRightPoint))
                && (underNotInside(coord, crustFocal1, crustFocal2, crustMajorAxis))) {
                cout << "|";
            } else {
                cout << "-";
            }
        }
        cout << endl;
    }
    
}



int main() {
    cout << "Happy pi day!" << endl;
    string input;
    int angle = 90;
    while(input != "exit") {
        printPie(angle);
        cout << "Next direction (w/a/s/d): ";
        cin >> input;
        if(input == "s" && angle < 90) {
            angle = min(angle + 10, 90);
        } else if(input == "w" && angle > 0) {
            angle = max(angle - 10, 0);
        }
    }
}