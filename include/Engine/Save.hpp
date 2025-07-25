#pragma once
#ifndef ENGINE_SAVE_HPP_
#define ENGINE_SAVE_HPP_

#include "Entities/Characters/Player.hpp"
#include "Game.hpp"
#include "Opts.hpp"
#include <raylib.h>

template <class Archive>
void Player::serialize(Archive& ar) {
  ar(stats, pos, inventory);
}

namespace cereal {
  template <class Archive>
  void serialize(Archive& ar, Game& game) {
    ar(game.player, game.opts, game.entities);
  }

  template <class Archive>
  void serialize(Archive& ar, Rectangle& rect) {
    ar(rect.x, rect.y, rect.width, rect.height);
  }

  template <class Archive>
  void serialize(Archive& ar, Vector2& vec) {
    ar(vec.x, vec.y);
  }

  template <class Archive>
  void serialize(Archive& ar, Opts& opts) {
    ar(opts.screen, opts.fps, opts.text_speed, opts.difficulty);
  }
} // namespace cereal

#endif
