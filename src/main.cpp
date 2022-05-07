/// Copyright (c) 2017, Adam Getchell
/// All rights reserved.

#include <CausalGraph.hpp>

int main(int argc, char** argv)
{
  // Create graph with 100 nodes
  auto g = make_graph(100);

  // Write
  write_graph(g);
}
