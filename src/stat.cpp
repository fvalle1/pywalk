#include "stat.h"

uint32_t getArrival(uint16_t n_steps, float alpha, uint32_t previous)
{
    auto walk = runWalkNative<uint32_t>(n_steps, alpha, previous);
    return walk[walk.size() - 1];
}

bp::list getArrivalList(uint32_t n_stats, uint16_t n_steps, float alpha, uint32_t previous)
{

    namespace bp = boost::python;
#pragma omp parallel master
    std::cout << "Running " << omp_get_num_threads() << " threads" << std::endl;
    bp::list arrivals;
#pragma omp parallel for shared(arrivals)
    for (uint32_t s = 0; s < n_stats; s++)
    {
        auto walkerDestination = getArrival(n_steps, alpha, previous);
#pragma omp critical
        {
            arrivals.append(walkerDestination);
        }
    }
    return arrivals;
}