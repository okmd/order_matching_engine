#include "order.hpp"
#ifndef LIMIT_ORDER_HPP
#define LIMIT_ORDER_HPP

class LimitOrder : public Order {
   public:
    LimitOrder(std::string, float, unsigned int, OPERATIONS);
};
#endif