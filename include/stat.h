#ifndef STAT_H
#define STAT_H

#include <iostream>
#include <boost/python.hpp>
#include <omp.h>
#include "walk.h"

namespace bp = boost::python;

uint32_t getArrival(uint16_t n_steps = 10000, float alpha = 2., uint32_t previous = 100);
bp::list getArrivalList(uint32_t n_stats= 1000000, uint16_t n_steps = 10000, float alpha = 2., uint32_t previous = 100);

#endif