#include "knn.h"

KNN::KNN(){}

/******************************************************************/

bool compare(Neighbor a, Neighbor b) {
    return a.getDistance() < b.getDistance();
}

/******************************************************************/

double KNN::calculateDistance(Instance target, Instance neighbor){
	double distance = 0.0;

	vector <int> localAttr, neighAttr;

	localAttr = target.getAttributes();
	neighAttr = neighbor.getAttributes();

	for (unsigned int i = 0; i < localAttr.size(); i++){
		distance += pow ((localAttr[i] - neighAttr[i]), 2);
	}

	return sqrt (distance);
}

/******************************************************************/

int KNN::getMajority(vector<Neighbor> nearest){
    map<int,int> count;
    int classification;

    int aux = 0;

    for(unsigned int i = 0; i < nearest.size(); i++)
        count[nearest[i].getClassification()]++;

    map <int,int>::iterator it = count.begin();

    for(;it != count.end(); ++it) {

        if(it->second > aux) {
            classification = it->first;
            aux = it->second;
        }
    }

    return classification;	
}

/******************************************************************/

bool KNN::classifyingInstance(Instance target, vector<Instance> trainingData){
	vector<Neighbor> neigh;
	vector <Neighbor> nearest;

	double distance;
	int k = 3; // Number of k neighbors to compare. 

	for (unsigned int i = 0; i < trainingData.size(); i++){
		distance = calculateDistance(target, trainingData[i]);
		Neighbor n = Neighbor(distance, trainingData[i].getClassification());

		//cout << "Distance: " << distance << endl;

		neigh.push_back(n);
	}

	sort (neigh.begin(), neigh.end(), compare);

	for (int i = 0; i < k; i++){
		nearest.push_back(neigh[i]);
	}

	int classification = getMajority(nearest);

	if (target.getClassification() == classification)
		return true;

	return false;
}

/******************************************************************/

double KNN::getPrecision(vector<Instance> trainingData, vector<Instance> testingData){
	int right = 0;
	int wrong = 0;

	for (unsigned int i = 0; i < testingData.size(); i++){
		if (classifyingInstance(testingData[i], trainingData))
			right++;
		else
			wrong++;	   		
	}

   	cout << "Number of instances correctly classified: " << right << endl;
   	cout << "Total of instances: " << right + wrong << endl;

   	return ((double)right / (double)(right + wrong));

}

