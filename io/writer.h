#ifndef WRITER_H
#define WRITER_H
#include <fstream>

#include <iostream>


class Writer
{
public:
    Writer();
    ~Writer();
    void WriteLine(std::string line);
    void Open();
    void DeleteFile();

private:
    void Close();
    std::ofstream myfile;
    std::string path;
};

#endif // WRITER_H
