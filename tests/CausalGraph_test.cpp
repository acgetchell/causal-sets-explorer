//
// Created by Adam Getchell on 5/6/22.
//
#include <doctest/doctest.h>

#include <CausalGraph.hpp>

TEST_CASE("[make_graph] Testing make_graph")
{
  auto result = make_graph(100);
  CHECK(boost::is_directed(result));
  CHECK(boost::num_vertices(result) == 100);
}

SCENARIO("Writing a graph")
{
  GIVEN("A graph")
  {
    auto test = make_graph(10);
    REQUIRE(boost::num_vertices(test) == 10);
    REQUIRE(boost::is_directed(test));

    WHEN("The graph is printed") { write_graph(test); }
  }
}