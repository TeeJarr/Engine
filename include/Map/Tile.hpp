#pragma once

#include "raylib.h"
#include <cstdint>

struct Tile {
  Tile();
  uint8_t id;
  uint8_t collision_id;
  Texture2D* texture;
};
