//
// Created by amirf on 14.11.2020.
//

#ifndef ASTRONOMYPROJECT_ELIPSECOUNTER_H
#define ASTRONOMYPROJECT_ELIPSECOUNTER_H
#define _USE_MATH_DEFINES


#include <iostream>
#include "math.h"


class elipseCounter {
public:
    double angle;
    double p;
    double e;
    double space;
    float year;
    double deltaAngle = 0.000001;

//    elipseCounter(double A, double B, float Year) {
//        a = A;
//        b = B;
//        year = Year;
//        e = sqrt(1-b*b/(a*a));
//        p = b*b/a;
//        space = M_PI*a*b;
//        angle = 0;
//    }

    double anglePerig;

    elipseCounter(double E, float Year) {       // for small у only
        e = E;
        year = Year;
        p = 1;
        space = p*p*M_PI/pow(1-e*e, 3.0/2);
        angle = 0;
        anglePerig = -77*2*M_PI/year;
    }
    double distance(){
        return p/(1+e*cos(angle-anglePerig));
    }
    void turn(){
        double goneSpace = 0;
        while (goneSpace < space/year) {
            angle += deltaAngle;
            goneSpace += pow(distance(), 2) * deltaAngle / 2;
        }
//        if (angle > 2*M_PI) {
//            angle -= 2*M_PI;
//        }
    }




};


#endif //ASTRONOMYPROJECT_ELIPSECOUNTER_H
