#ifndef WALLET_H
#define WALLET_H


#include <list>
#include <map>
#include <iterator>
#include "model/transactions.h"
#include "io/writer.h"
#include "io/reader.h"

class Wallet
{
public:
    Wallet();
    bool AddTransaction(time_t *t, int *amount, std::string *tag, bool write);
    bool RemoveTransaction(time_t *t, int *amount, std::string *tag);
    int GetSumm();
    const std::map<std::string, int> * GetSummbyTag();
    std::list<std::string> GetTags();
    const std::list<Transactions> * GetTransactions();
    void erase();
private:
    void DeleteTransaction(Transactions * tr);
    void ReWrite();
    void Write(Transactions tr);
    void IncreaseVariables(int *amount, std::string *tag);
    std::list<Transactions> transactions;
    int summ;
    std::map<std::string, int> summByTags;
    Writer writer;

};

#endif // WALLET_H
