//
// Created by Adam Getchell on 2017-12-03.
//
#include "catch.hpp"
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/small_world_generator.hpp>
#include <boost/random/linear_congruential.hpp>

using Graph = boost::adjacency_list<>;
using SWGen = boost::small_world_iterator<boost::minstd_rand, Graph>;

SCENARIO("A graph is generated")
{
  GIVEN("A graph with 100 items")
  {
    boost::minstd_rand generator;
    auto graph = Graph(SWGen(generator, 100, 6, 0.03), SWGen(), 100);

    REQUIRE(boost::is_directed(graph));
  }
}
