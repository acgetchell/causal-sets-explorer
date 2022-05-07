/// Copyright (c) 2017, Adam Getchell
/// All rights reserved.

#include <CausalGraph.hpp>

int main()
{
  fmt::print("Making graph...\n");
  // Create graph with 100 nodes
  auto g = make_graph(100);

  // Write
  fmt::print("Writing graph...\n");
  write_graph(g);
}
