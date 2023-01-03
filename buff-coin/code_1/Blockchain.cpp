#include <iostream>
#include <sstream>

#include "Transaction.hpp"
#include "Block.hpp"
#include "Blockchain.hpp"
#include <vector>

using namespace std;

Blockchain::Blockchain() {
    Transaction genesis("BFC","BFC",0);
    pending.push_back(genesis);

    Block gBlock(pending, gBlock.getTimeStamp(), "In the beginning..");
    chain.push_back(gBlock);

    Transaction freeMoney("BFC","make money by mining",0);
    pending.push_back(freeMoney);
    difficulty = 4;
    miningReward = 10;
}

Block Blockchain::getLatestBlock() { 
    return chain.back();
}

void Blockchain::addTransaction(string src, string dst, int coins) {
    // get balance of source address
    int balance = getBalanceOfAddress(src);
    // if the address has enough coins add the transaction
    if(balance > coins){
        Transaction addToPend = Transaction(src, dst, coins);
        pending.push_back(addToPend);
    }
    // else print error message
    else{
        cout << "ERROR balance is not greater than coins \n";
        return;
    }
    return;
}

bool Blockchain::isChainValid() { 
    // loop through blocks
    for(int i=1; i<chain.size(); i++){
        // return false if previous hash is not correct
        if(chain[i].previousHash != chain[i-1].hash){
            return false;
        }
        // make sure correct number of zeros are present
        for(int j=0; j<difficulty; j++){
            if(chain[i].hash[j] != '0'){
                return false;
            }
        }
    }
    return true;
}

bool Blockchain::minePendingTransactions(string minerAddress) {
    // create new block 
    Block nBlock = Block(pending, time(nullptr), chain.back().hash);
    nBlock.setTimeStamp(time(nullptr));
    // mine it with correct difficulty
    nBlock.mineBlock(difficulty);
    // clear list of pending transactions
    pending.clear();
    // push new block to the chain
    chain.push_back(nBlock);
    // reward miner in form of pending transaction
    Transaction mineReward = Transaction("BFC", minerAddress, miningReward);
    pending.push_back(mineReward);
    return true;
}

int Blockchain::getBalanceOfAddress(string address) {
    int balance = -1;
    // loop blocks in chain
    for(int i=0; i<chain.size(); i++){
        // loop transactions in chain[i]
        for(int j=0; j<chain[i].transactions.size(); j++){
            // address is recievng
            if(chain[i].transactions[j].getReceiver() == address){
                balance += chain[i].transactions[j].getAmount();
            }
            // address is sending
            else if(chain[i].transactions[j].getSender() == address){
                balance -= chain[i].transactions[j].getAmount();
                // make sure balance cant be negative
                if(balance < 0){
                    cout << "ERROR Balance tried to go negative\n";
                    balance = 0;
                }
            }

        }
    }
    return balance;
}

void Blockchain::prettyPrint() {
    // loop through chain
    for(int i=0; i<chain.size(); i++){
        // display hash and previous hash for each block
        cout << "Chain [" << i << "] hash: " << chain[i].hash;
            if(i != 0){
                cout << "  ||  Previous hash: " << chain[i].previousHash << endl;
            }
            else{
                cout << endl;
            }
        // display all transactions for each block
        for(int j=0; j<chain[i].transactions.size(); j++){
            cout << chain[i].transactions[j].toString() << endl;
        }
    }
}