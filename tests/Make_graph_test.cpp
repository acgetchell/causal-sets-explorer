//
// Created by Adam Getchell on 5/7/22.
//
#include <doctest/doctest.h>

#include <CausalGraph.hpp>

TEST_CASE("[make_graph] Testing make_graph")
{
  auto result       = make_graph(100);
  auto is_directed  = boost::is_directed(result);
  auto num_vertices = boost::num_vertices(result);
  CHECK(is_directed);
  CHECK(num_vertices == 100);
  // Human verification
  fmt::print("Graph is directed? {}\n", is_directed);
  fmt::print("Graph has {} vertices\n", num_vertices);
}