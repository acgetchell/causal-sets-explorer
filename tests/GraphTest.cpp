//
// Created by Adam Getchell on 2017-12-03.
//
#include <catch2/catch.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/small_world_generator.hpp>
#include <boost/random/linear_congruential.hpp>

using Graph = boost::adjacency_list<>;
using SWGen = boost::small_world_iterator<boost::minstd_rand, Graph>;

SCENARIO("Graph operations",    "[graph]")
{
  GIVEN("A random number generator")  // Arrange
  {
    boost::minstd_rand generator;

    WHEN("A graph is generated")  // Act
    {
      auto graph = Graph(SWGen(generator, 100, 6, 0.03), SWGen(), 100);

      THEN("The graph is directed")  // Assert
      {
        REQUIRE(boost::is_directed(graph));
      }
    }
  }
}
