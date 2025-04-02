#include <iostream>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <vector>
#include <string>
using namespace std;
using namespace mongocxx;

class Database {
    static instance db_instance;
    client db_client;
    database db;
    collection coll;
    public:
    Database(string dbname, string collectionName, vector<int> clients_range)
    :db_client{uri{"mongodb://localhost:27017"}}
    {
        db = client[dbname];
        coll = db[collectionName];
        for(int i = clients_range[0]; i <= clients_range[1]; i++) {
            collection.insert_one(
                bsoncxx::builder::stream::document{}
                << "id" << i
                << "balance" << 100
                << bsoncxx::builder::stream::finalize 
            );
        }
    }
    void updateBalance(int id, int amount);
};