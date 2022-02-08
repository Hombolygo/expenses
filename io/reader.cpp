#include "reader.h"

Reader::Reader()
{
    std::string path = "data.csv";
    file.open(path,std::ios_base::in);
}

Reader::~Reader(){
    file.close();
}

std::string Reader::Read()
{
    std::string data;

    if (!file.fail() && !file.eof())
        file >> data;

    return data;
}

bool Reader::isReadable(){
    return (!file.fail() && !file.eof());
}
