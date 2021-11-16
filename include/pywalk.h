#ifndef PYWALK_H
#define PYWALK_H

#include <boost/python.hpp>
#include "walk.h"
#include "stat.h"

BOOST_PYTHON_FUNCTION_OVERLOADS(runWalk_overloads, runWalk, 0, 3)
BOOST_PYTHON_FUNCTION_OVERLOADS(step_overloads, step, 1, 2)
BOOST_PYTHON_FUNCTION_OVERLOADS(arrival_overloads, getArrival, 0, 3)
BOOST_PYTHON_FUNCTION_OVERLOADS(arrivalstat_overloads, getArrivalList, 1, 4)

BOOST_PYTHON_MODULE(pywalk)
{
    namespace bp = boost::python;
    using namespace bp;
    def("run_walk", runWalk, runWalk_overloads(bp::args("n_steps", "alpha", "previous")));
    def("step", step, step_overloads(bp::args("x", "alpha")));
    def("get_arrival", getArrival, arrival_overloads(bp::args("n_steps", "alpha", "previous")));
    def("get_arrival_list", getArrivalList, arrivalstat_overloads(bp::args("n_stats", "n_steps", "alpha", "previous")));
}

#endif