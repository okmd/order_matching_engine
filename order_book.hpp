
#include <map>
#include <memory>
#include <queue>
#include <unordered_map>
#include <vector>
#include "order.hpp"
#ifndef ORDER_BOOK_HPP
#define ORDER_BOOK_HPP

class OrderBook {
   private:
    map<float, queue<shared_ptr<Order>>> asks;
    map<float, queue<shared_ptr<Order>>, greater<float>> bids;
    vector<shared_ptr<Order>> finished_orders;
    float last_traded_price;

   public:
    OrderBook();
    bool can_match(const shared_ptr<Order>, const shared_ptr<Order>);
    bool match_order(shared_ptr<Order>);
    void active_orders();
    void completed_orders();
};
#endif