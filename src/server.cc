#include<server.h>
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;


grpc::Status BlockChainServiceImpl::AddTransaction(grpc::ServerContext* context, const blockchain::Transaction* request, blockchain::TransactionResponse* response) {
    std::string txn = request->sender() + "," + request->receiver() + "," + std::to_string(request->amount());
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
    response->set_previous_hash(lastBlock.prev_hash);
    response->set_hash(lastBlock.curr_hash);
    for (string txn: lastBlock.transactions) {
        blockchain::Transaction* transaction = response->add_transactions();
        transaction->set_sender(string(1, txn[0]));
        transaction->set_receiver(string(1, txn[2]));
        transaction->set_amount(stoi(txn.substr(4, txn.size()-4)));
    }
    return Status::OK;
}

void BlockChainServiceImpl::runServer() {
    std::string server_address("localhost:50051");
    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(this);
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
}
int main() {
    BlockChainServiceImpl service;
    service.runServer();
    return 0;
}