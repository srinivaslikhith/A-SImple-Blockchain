#include<server.h>
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;


grpc::Status BlockChainServiceImpl::AddTransaction(grpc::ServerContext* context, const blockchain::TransactionRequest* request, blockchain::TransactionResponse* response) {
    std::string txn = request->sender() + "->" + request->receiver() + ":" + std::to_string(request->amount());
    // need to implement database functionality for stoing balances of clients.
    //will use mongodb for this purpose.
    //late will make it distributed.
    block_chain.AddTransaction(txn);
    response->set_success(true);
    response->set_message("Transaction added successfully");
    return Status::OK;
}

grpc::Status BlockChainServiceImpl::GetLastBlock(grpc::ServerContext* context, const google::protobuf::Empty* request, blockchain::Block* response) {
    Block lastBlock = block_chain.getLastBlock();
    response->set_index(lastBlock.index);
    response->set_timestamp(lastBlock.timestamp);
    response->set_prev_hash(lastBlock.prev_hash);
    response->set_curr_hash(lastBlock.curr_hash);
    return Status::OK;
}