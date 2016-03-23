/*
 * DirectoryLister.h
 *
 *  Created on: 23 de mar. de 2016
 *      Author: Laura
 */

#ifndef DIRECTORYLISTER_H_
#define DIRECTORYLISTER_H_
#include <dirent.h>
#include <vector>

class DirectoryLister {
private:
    std::vector<char*> fileNames;
public:
	DirectoryLister(char* dirPath);
	std::vector<char*> getFileNames();
};

#endif /* DIRECTORYLISTER_H_ */
