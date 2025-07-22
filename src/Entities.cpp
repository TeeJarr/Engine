#include "Entities/Entity.hpp"
#include "raylib.h"
#include <cstdint>

Vec2& Entity::get_pos() { return pos; }
Vec2& Entity::get_size() { return size; }
bool Entity::is_colliding(Rectangle& other) const { return CheckCollisionRecs({pos.x, pos.y, size.x, size.y}, other); }

void Entity::draw() {}
void Entity::update() {}
void Entity::move() {}

Texture2D* Entity::get_sprite(uint8_t num) {}
