#include "transactions.h"


Transactions::Transactions(time_t t, int amount, std::string tag)
{
    this->date = t;
    this->amount = amount;
    this->tag = tag;
}

bool Transactions::operator==(Transactions const &trs){
    if(this->amount == trs.amount && this->date == trs.date && this->tag == trs.tag){
        return true;
    } else {
        return false;
    }

}


int Transactions::GetAmount(){
    return amount;
}

std::string Transactions::GetTag(){
    return tag;
}

time_t Transactions::Gettime_t(){
    return date;
};


std::string Transactions::getDate(){
    std::tm* now = std::localtime(&date);
    return std::to_string((now->tm_year + 1900)) + '-' + std::to_string(now->tm_mon + 1) + '-' + std::to_string(now->tm_mday);
}
