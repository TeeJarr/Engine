#pragma once
#include "raylib.h"

struct Vec2 {
  float x, y;

  template <class Archive>
  void serialize(Archive& archive) {
    archive(x, y);
  }
};

struct Rect {
  float x, y, width, height;
  template <class Archive>
  void serialize(Archive& archive) {
    archive(x, y, width, height);
  }
};
