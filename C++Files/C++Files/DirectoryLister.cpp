/*
 * DirectoryLister.cpp
 *
 *  Created on: 23 de mar. de 2016
 *      Author: Laura
 */
#ifndef STDLIB
#include <cstdio>
#endif
#include <string.h>
#include "DirectoryLister.h"

DirectoryLister::DirectoryLister(char* dirPath) {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (dirPath)) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            this->fileNames.push_back(strdup(ent->d_name));
            printf("%s\n",ent->d_name);
        }
        closedir (dir);
        printf("end of list\n");
    }

    else {
    perror ("Unable to open the directory");

    }

}

std::vector<char*> DirectoryLister::getFileNames(){
    std::vector<char*> cpy = this->fileNames;
    return cpy;
}

