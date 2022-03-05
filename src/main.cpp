/// Copyright (c) 2017, Adam Getchell
/// All rights reserved.

#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/small_world_generator.hpp>
#include <boost/random/linear_congruential.hpp>
#include <boost/graph/graphviz.hpp>


using Graph = boost::adjacency_list<>;
using SWGen = boost::small_world_iterator<boost::minstd_rand, Graph>;

auto make_graph(int size) {
  boost::minstd_rand gen;
  Graph g{SWGen(gen, size, 6, 0.03), SWGen(), static_cast<boost::adjacency_list<>::vertices_size_type>(size)};
  return g;
}

TEST_CASE("[make_graph] testing make_graph") {
  auto result = make_graph(100);
  CHECK(boost::is_directed(result));
  CHECK(boost::num_vertices(result) == 100);
}

void write_graph(Graph graph) {
  write_graphviz(std::cout, graph);
}

int main(int argc, char** argv)
{
  // Doctest integration
  doctest::Context context;
  context.setOption("abort-after", 5); // default - stop after 5 failed asserts
  context.applyCommandLine(argc, argv); // apply command line argc / argv
  context.setOption("no-breaks", true); // override - don't break in the debugger
  int result = context.run(); // run test cases unless with --no-run
  if (context.shouldExit()) return result;

  // Create graph with 100 nodes
  auto g = make_graph(100);

  // Write
  write_graph(g);
  return result;
}
