#include "filemanager.h"

FileManager::FileManager(){}

void FileManager::generatingRandomTests (string filepath){
/*	int size;
	int test_size = size/10; // Test data has 10% of total cases.

	bool *used = new bool[size];
	string testfile = "";
	string datafile = "";


	ifstream file (filepath.c_str());

	string line;

	if(!file.is_open()) {
        cout << "Impossible to open the file!!!" << endl;
        exit(-1);
    }

    while (getline(file, line)){
    	if (count < test_size && !used){
    		testfile += line + "\n";
    	}

    	else if (count >= test_size && !used)
    		datafile += line + "\n";

    	count++;
    }

    return set;*/
}

vector <Instance> FileManager::readingFile(string filepath){
	vector <Instance> set;
	ifstream file (filepath.c_str());

	string line;
	int i;

	if(!file.is_open()) {
        cout << "Impossible to open the file!!!" << endl;
        exit(-1);
    }

    while (getline(file, line)){
    	stringstream ss (line);
    	vector<int> attrib;

    	while (ss >> i){
    		attrib.push_back(i);

    		if (ss.peek() == ',')
    			ss.ignore();
    	}

    	int classif = attrib.back();
    	attrib.pop_back();

    	Instance in = Instance (attrib, classif);

    	set.push_back(in);
    }

    return set;
}