#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include<vector>
#include<string>
#include<utils.h>

using namespace std;
class Block {
    int index;
    int64_t timestamp;
    vector<string> transactions;
    string prev_hash;
    string curr_hash;
public:
    Block(int i, string prevHash);
    void ComputeCurrentHash();
    friend class Blockchain;
    friend class BlockChainServiceImpl;
};

class Blockchain {
    vector<Block> chain;
    int transaction_limit = 5;
    vector<string> pending_transactions;
public:
    Blockchain();
    void AddTransaction(string txn);
    Block getLastBlock();
};
#endif // BLOCKCHAIN_H