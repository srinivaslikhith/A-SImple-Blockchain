#include <database.h>
#include <utils.h>

instance Database::db_instance{};
void Database::updateBalance(int id, int amount) {
    coll.update_one(
        bsoncxx::builder::stream::document{} 
        << "id" << id 
        << bsoncxx::builder::stream::finalize,
        bsoncxx::builder::stream::document{} 
        << "$inc" << bsoncxx::builder::stream::open_document 
        << "balance" << amount 
        << bsoncxx::builder::stream::close_document 
        << bsoncxx::builder::stream::finalize
    );
}
