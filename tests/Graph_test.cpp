//
// Created by Adam Getchell on 5/6/22.
//
#include <doctest/doctest.h>

#include <CausalGraph.hpp>

SCENARIO("Writing a graph")
{
  GIVEN("A graph")
  {
    auto test = make_graph(10);
    REQUIRE(boost::num_vertices(test) == 10);
    REQUIRE(boost::is_directed(test));

    WHEN("The graph is printed")
    {
      write_graph(test);
      THEN("We get output") { fmt::print("Graph printed.\n"); }
    }
  }
}