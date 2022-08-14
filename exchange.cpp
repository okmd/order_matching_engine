
#include "exchange.hpp"
Exchange::Exchange() {
    cout << "Created new Exchange\n";
}
void Exchange::make_order(shared_ptr<Order> order) {
    if (orders.count(order->get_instrument()) == 0)
        orders[order->get_instrument()] = shared_ptr<OrderBook>(new OrderBook());
    orders[order->get_instrument()]->match_order(order);
}
void Exchange::active_orders() {
    cout << "====================ACTIVE ORDERS====================\n";
    for (auto [ins, ptrs] : orders) {
        ptrs->active_orders();
    }
}
void Exchange::completed_orders() {
    cout << "====================COMPLETED ORDERS====================\n";
    for (auto [ins, ptrs] : orders) {
        ptrs->completed_orders();
    }
}