

#ifndef EXCHANGE_HPP
#define EXCHANGE_HPP
#include "order_book.hpp"
class Exchange {
   private:
    unordered_map<string, shared_ptr<OrderBook>> orders;

   public:
    Exchange();
    void make_order(shared_ptr<Order>);
    void active_orders();
    void completed_orders();
};
#endif