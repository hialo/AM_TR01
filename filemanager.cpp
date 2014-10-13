#include "filemanager.h"

FileManager::FileManager(){}

void FileManager::writingFile (string text, string type){
	ofstream output;
	type += "_data_file";

	const char* filepath = type.c_str();

	output.open (filepath);

	output << text;

	output.close();
}


void FileManager::generatingRandomTests (string filepath){
	ifstream file (filepath.c_str());

	string line;
	string test = "";
	string training = "";
	int count = 1;

	if(!file.is_open()) {
        cout << "Impossible to open the file!!!" << endl;
        exit(-1);
    }

    cout << "Generating training and test cases..." << endl;

    while (getline(file, line)){
    	if (count % 5 == 0)
    		test += line + "\n";
    	
    	else 
    		training += line + "\n";

    	count++;
    }

    writingFile(test, "test");
    writingFile(training, "train");

    cout << "Done." << endl;

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