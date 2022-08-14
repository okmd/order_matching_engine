#include <iomanip>
#include <iostream>

#include "constant.hpp"
using namespace std;
#ifndef ORDER_HPP
#define ORDER_HPP
class Order {
   private:
    inline static unsigned int order_count;
    ORDER_TYPES order_type;
    OPERATIONS operation;
    unsigned int quantity;
    float price;
    unsigned int order_id;
    ORDER_STATUS order_status;
    string instrument;

   public:
    Order(string, float, int, OPERATIONS, ORDER_TYPES);
    void set_status(ORDER_STATUS);
    void set_quantity(unsigned int);
    void set_price(float);
    ORDER_TYPES get_type();
    ORDER_STATUS get_status();
    OPERATIONS get_operation();
    string get_instrument();
    unsigned int get_id();
    unsigned int get_quantity();
    float get_price();

    void show();
};
#endif