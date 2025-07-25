#pragma once
#include "../Entity.hpp"
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
  float get_move_speed();
  std::vector<std::shared_ptr<Item>> get_inventory();
  std::unique_ptr<std::array<Texture2D, 13>>& get_sprite(uint8_t sprite_id) override;

  template <class Archive>
  void serialize(Archive& ar);
  void save_serial(const std::string& filepath);
  void load(const std::string& filepath);

  private:
  Stats stats;
  std::vector<std::shared_ptr<Item>> inventory;
  uint16_t money = 0;
  int last_key_x = 0;
  int last_key_y = 0;
  float move_speed;
  int base_move_speed = 250;
};

namespace cereal {
  // template <class Archive>
  // void serialize(Archive& ar, Game& game) {
  //   ar(game.player, game.opts, game.entities);
  // }

  // template <class Archive>
  // void serialize(Archive& ar, Rectangle& rect) {
  //   ar(rect.x, rect.y, rect.width, rect.height);
  // }
  //
  // template <class Archive>
  // void serialize(Archive& ar, Vector2& vec) {
  //   ar(vec.x, vec.y);
  // }
  //
  // template <class Archive>
  // void serialize(Archive& ar, Player& player) {
  //   ar(player.get_pos(), player.get_stats(), player.get_inventory());
  // }

  // template <class Archive>
  // void serialize(Archive& ar, Opts& opts) {
  //   ar(opts.screen, opts.fps, opts.text_speed, opts.difficulty);
  // }
} // namespace cereal
