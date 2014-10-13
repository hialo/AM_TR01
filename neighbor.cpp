#include "neighbor.h"

Neighbor::Neighbor(){}

Neighbor::Neighbor(int distance, int classification) {
    this->distance = distance;
    this->classification = classification;
}

int Neighbor::getClassification() {
    return this->classification;
}

int Neighbor::getDistance() {
    return this->distance;
}