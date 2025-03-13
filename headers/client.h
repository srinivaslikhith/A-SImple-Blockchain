#ifndef CLIENT_H
#define CLIENT_H

#include<grpcpp/grpcpp.h>
#include "blockchain.grpc.pb.h"
#include <utils.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class Client{
public:
    void AddTransaction(string txn);
    void GetLastBlock();
    Client(std::shared_ptr<grpc::Channel> channel);
    void ProcessCSV(string filename);

private:
    unique_ptr<blockchain::BlockchainService::Stub> stub_;
};
#endif // CLIENT_H