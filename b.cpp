//
// Created by will on 5/24/18.
//

#include <boost/python.hpp>
#include "library.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(event)
    {
        class_<EventBus>("Eventbus")
                .def("add_liteners", &EventBus::add_listener);
    }
