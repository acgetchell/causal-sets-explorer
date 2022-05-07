#pragma once

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/small_world_generator.hpp>
#include <boost/random/linear_congruential.hpp>

using Graph = boost::adjacency_list<>;
using SWGen = boost::small_world_iterator<boost::minstd_rand, Graph>;

auto make_graph(unsigned size)
{
  boost::minstd_rand gen;
  Graph              graph{SWGen(gen, size, 6, 0.03), SWGen(),
              static_cast<boost::adjacency_list<>::vertices_size_type>(size)};
  return graph;
}

void write_graph(Graph const& graph) { write_graphviz(std::cout, graph); }
