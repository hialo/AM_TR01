#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "instance.h"
#include "neighbor.h"
#include "knn.h"
#include "filemanager.h"

using namespace std;

class FileManager {
  public:

    FileManager();
    vector <Instance> readingFile(string filepath);
    void generatingRandomTests (string filepath);

  private:

};

#endif