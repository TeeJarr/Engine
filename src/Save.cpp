#include "Engine/Save.hpp"
// Player Saves

void Player::save_serial(const std::string& filepath) {
  std::ofstream file(filepath + "/player.bin", std::ios::binary);
  cereal::BinaryOutputArchive archive(file);
  archive(*this);
}

void Player::load(const std::string& filepath) {
  std::ifstream file(filepath + "/player.bin", std::ios::binary);
  if (file.is_open()) {
    cereal::BinaryInputArchive archive(file);
    archive(*this);
  } else {
    std::println("can't open file");
    this->pos = {500, 500};
    this->size = {25, 25};
  }
}

// Game Save
