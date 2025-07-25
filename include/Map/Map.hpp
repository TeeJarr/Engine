#pragma once

#include <cstddef>
#include <vector>
class Map {
  public:
  virtual void update();
  virtual void draw();

  private:
  Map();
  std::vector<int> tile_map;
  size_t width;
  size_t height;
};
