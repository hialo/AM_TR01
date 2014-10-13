#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include "instance.h"
#include "neighbor.h"
#include "knn.h"
#include "filemanager.h"

using namespace std;


/*********************************************************/

int main (int argc, char* argv []){
	if(argc == 1) {
        cout << "ERROR: You need to pass the full dataset (./KNN dataset)" << 
                " or the training set and test set (./KNN trainset testset)." << endl;
    }

    if (argc == 2){
    	string dataset = argv[1];
    	FileManager fm;

    	fm.generatingRandomTests(dataset);

    }

    if (argc == 3){
    	string dataset = argv[1];
    	string testset = argv[2];

    	vector <Instance> data;
    	vector <Instance> test;

    	FileManager fm;

	   	data = fm.readingFile(dataset);
	   	test = fm.readingFile(testset);

	   	KNN knn;

	   	cout << "Precision of the algorithm on this test database: " << fixed << setprecision (2) 
	   	     << knn.getPrecision (data, test) * 100 << "%"<< endl;

    }

	return 0;
}