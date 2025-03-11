#include<blockchain.h>
Block::Block(int i, string prevHash) {
    index = i;
    prev_hash = prevHash;
    timestamp = getCurrentTimestamp();
    transactions = {};
}

void Block::ComputeCurrentHash() {
    string transaction_str = "";
    for (string& txn: transactions) {
        transaction_str += txn + '|';
    }
    string block_data = to_string(index) +
                        to_string(timestamp) +
                        prev_hash +
                        transaction_str;
    curr_hash = sha256(block_data);
}

Blockchain::Blockchain() {
    chain = {Block(0, "0")};
}

void Blockchain::AddTransaction(string txn) {
    if(pending_transactions.size() == transaction_limit) {
        Block newBlock(chain.size(), chain.back().prev_hash);
        newBlock.transactions = pending_transactions;
        newBlock.ComputeCurrentHash();
        chain.push_back(newBlock);
        pending_transactions.clear();
    }
    pending_transactions.push_back(txn);
}

Block Blockchain::getLastBlock() {
    return chain.back();
}
