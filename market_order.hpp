#include "order.hpp"
#ifndef MARKET_ORDER_HPP
#define MARKET_ORDER_HPP

class MarketOrder : public Order {
   public:
    MarketOrder(std::string, unsigned int, OPERATIONS);
};
#endif