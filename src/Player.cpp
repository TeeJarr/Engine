#include "Entities/Characters/Player.hpp"
#include "raylib.h"
#include <array>
#include <memory>
#include <print>

Player::Player() {
  get_pos() = {500, 500};
  get_size() = {25, 25};
}

Stats& Player::get_stats() { return stats; }

void Player::move() {
  int key = GetKeyPressed();
  if (key == KEY_UP || key == KEY_DOWN) {
    last_key_y = key;
  }
  if (key == KEY_LEFT || key == KEY_RIGHT) {
    last_key_x = key;
  }
  switch (last_key_y) {
    case KEY_UP:
      if (IsKeyDown(KEY_UP)) {
        get_pos().y -= get_move_speed();
      }
      break;
    case KEY_DOWN:
      if (IsKeyDown(KEY_DOWN)) {
        get_pos().y += get_move_speed();
      }
      break;
  }
  switch (last_key_x) {
    case KEY_LEFT:
      if (IsKeyDown(KEY_LEFT)) {
        get_pos().x -= get_move_speed();
      }
      break;
    case KEY_RIGHT:
      if (IsKeyDown(KEY_RIGHT)) {
        get_pos().x += get_move_speed();
      }
      break;
  }
}

float Player::get_move_speed() { return base_move_speed * GetFrameTime(); }

void Player::draw() {
  DrawRectangle(get_pos().x, get_pos().y, get_size().x, get_size().y, RED);
  DrawRectangleLinesEx({get_size().x, get_size().y, get_size().y}, 2, WHITE);
}

void Player::update() { move(); }

// template <class Archive>
// void Player::serialize(Archive& ar) {
//   ar(stats, get_pos().x, get_pos().y, inventory);
// }

std::unique_ptr<std::array<Texture2D, 13>>& Player::get_sprite(uint8_t num) { return sprite_array_idle; }
