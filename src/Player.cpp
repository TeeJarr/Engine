#include "Entities/Player.hpp"
#include "cereal/archives/binary.hpp"
#include "raylib.h"
#include <filesystem>
#include <fstream>
#include <memory>
#include <ostream>
#include <print>

Player::Player() {
  get_pos() = {500, 500};
  get_size() = {25, 25};
}

Stats& Player::get_stats() { return stats; }

void Player::move() {
  if (IsKeyDown(KEY_UP)) {
    get_pos().y -= 5;
    std::println("Key Pressed UP - poistion: {}, {}", get_pos().x, get_pos().y);
  } else if (IsKeyDown(KEY_DOWN)) {
    get_pos().y += 5;
    std::println("Key Pressed DOWN - poistion: {}, {}", get_pos().x, get_pos().y);
  }

  if (IsKeyDown(KEY_LEFT)) {
    get_pos().x -= 5;
    std::println("Key Pressed LEFT - poistion: {}, {}", get_pos().x, get_pos().y);
  } else if (IsKeyDown(KEY_RIGHT)) {
    get_pos().x += 5;
    std::println("Key Pressed RIGHT - poistion: {}, {}", get_pos().x, get_pos().y);
  }
}

void Player::draw() { DrawRectangle(get_pos().x, get_pos().y, get_size().x, get_size().y, RED); }

void Player::update() { move(); }

// Texture2D* Player::get_sprite(uint8_t num) override {}
