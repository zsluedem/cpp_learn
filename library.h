#ifndef EVENT_BOOST_LIBRARY_H
#define EVENT_BOOST_LIBRARY_H

#include <Python.h>
#include "vector"
#include "boost/python.hpp"
#include "boost/python/dict.hpp"
#include "boost/python/ob"
#include "map"

enum EVENT{
    //        # 系统初始化后触发
    POST_SYSTEM_INIT,

    //在实盘时，你可能需要在此事件后根据其他信息源对系统状态进行调整
    POST_SYSTEM_RESTORED,

    //回测结束调用
    BACKTEST_END,

    //策略执行完init函数后触发
    //post_user_init()
    POST_USER_INIT ,
    //策略证券池发生变化后触发
    //post_universe_changed(universe)
    POST_UNIVERSE_CHANGED ,

    //执行before_trading函数前触发
    //pre_before_trading()
    PRE_BEFORE_TRADING ,
    //该事件会触发策略的before_trading函数
    //before_trading()
    BEFORE_TRADING ,
    //执行before_trading函数后触发
    //post_before_trading()
    POST_BEFORE_TRADING ,

    //执行handle_bar函数前触发
    //pre_bar()
    PRE_BAR ,
    //该事件会触发策略的handle_bar函数
    //bar(bar_dict)
    BAR ,
    //执行handle_bar函数后触发
    //post_bar()
    POST_BAR ,

    //执行handle_tick前触发
    PRE_TICK ,
    //该事件会触发策略的handle_tick函数
    //tick(tick)
    TICK ,
    //执行handle_tick后触发
    POST_TICK ,

    //在scheduler执行前触发
    PRE_SCHEDULED ,
    //在scheduler执行后触发
    POST_SCHEDULED ,

    NOON_BREAK ,
    //执行after_trading函数前触发
    //pre_after_trading()
    PRE_AFTER_TRADING ,
    //该事件会触发策略的after_trading函数
    //after_trading()
    AFTER_TRADING ,
    //执行after_trading函数后触发
    //post_after_trading()
    POST_AFTER_TRADING ,

    //结算前触发该事件
    //pre_settlement()
    PRE_SETTLEMENT ,
    //触发结算事件
    //settlement()
    SETTLEMENT ,
    //结算后触发该事件
    //post_settlement()
    POST_SETTLEMENT ,

    //创建订单
    //order_pending_new(account, order)
    ORDER_PENDING_NEW ,
    //创建订单成功
    //order_creation_pass(account, order)
    ORDER_CREATION_PASS ,
    //创建订单失败
    //order_creation_reject(account, order)
    ORDER_CREATION_REJECT ,
    //创建撤单
    //order_pending_cancel(account, order)
    ORDER_PENDING_CANCEL ,
    //撤销订单成功
    //order_cancellation_pass(account, order)
    ORDER_CANCELLATION_PASS ,
    //撤销订单失败
    //order_cancellation_reject(account, order)
    ORDER_CANCELLATION_REJECT ,
    //订单状态更新
    //order_unsolicited_update(account, order)
    ORDER_UNSOLICITED_UPDATE ,


        //XTP ORDER EVENT
    XORDER_SUBMIT ,

    XORDER_SUBMIT_SUCCESS ,

    XORDER_SUBMIT_FAILURE ,

    XORDER_CANCELED_SUBMIT ,

    XORDER_CANCELED_SUBMIT_SUCCESS ,

    XORDER_CANCELED_SUBMIT_FAILURE ,

    XORDER_CANCELED_ERROR ,

    XORDER_INIT ,

    XORDER_ALL_TRADED ,

    XORDER_PARTLY_TRADED ,

    XORDER_PARTLY_CANCELED ,

    XORDER_NOTTRADE ,

    XORDER_CANCELED ,

    XORDER_REJECTED ,

    XORDER_OUTDATED ,

    XORDER_UNSOLICITED_UPDATE ,

    XTP_ERROR ,

    XTP_ORDER_CANCEL_ERROR ,


    //成交
    //trade(accout, trade, order)
    TRADE ,

    ON_LINE_PROFILER_RESULT ,
};

class Event
{
    public:
    enum EVENT event_type;
    boost::python::dict __dict;
//    PyDict_Type dict;

};

class EventBus{
    public:
    std::map<EVENT, std::vector<>> listeners;
    void add_listener(EVENT event, PyMethodObject listener);

};

#endif