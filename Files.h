//
// Created by Kathleen Nguyen on 11/17/21.
//

#ifndef CATCHASE_FILES_H
#define CATCHASE_FILES_H
#include <SFML/Graphics.hpp>
#include <map>
#include "File.h"

template <class T, class S>
class Files
{
private:
    static std::map<T, S> files;
    static std::string getFilePath(T fileName);
    static void loadFile(T fileName);

public:
    static S& getFile(T fileName);
};

#include "Files.cpp"
#endif //CATCHASE_FILES_H
