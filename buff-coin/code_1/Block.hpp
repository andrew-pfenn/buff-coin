#pragma once
#include<iostream>
#include <vector>
#include "Transaction.hpp"

using namespace std;

class Block {
protected:
    long long nonce; // An arbitrary number crucial in mining
    time_t timestamp; // Time when mined 
    
    
public:
     string hash; // Hash of this block
     vector<Transaction> transactions; //vector of transactions
     string previousHash; // Hash of previous block

    time_t getTimeStamp();
    void setTimeStamp(time_t time);
    Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash);
    void setPreviousHash(string hash);
    string calculateHash();
    void mineBlock(unsigned int nDifficulty);
    string toString();
};

