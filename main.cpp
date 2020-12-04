#include <iostream>
#include <fstream>
#include "elipseCounter.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include "vector"

using namespace std;
int main() {
    ofstream fout("table.txt");
    double a = 100;
    double b = 99;
    float year = 365.25;
    double e = 0.017;
//    e = 0;
    elipseCounter orbit(e, year);
    vector<double> gamma{0};   //vertical angle metric for polus
    vector<double> betta{0};   // horizontal angle metric that counts daily shift
    double gammaDV = 23.5*M_PI/180;     // tilt of planet axis
//    gammaDV = 0;
    for (int i = 0; i <= year*500; ++i) {
        orbit.turn();
        double alpha = orbit.angle;
        gamma.push_back( asin(sin(gammaDV)*sin(alpha)) );
        double newBeta;
        if (sin(alpha) >= 0) {
            newBeta = acos(cos(alpha) / cos(gamma[gamma.size() - 1]));
        }
        else {
            newBeta = -acos(cos(alpha) / cos(gamma[gamma.size() - 1]));
        }
        while (newBeta < betta[betta.size()-1]) {
            newBeta += 2*M_PI;
        }
        betta.push_back(newBeta);
    }
    for (int i = 0; i < gamma.size(); ++i) {
        fout << betta[i]-i*2*M_PI/year << '\t' << gamma[i] <<  '\n';
    }
    return 0;
}
