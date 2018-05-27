//
// Created by will on 5/24/18.
//
//#include <string>
#include <sstream>



#ifndef EVENT_BOOST_ORDER_H
#define EVENT_BOOST_ORDER_H

enum ORDER_STATUS{
    PENDING_NEW,
    ACTIVE,
    FILLED,
    REJECTED,
    PENDING_CANCEL,
    CANCELLED
};

enum ORDER_TYPE{
    MARKET,
    LIMIT
};

enum SIDE{
    BUY,
    SELL
};

enum POSITION_EFFECT{
    OPEN,
    CLOSE,
    CLOSE_TODAY
};

class order {
public:
    int get_order_id() const{ return order_id;}
    void set_order_id(int id){order_id=id;}
private:
    int order_id;
    int calendar_dt;
    int trading_dt;
    int quantity;
    std::string order_bood_id;
    SIDE side;
    POSITION_EFFECT position_effect;
    std::string message;
    int filled_quantity;
    ORDER_STATUS status;
    double frozen_price;
    ORDER_TYPE order_type;
    double avg_price;
    double transaction_cost;


};


#endif //EVENT_BOOST_ORDER_H
