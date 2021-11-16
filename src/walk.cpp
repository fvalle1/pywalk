#include "walk.h"

pcg_extras::seed_seq_from<std::random_device> seed_source;
pcg32 rng(seed_source);

uint32_t step(uint32_t x, float alpha)
{
    // Seed with a real random value, if available

    std::uniform_real_distribution<double> dist(0, alpha * x);
    return std::ceil(0.0001 + dist(rng));
}


boost::python::list runWalk(uint16_t n_steps, float alpha, uint32_t previous)
{
    auto nativeWalk = runWalkNative<uint32_t>(n_steps, alpha, previous);
    boost::python::list walk;
    std::for_each(nativeWalk.begin(), nativeWalk.end(), [&walk](auto&& el){
        walk.append(el);
    });
    nativeWalk.clear();
    return walk;
}