/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <ABI45_0_0React/ABI45_0_0renderer/components/view/TouchEvent.h>
#include <ABI45_0_0React/ABI45_0_0renderer/core/EventEmitter.h>
#include <ABI45_0_0React/ABI45_0_0renderer/core/LayoutMetrics.h>
#include <ABI45_0_0React/ABI45_0_0renderer/core/ABI45_0_0ReactPrimitives.h>
#include <ABI45_0_0React/ABI45_0_0renderer/debug/DebugStringConvertible.h>

namespace ABI45_0_0facebook {
namespace ABI45_0_0React {

class TouchEventEmitter;

using SharedTouchEventEmitter = std::shared_ptr<TouchEventEmitter const>;

class TouchEventEmitter : public EventEmitter {
 public:
  using EventEmitter::EventEmitter;

  void onTouchStart(TouchEvent const &event) const;
  void onTouchMove(TouchEvent const &event) const;
  void onTouchEnd(TouchEvent const &event) const;
  void onTouchCancel(TouchEvent const &event) const;

 private:
  void dispatchTouchEvent(
      std::string const &type,
      TouchEvent const &event,
      EventPriority priority,
      RawEvent::Category category) const;
};

} // namespace ABI45_0_0React
} // namespace ABI45_0_0facebook
