#pragma once

struct Vec2 {
  float x, y;

  template <class Archive>
  void serialize(Archive& archive) {
    archive(x, y);
  }
};
