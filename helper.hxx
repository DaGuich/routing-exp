#pragma once

#include <cmath>
#include <memory>
#include <set>
#include <utility>
#include "graph.hxx"

constexpr float EARTH_RADIUS_M = 6371000.785;

constexpr auto deg2rad(const float &deg)
{
    return deg * (M_PI / 180);
}

constexpr auto rad2deg(const float &rad)
{
    return (rad * 180) / M_PI;
}
