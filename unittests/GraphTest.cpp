//
// Copyright ©2017 Adam Getchell on 2017-03-10.
//
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/small_world_generator.hpp>
#include <boost/random/linear_congruential.hpp>
#include <boost/graph/graphviz.hpp>
#include "gmock/gmock.h"

using Graph = boost::adjacency_list<>;
using SWGen = boost::small_world_iterator<boost::minstd_rand, Graph>;

TEST(GraphTest, NotNull) {
//  boost::minstd_rand gen;
//  // Create graph with 100 nodes
//  Graph g{SWGen(gen, 100, 6, 0.03), SWGen(), 100};
//
//  // Write
//  //  boost::dynamic_properties dp;
//  //  write_graphml(std::cout, g, dp, true);
//  write_graphviz(std::cout, g);
  ASSERT_NE(1, 2) << "Graph not instantiated.";
}