//
// Copyright ©2017 Adam Getchell on 2017-03-10.
//
#include "gmock/gmock.h"
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/small_world_generator.hpp>
#include <boost/random/linear_congruential.hpp>

using Graph = boost::adjacency_list<>;
using SWGen = boost::small_world_iterator<boost::minstd_rand, Graph>;

class GraphTest : public ::testing::Test
{
 public:
  GraphTest()
  {
    boost::minstd_rand generator;
    graph_ = Graph(SWGen(generator, 100, 6, 0.03), SWGen(), 100);
  }

  Graph graph_;
};

TEST_F(GraphTest, IsDirected)
{
  ASSERT_TRUE(boost::is_directed(graph_)) << "Graph not directed.";
}
