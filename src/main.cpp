/// Copyright (c) 2017, Adam Getchell
/// All rights reserved.

#include <CausalGraph.hpp>

int main(int argc, char** argv)
{
  // Doctest integration
  doctest::Context context;
  context.setOption("abort-after", 5); // default - stop after 5 failed asserts
  context.applyCommandLine(argc, argv); // apply command line argc / argv
  context.setOption("no-breaks", true); // override - don't break in the debugger
  int result = context.run(); // run test cases unless with --no-run
  if (context.shouldExit()) return result;

  // Create graph with 100 nodes
  auto g = make_graph(100);

  // Write
  write_graph(g);
  return result;
}
