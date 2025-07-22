#pragma once
#include "Entity.hpp"
#include "Item/Item.hpp"
#include "Stats.hpp"
#include "cereal/archives/binary.hpp"
#include <cereal/types/memory.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/vector.hpp>

#include <cstdint>
#include <fstream>
#include <memory>
#include <print>
#include <raylib.h>

class Player : public Entity {
  public:
  Player();
  void update() override;
  void move() override;
  void draw() override;
  Stats& get_stats();
  // Texture2D* get_sprite(uint8_t sprite_id) override;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(stats, pos, inventory);
  }

  static void save(const std::string& filepath, const std::shared_ptr<Player> player) {
    std::ofstream file(filepath + "/player.bin", std::ios::binary);
    cereal::BinaryOutputArchive archive(file);
    archive(*player);
  }

  static std::shared_ptr<Player> load(const std::string& filepath) {
    std::ifstream file(filepath + "/player.bin", std::ios::binary);
    std::shared_ptr<Player> player = std::make_shared<Player>();
    if (file.is_open()) {
      cereal::BinaryInputArchive archive(file);
      archive(*player);
    } else {
      std::println("can't open file");
      player->pos = {500, 500};
      player->size = {25, 25};
    }
    return player;
  }

  private:
  Stats stats;
  std::vector<std::shared_ptr<Item>> inventory;
  uint16_t money;
};
