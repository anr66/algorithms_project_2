#ifndef JARVISMARCH_H
#define JARVISMARCH_H

#include "Point.h"
#include <vector>
using std::vector;

int orientationJarvis(Point p, Point q, Point r);
vector<Point> convexHullJarvis(vector<Point> points, int n);

#endif