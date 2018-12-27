#pragma once

#include "graph.hxx"
#include <functional>
#include <vector>

auto cmp_open_list = [](const std::pair<float, long long> &lhs, const std::pair<float, long long> &rhs) -> bool {
    return lhs.first < rhs.first;
};

struct AStar
{
    Graph *m_graph;
    std::vector<std::pair<float, long long>> open_list;

    AStar(Graph *m_graph);
};

AStar::AStar(Graph *graph)
{
    this->m_graph = graph;
}