#pragma once
#include <memory>
#include <raylib.h>

class Entity {
  public:
  virtual Vector2& get_pos();
  virtual Vector2& get_size();

  virtual bool is_colliding(Rectangle& other) const;
  virtual std::unique_ptr<std::array<Texture2D, 13>>& get_sprite(uint8_t sprite_id);
  virtual void move();

  virtual void update();
  virtual void draw();

  protected:
  Vector2 pos;
  Vector2 size;
  std::unique_ptr<std::array<Texture2D, 13>> sprite_array_idle;
};
