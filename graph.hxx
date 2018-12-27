#pragma once

#include "helper.hxx"
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <utility>
#include <vector>

class Point
{
    std::vector<std::shared_ptr<Point>> m_neighbours;

    long long m_id;
    float m_lat, m_lon;

    void sort_neighbours();

  public:
    Point(long long id, float lat, float lon);
    bool operator==(const Point &other);

    long long get_id() const;
    float get_lat() const;
    float get_lon() const;

    void add_neighbour(const std::shared_ptr<Point> &p);
    std::vector<std::shared_ptr<Point>> get_neighbours() const;

    float dist(const Point &other);
};

Point::Point(long long id, float lat, float lon) : m_id(id), m_lat(lat), m_lon(lon) {}

bool Point::operator==(const Point &other)
{
    bool ret_val = true;
    ret_val = ret_val && (this->m_id == other.m_id);
    ret_val = ret_val && (this->m_lat == other.m_lat);
    ret_val = ret_val && (this->m_lon == other.m_lon);
    return ret_val;
}

long long Point::get_id() const
{
    return this->m_id;
}

float Point::get_lat() const
{
    return this->m_lat;
}

float Point::get_lon() const
{
    return this->m_lon;
}

void Point::add_neighbour(const std::shared_ptr<Point> &p)
{
    this->m_neighbours.push_back(p);
}

std::vector<std::shared_ptr<Point>> Point::get_neighbours() const
{
    std::vector<std::shared_ptr<Point>> ret_val(this->m_neighbours);
    return ret_val;
}

float Point::dist(const Point &other)
{
    float a, c;
    float thisLat = deg2rad(this->m_lat);
    float otherLat = deg2rad(other.m_lat);
    float thisLon = deg2rad(this->m_lon);
    float otherLon = deg2rad(other.m_lon);
    float dLat = otherLat - thisLat;
    float dLon = otherLon - thisLon;

    a = 0;
    a += sin(dLat / 2) * sin(dLat / 2);
    a += cos(otherLat) * cos(otherLat) * sin(dLon / 2) * sin(dLon / 2);

    c = 0;
    c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS_M * c;
}

void Point::sort_neighbours()
{
    std::sort(this->m_neighbours.begin(),
              this->m_neighbours.end(),
              [this](const std::shared_ptr<Point> &lhs, const std::shared_ptr<Point> &rhs) {
                  float dist_l = this->dist(*lhs);
                  float dist_r = this->dist(*rhs);

                  if (dist_l != dist_r)
                  {
                      return dist_l < dist_r;
                  }
                  return lhs->m_id < rhs->m_id;
              });
}

struct Graph
{
    std::map<long long, std::shared_ptr<Point>> m_points;

    void add_point(const Point &p);
    void add_neighbour(const long long &lhs, const long long &rhs);
};

void Graph::add_point(const Point &p)
{
    this->m_points[p.get_id()] = std::make_shared<Point>(p);
}

void Graph::add_neighbour(const long long &lhs, const long long &rhs)
{
    auto p1 = this->m_points[lhs];
    auto p2 = this->m_points[rhs];
    p1->add_neighbour(p2);
}