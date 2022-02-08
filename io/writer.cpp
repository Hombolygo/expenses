#include "writer.h"

Writer::Writer()
{
    path = "data.csv";
    Open();
}

Writer::~Writer(){
    myfile.close();
}

void Writer::WriteLine(std::string line){
    myfile << line << std::endl;
}

void Writer::DeleteFile(){
    Close();
    const char * c = path.c_str();
    std::remove(c);
}

void Writer::Close(){
    myfile.close();
}

void Writer::Open(){
    myfile.open(path, std::ios_base::app);
}
