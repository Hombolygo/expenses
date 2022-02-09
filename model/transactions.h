#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include <iostream>
#include <ctime>

class Transactions
{
public:
    Transactions(time_t t, int amount, std::string tag);
    int GetAmount();
    std::string GetTag();
    time_t Gettime_t();
    std::string getDate();
    bool operator==(Transactions const &first);
private:

    int amount;
    std::string tag;
    time_t date;

};



#endif // TRANSACTIONS_H
