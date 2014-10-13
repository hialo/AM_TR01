#ifndef KNN_H
#define KNN_H

using namespace std;

#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <iostream>
#include "instance.h"
#include "neighbor.h"


class KNN {
  public:

    KNN();
    double calculateDistance(Instance target, Instance neighbor);
    bool classifyingInstance(Instance target, vector<Instance> trainingData);
    int getMajority(vector<Neighbor> nearest);
    double getPrecision(vector<Instance> trainingData, vector<Instance> testingData);

  private:

};

#endif