#include<bits/stdc++.h> 
#include <vector>
#include <utility>
#include "Point.h"

// iPair is integer pairs 
#define iPair std::pair<int, int> 

int findSide(iPair p1, iPair p2, iPair p);
int lineDist(iPair p1, iPair p2, iPair p);
void quickHull(iPair a[], int n, iPair p1, iPair p2, int side);
std::vector<Point> convexHullQuick(iPair a[], int n);
