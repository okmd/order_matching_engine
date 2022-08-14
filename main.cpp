#include "exchange.hpp"
#include "limit_order.hpp"
#include "market_order.hpp"
#include "order.hpp"

int main() {
    Exchange NSE;
    NSE.make_order(shared_ptr<Order>(new LimitOrder("Google", 20, 400, SELL)));
    NSE.make_order(shared_ptr<Order>(new LimitOrder("Google", 50, 300, SELL)));
    NSE.make_order(shared_ptr<Order>(new LimitOrder("Microsoft", 100, 200, BUY)));
    NSE.make_order(shared_ptr<Order>(new LimitOrder("Microsoft", 20, 300, SELL)));
    NSE.make_order(shared_ptr<Order>(new LimitOrder("Google", 100, 470, BUY)));
    NSE.make_order(shared_ptr<Order>(new MarketOrder("Facebook", 150, BUY)));
    NSE.make_order(shared_ptr<Order>(new MarketOrder("Facebook", 150, BUY)));
    NSE.make_order(shared_ptr<Order>(new MarketOrder("Microsoft", 150, BUY)));
    NSE.active_orders();
    NSE.completed_orders();

    return 0;
}

// TODO: When only buy and sell of MARKET order;