#ifndef NEIGHBOR_H
#define NEIGHBOR_H

using namespace std;

#include <vector>

class Neighbor {
  public:

    Neighbor();
    Neighbor(int distance, int classification);
    int getDistance();
    int getClassification();

  private:
  	int distance;
    int classification;
};

#endif