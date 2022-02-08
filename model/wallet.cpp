#include "wallet.h"


Wallet::Wallet()
{
    summ = 0;
    Reader r;
    while (r.isReadable()){
        try{
        int a = stoi(r.Read());
        time_t time = std::stoll(r.Read());
        std::string t = r.Read();
        AddTransaction(&time, &a, &t, false);
        } catch (std::exception ex){
            continue;
        }
    }
}

bool Wallet::AddTransaction(time_t *t, int *amount, std::string *tag, bool write=true){
    try{
        Transactions tr = Transactions(*t, *amount, *tag);
        transactions.push_back(tr);
        IncreaseVariables(amount, tag);
        if(write)
            Write(tr);
    } catch (std::exception ex){
        return false;
    }

    return true;
}

bool Wallet::RemoveTransaction(time_t *t, int *amount, std::string *tag){
    try{
        Transactions tr = Transactions(*t, *amount, *tag);
        DeleteTransaction(&tr);
        int anount_1 = *amount * (-1);
        IncreaseVariables(&anount_1, tag);
    } catch (std::exception ex){
        return false;
    }
    ReWrite();

    return true;
}

void Wallet::DeleteTransaction(Transactions *tr){
    std::list<Transactions>::iterator it = transactions.begin();
    while (it != transactions.end())
    {
        if (*tr == *it){
            transactions.erase(it);
            break;
        }
        else {
            it++;
        }
    }
}



int Wallet::GetSumm(){
    return summ;
}

void Wallet::IncreaseVariables(int *amount, std::string *tag){
    this->summ += *amount;
    if (this->summByTags.find(*tag) != summByTags.end()){
        this->summByTags[*tag] += *amount;
    }else {
        this->summByTags[*tag] = *amount;
    }
}

const std::list<Transactions> *  Wallet::GetTransactions(){
    return &transactions;
}

std::list<std::string> Wallet::GetTags(){
    std::list<std::string> tags;
    for (auto e : summByTags){
        tags.push_back(e.first);
    }
    return tags;
}

const std::map<std::string, int> * Wallet::GetSummbyTag(){
    return &summByTags;
}

void Wallet::erase(){
    this->summ = 0;
    this->summByTags.clear();
    this->transactions.clear();
}

void Wallet::ReWrite(){
    writer.DeleteFile();
    writer.Open();

    for (auto e : transactions){
        Write(e);
    }
}

void Wallet::Write(Transactions tr){
    std::string str = std::to_string(tr.GetAmount()) + " " + std::to_string(tr.Gettime_t()) + " " + tr.GetTag();
    this->writer.WriteLine(str);
}


