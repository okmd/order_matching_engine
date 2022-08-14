#ifndef CONSTANT_HPP
#define CONSTANT_HPP
#include <iostream>
enum ORDER_TYPES { LIMIT, MARKET };
enum OPERATIONS { BUY, SELL };
enum ORDER_STATUS { NEW, PARTIAL, COMPLETE };
enum TRANSACTION { FAILED, SUCCIEDED };
const std::string ORDER_TYPES_STR[] = {"LIMIT", "MARKET"};
const std::string OPERATIONS_STR[] = {"BUY", "SELL"};
const std::string ORDER_STATUS_STR[] = {"NEW", "PARTIAL", "COMPLETE"};
const std::string TRANSACTION_STR[] = {"FAILED", "SUCCIEDED"};
#endif