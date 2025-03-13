#ifndef UTILS_H
#define UTILS_H
#include <chrono>
#include <openssl/sha.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdint>
using namespace std;

int64_t getCurrentTimestamp();

std::string sha256(const std::string &input);
#endif // UTILS_H