
#include "limit_order.hpp"
LimitOrder::LimitOrder(std::string instrument, float price, unsigned int quantity, OPERATIONS operation) : Order(instrument, price, quantity, operation, LIMIT) {

}