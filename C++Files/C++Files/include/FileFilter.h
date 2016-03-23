#ifndef FILEFILTER_H
#define FILEFILTER_H
#include "../DirectoryLister.h"

class FileFilter
{
    public:
        FileFilter(DirectoryLister* lister);
        virtual std::vector<char*> filter(){
            return this->lister->getFileNames();
        }
    protected:
        DirectoryLister* lister;


};

#endif // FILEFILTER_H
