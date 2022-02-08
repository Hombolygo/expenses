#ifndef READER_H
#define READER_H
#include <fstream>

#include <iostream>

class Reader
{
public:
    Reader();
    ~Reader();
    std::string Read();
    bool isReadable();
private:
    std::ifstream file;
};

#endif // READER_H
