#ifndef WALK_H
#define WALK_H

#include <random>
#include <cmath>
#include <pcg_random.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/python.hpp>

uint32_t step(uint32_t x, float alpha = 2.0);
boost::python::list runWalk(uint16_t n_steps = 10000, float alpha = 2., uint32_t previous = 100);

/*templates*/
template <typename T>
std::vector<T> runWalkNative(uint16_t n_steps = 10000, float alpha = 2., T previous = 100)
{
    auto warmup = 1000;
    T previous_step = previous;
    for (int i = 0; i < warmup; i++)
        previous_step = step(previous_step, alpha);

    std::vector<T> walk;
    walk.reserve(n_steps);
    walk.push_back(previous_step);
    for (int i = 1; i < n_steps; i++)
    {
        previous_step = step(previous_step, alpha);
        walk.push_back(previous_step);
    }
    return walk;
}

#endif