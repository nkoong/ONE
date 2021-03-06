/*
 * Copyright (c) 2020 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "luci/IR/Nodes/CircleFloorMod.h"

#include "luci/IR/CircleDialect.h"
#include "luci/IR/CircleNodeVisitor.h"

#include <gtest/gtest.h>

TEST(CircleFloorModTest, constructor)
{
  luci::CircleFloorMod floormod_node;

  ASSERT_EQ(luci::CircleDialect::get(), floormod_node.dialect());
  ASSERT_EQ(luci::CircleOpcode::FLOOR_MOD, floormod_node.opcode());

  ASSERT_EQ(nullptr, floormod_node.x());
  ASSERT_EQ(nullptr, floormod_node.y());
}

TEST(CircleFloorModTest, input_NEG)
{
  luci::CircleFloorMod floormod_node;
  luci::CircleFloorMod node;

  floormod_node.x(&node);
  floormod_node.y(&node);
  ASSERT_NE(nullptr, floormod_node.x());
  ASSERT_NE(nullptr, floormod_node.y());

  floormod_node.x(nullptr);
  floormod_node.y(nullptr);
  ASSERT_EQ(nullptr, floormod_node.x());
  ASSERT_EQ(nullptr, floormod_node.y());
}

TEST(CircleFloorModTest, arity_NEG)
{
  luci::CircleFloorMod floormod_node;

  ASSERT_NO_THROW(floormod_node.arg(1));
  ASSERT_THROW(floormod_node.arg(2), std::out_of_range);
}

TEST(CircleFloorModTest, visit_mutable_NEG)
{
  struct TestVisitor final : public luci::CircleNodeMutableVisitor<void>
  {
  };

  luci::CircleFloorMod floormod_node;

  TestVisitor tv;
  ASSERT_THROW(floormod_node.accept(&tv), std::exception);
}

TEST(CircleFloorModTest, visit_NEG)
{
  struct TestVisitor final : public luci::CircleNodeVisitor<void>
  {
  };

  luci::CircleFloorMod floormod_node;

  TestVisitor tv;
  ASSERT_THROW(floormod_node.accept(&tv), std::exception);
}
