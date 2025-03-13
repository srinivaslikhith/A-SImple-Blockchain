#include<client.h>

Client::Client(std::shared_ptr<grpc::Channel> channel)
    : stub_(blockchain::BlockchainService::NewStub(channel)) {}

void Client::AddTransaction(string txn) {
    blockchain::Transaction request;
    request.set_sender(string(1, txn[0]));
    request.set_receiver(string(1, txn[2]));
    request.set_amount(stoi(txn.substr(4, txn.size()-4)));
    blockchain::TransactionResponse response;
    grpc::ClientContext context;
    grpc::Status status = stub_->AddTransaction(&context, request, &response);
    if(status.ok()) {
        cout << "Transaction added successfully" << endl;
    } else {
        cout << "Transaction failed" << endl;
    }
}

void Client::GetLastBlock() {
    google::protobuf::Empty request;
    blockchain::Block response;
    grpc::ClientContext context;
    grpc::Status status = stub_->GetLastBlock(&context, request, &response);
    if(status.ok()) {
        cout << "Index: " << response.index() << endl;
        cout << "Timestamp: " << response.timestamp() << endl;
        cout << "Previous Hash: " << response.previous_hash() << endl;
        cout << "Current Hash: " << response.hash() << endl;
        for (blockchain::Transaction txn: response.transactions()) {
            cout << txn.sender() << "->" << txn.receiver() << ":" << txn.amount() << endl;
        }
    } else {
        cout << "Failed to get last block" << endl;
    }
}

void Client::ProcessCSV(string filename){
    ifstream file(filename);
    string line;
    while(getline(file, line)) {
        AddTransaction(line);
        GetLastBlock();
    }
}

int main() {
    Client client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
    client.ProcessCSV("files/transactions.csv");
    return 0;
}