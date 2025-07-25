#include "Entities/Entity.hpp"
#include "raylib.h"
#include <cstdint>
#include <memory>

Vector2& Entity::get_pos() { return pos; }
Vector2& Entity::get_size() { return size; }
bool Entity::is_colliding(Rectangle& other) const { return CheckCollisionRecs({pos.x, pos.y, size.x, size.y}, other); }

void Entity::draw() {}
void Entity::update() {}
void Entity::move() {}

std::unique_ptr<std::array<Texture2D, 13>>& Entity::get_sprite(uint8_t num) { return sprite_array_idle; }
