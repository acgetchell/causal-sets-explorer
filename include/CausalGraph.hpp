#pragma once

#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/small_world_generator.hpp>
#include <boost/random/linear_congruential.hpp>

using Graph = boost::adjacency_list<>;
using SWGen = boost::small_world_iterator<boost::minstd_rand, Graph>;

auto make_graph(unsigned size)
{
  boost::minstd_rand gen;
  Graph              g{SWGen(gen, size, 6, 0.03), SWGen(),
          static_cast<boost::adjacency_list<>::vertices_size_type>(size)};
  return g;
}

TEST_CASE("[make_graph] Testing make_graph")
{
  auto result = make_graph(100);
  CHECK(boost::is_directed(result));
  CHECK(boost::num_vertices(result) == 100);
}

void write_graph(Graph graph) { write_graphviz(std::cout, graph); }

SCENARIO("Making a graph")
{
  GIVEN("A graph")
  {
    auto test = make_graph(100);
    REQUIRE(boost::num_vertices(test) == 100);
    REQUIRE(boost::is_directed(test));

    WHEN("The graph is printed") { write_graph(test); }
  }
}