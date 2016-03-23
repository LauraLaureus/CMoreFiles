#include "ImageFileFilter.h"
#include <string.h>
#include <stdio.h>

std::vector<char*> ImageFileFilter::filter(){

    std::vector<char*> results, filNames = this->lister->getFileNames();
    for(unsigned int i = 0; i < filNames.size();i++){
        if(belongsToFilter(getExtension(filNames.at(i)))){
            results.push_back(strdup(filNames.at(i)));
            printf("%s\n",filNames.at(i));
        }
    }
    return results;
}


bool ImageFileFilter::belongsToFilter(char* ext){
    bool result = false;
    for(unsigned int i = 0; i < this->own_extensions.size();i++){
        if(0 == strcmp(this->own_extensions.at(i),ext)){
            result = true;
            break;
        }
    }
    return result;
}

char* ImageFileFilter::getExtension(char* name){
    char result[6];
    result[5] = '\0';
    short int extensionlen = 0, pointer = 4;
    while (extensionlen <6 && name[strlen(name)-extensionlen-1] != '.'){
        result[pointer] = name[strlen(name)-extensionlen-1];
        pointer -=1;
        extensionlen +=1;
    }
    if(extensionlen > 0){
        char result2[6-extensionlen];
        for(short int i = 0;  i <6-extensionlen; i++){
            result2[i] = result[i+extensionlen];
        }
        return result2;
    }else{
        return result;
    }
}
