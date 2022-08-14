

#include "order_book.hpp"
OrderBook::OrderBook() {
    last_traded_price = 100;  // intially any stock is worth 100 rupee;
}

bool OrderBook::can_match(const shared_ptr<Order> node, const shared_ptr<Order> order) {
    if (order->get_operation() == node->get_operation()) return false;
    if (order->get_type() == MARKET) return true;
    if (order->get_operation() == SELL) return order->get_price() <= node->get_price();
    return order->get_price() >= node->get_price();
}
bool OrderBook::match_order(shared_ptr<Order> order) {
    auto sell_order = order->get_operation() == SELL;
    while (order->get_quantity() > 0) {
        auto invalid = (sell_order) ? bids.empty() : asks.empty();
        if (invalid) {
            (sell_order) ? asks[order->get_price()].push(order) : bids[order->get_price()].push(order);
            return FAILED;
        }
        auto map_iterator = (sell_order) ? bids.begin() : asks.begin();
        auto best_match_order = map_iterator->second.front();
        if (!can_match(best_match_order, order)) {
            auto &current_queue = (sell_order) ? asks[order->get_price()] : bids[order->get_price()];
            current_queue.push(order);
            return SUCCIEDED;
        }
        if (best_match_order->get_quantity() >= order->get_quantity()) {
            best_match_order->set_quantity(best_match_order->get_quantity() - order->get_quantity());
            best_match_order->set_status(PARTIAL);
            order->set_status(COMPLETE);
            // order->set_price(min(best_match_order->price, order->price));
            last_traded_price = order->get_price();
            finished_orders.push_back(order);
            last_traded_price = order->get_price();
            return SUCCIEDED;
        }
        order->set_quantity(order->get_quantity() - best_match_order->get_quantity());
        order->set_status(PARTIAL);
        best_match_order->set_status(COMPLETE);
        // best_match_order->set_price((sell_order)?order->price : best_match_order->price);
        last_traded_price = best_match_order->get_price();
        finished_orders.push_back(best_match_order);
        map_iterator->second.pop();
        if (map_iterator->second.empty()) (sell_order) ? bids.erase(map_iterator) : asks.erase(map_iterator);
    }
    return SUCCIEDED;
}
void OrderBook::active_orders() {
    for (auto [p, q] : bids) {
        queue<shared_ptr<Order>> qq = q;
        while (qq.size()) {
            qq.front()->show();
            qq.pop();
        }
    }
    for (auto [p, q] : asks) {
        queue<shared_ptr<Order>> qq = q;
        while (qq.size()) {
            qq.front()->show();
            qq.pop();
        }
    }
}
void OrderBook::completed_orders() {
    for (auto order : finished_orders) {
        order->show();
    }
}
