all:
	g++ -o KNN main.cpp knn.cpp neighbor.cpp instance.cpp filemanager.cpp -W -Wall -ansi -pedantic
	echo 'USAGE: ./KNN data_set to generate the training an testing sets using a full data set, or ./KNN training_set testing_set'

clean:
	rm KNN
