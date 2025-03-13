#ifndef SERVER_H
#define SERVER_H

#include <grpcpp/grpcpp.h>
#include "blockchain.grpc.pb.h"
#include "blockchain.h"
#include <utils.h>

class BlockChainServiceImpl final: public blockchain::BlockchainService::Service {
    Blockchain: block_chain;
public:
    grpc::Status AddTransaction(grpc::ServerContext* context, const blockchain::TransactionRequest* request, blockchain::TransactionResponse* response) override;
    grpc::Status GetLastBlock(grpc::ServerContext* context, const google::protobuf::Empty* request, blockchain::Block* response) override;
    
    void runServer();
}

#endif // SERVER_H