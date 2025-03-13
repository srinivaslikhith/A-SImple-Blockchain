#ifndef UTILS_H
#define UTILS_H
#include <chrono>
#include <openssl/sha.h>
using namespace std;

int64_t getCurrentTimestamp() {
    return std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now().time_since_epoch()
    ).count();
}

std::string sha256(const std::string &input);
#endif // UTILS_H