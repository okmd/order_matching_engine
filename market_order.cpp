#include "market_order.hpp"
MarketOrder::MarketOrder(std::string instrument, unsigned int quantity, OPERATIONS operation) : Order(instrument, 0, quantity, operation, MARKET) {
}