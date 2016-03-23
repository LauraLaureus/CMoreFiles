#ifndef IMAGEFILEFILTER_H
#define IMAGEFILEFILTER_H

#include "FileFilter.h"


class ImageFileFilter : public FileFilter
{
    private:
        bool belongsToFilter(char* ext);
        std::vector<char*> own_extensions;
        char* getExtension(char* name);
    public:
        ImageFileFilter(DirectoryLister* lister):FileFilter(lister){
            this->own_extensions.push_back(".jpg");
            this->own_extensions.push_back(".jpeg");
            this->own_extensions.push_back(".png");
            this->own_extensions.push_back(".gif");
        }
        std::vector<char*> filter();
};

#endif // IMAGEFILEFILTER_H
