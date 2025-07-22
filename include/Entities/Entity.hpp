#pragma once
#include "Engine/DataStructs.hpp"
#include <cstddef>
#include <memory>
#include <raylib.h>

class Entity {
  public:
  virtual Vec2& get_pos();
  virtual Vec2& get_size();

  virtual bool is_colliding(Rectangle& other) const;
  virtual Texture2D* get_sprite(uint8_t sprite_id);
  virtual void move();

  virtual void update();
  virtual void draw();

  protected:
  Vec2 pos;
  Vec2 size;
  std::unique_ptr<Image> sprite_array_idle[13];
};
