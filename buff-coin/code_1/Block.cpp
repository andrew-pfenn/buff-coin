#include<iostream>
#include <sstream>

#include "Blockchain.hpp"
#include "Transaction.hpp"
#include "Block.hpp"
#include "sha256.hpp"

using namespace std;

Block::Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash) {
    nonce = -1;
    transactions = _transactions;
    previousHash = _previousHash;
    timestamp = _timestamp;
    hash = calculateHash();
}

void Block::setPreviousHash(string _previousHash) {
    previousHash = _previousHash;
}

string Block::calculateHash() {
    // toString() as parameter for sha256()
    return sha256(toString());
}

void Block::mineBlock(unsigned int difficulty) {
    bool validHash = false;
    // while loop to keep creating new hash until its valid
    while(validHash == false){
        // variable to count number of 0's in the first #difficulty characters
        int counter = 0;
        for(int i=0; i<difficulty; i++){
            // if character = 0 add to counter 
            if(hash[i] == '0'){
                counter++;
                // if the counter has the corrext number of 0's break the loop and return
                if(counter == difficulty){
                    validHash = true;
                    return;
                }
            }
        }
        // add to nonce and get new hash
        nonce++;
        hash = calculateHash();
    }
    return;
}

string Block::toString(){
    // create ss object
    stringstream ss;
    // put all variables into string 
    ss << nonce << previousHash << timestamp;
    for(int j=0; j<transactions.size(); j++){
        ss << transactions[j].toString();
    }
    // return the complete string
    return ss.str();
}

time_t Block::getTimeStamp(){
    return timestamp;
}

void Block::setTimeStamp(time_t time){
    timestamp = time;
}