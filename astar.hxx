#pragma once

#include "graph.hxx"
#include <functional>
#include <unordered_set>
#include <vector>

auto cmp_open_list = [](const std::pair<float, long long> &lhs, const std::pair<float, long long> &rhs) -> bool {
    return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second);
};

struct AStar
{
    Graph *m_graph;
    std::vector<std::pair<float, long long>> m_open_list; // f-value | id
    std::unordered_set<long long> m_closed_list;
    std::map<long long, long long> m_previous_nodes;
    std::map<long long, float> m_gs;
    std::map<long long, float> m_hs;

    AStar(Graph *m_graph);
    std::vector<long long> route(long long start, long long end);
};

AStar::AStar(Graph *graph)
{
    this->m_graph = graph;
}

std::vector<long long> AStar::route(long long start, long long end)
{
}