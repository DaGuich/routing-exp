#include "astar.hxx"
#include "graph.hxx"
#include <iostream>
#include <memory>

const unsigned int ROWS = 10;
const unsigned int COLS = 10;

int main(int argc, char *argv[])
{
    auto make_id = [](long long row, long long col) constexpr->long long
    {
        return row * COLS + col;
    };

    Graph g;
    for (auto r = 0; r < ROWS; ++r)
    {
        float row = static_cast<float>(r);
        for (auto c = 0; c < COLS; ++c)
        {
            float col = static_cast<float>(c);
            long long id = make_id(r, c);
            g.add_point(Point(id, row, col));
        }
    }

    for (auto r = 0; r < ROWS; ++r)
    {
        for (auto c = 0; c < COLS; ++c)
        {
            long long id = make_id(r, c);

            if ((r - 1) >= 0)
            {
                g.add_neighbour(id, make_id(r - 1, c));
            }

            if ((r + 1) < ROWS)
            {
                g.add_neighbour(id, make_id(r + 1, c));
            }

            if ((c - 1) >= 0)
            {
                g.add_neighbour(id, make_id(r, c - 1));
            }

            if ((c + 1) < COLS)
            {
                g.add_neighbour(id, make_id(r, c + 1));
            }
        }
    }

    std::cout << g.m_points.size() << " * "
              << (sizeof(Point)) << " = "
              << (g.m_points.size() * sizeof(Point)) / 1024 << " R "
              << (g.m_points.size() * sizeof(Point)) % 1024 << std::endl;
    return 0;
}