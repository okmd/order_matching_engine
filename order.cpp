#include "order.hpp"
Order::Order(string instrument, float price, int quantity, OPERATIONS operation, ORDER_TYPES order_type) {
    this->order_id = ++order_count;
    this->order_type = order_type;
    this->price = price;
    this->quantity = quantity;
    this->order_status = NEW;
    this->operation = operation;
    this->instrument = instrument;
}

void Order::set_status(ORDER_STATUS order_status) {
    this->order_status = order_status;
}
void Order::set_price(float price) {
    this->price = price;
}
void Order::set_quantity(unsigned int qty) {
    this->quantity = qty;
}
ORDER_TYPES Order::get_type() {
    return this->order_type;
}
ORDER_STATUS Order::get_status() {
    return this->order_status;
}
OPERATIONS Order::get_operation() {
    return this->operation;
}
std::string Order::get_instrument() {
    return this->instrument;
}
unsigned int Order::get_id() {
    return this->order_id;
}
unsigned int Order::get_quantity() {
    return this->quantity;
}
float Order::get_price() {
    return this->price;
}
void Order::show() {
    int W = 10;
    cout << "******_____ORDER_____******\n";
    cout << left;
    cout << setw(W) << "ORDERID: " << get_id() << endl;
    cout << setw(W) << "SECURITY: " << get_instrument() << endl;
    cout << setw(W) << "TYPE: " << ORDER_TYPES_STR[get_type()] << endl;
    cout << setw(W) << "PRICE: " << get_price() << endl;
    cout << setw(W) << "QUANTITY: " << get_quantity() << endl;
    cout << setw(W) << "STATUS: " << ORDER_STATUS_STR[get_status()] << endl;
    cout << setw(W) << "MODE: " << OPERATIONS_STR[get_operation()] << endl;
}