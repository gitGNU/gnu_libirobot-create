// Copyright (C) 2008 iLab
//
// This file is part of the iRobot Create library.
//
// libirobot-create is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// libirobot-create is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with libirobot-create.  If not, see <http://www.gnu.org/licenses/>.

#include "common.hh"

int run_test (iRobot::Create robot, std::stringstream& stream)
{
  using namespace iRobot;

  // Cliff left.
  std::cerr << "Cliff left" << std::endl;
  CHECK_SENSOR_UCHAR (Create::SENSOR_CLIFF_LEFT, 0,
                      !!robot.cliffLeft ());
  CHECK_SENSOR_UCHAR (Create::SENSOR_CLIFF_LEFT, 1,
                      !robot.cliffLeft ());
  CHECK_SENSOR_UCHAR (Create::SENSOR_CLIFF_LEFT, 15,
                      !robot.cliffLeft ());

  // Cliff front left.
  std::cerr << "Cliff front left" << std::endl;
  CHECK_SENSOR_UCHAR (Create::SENSOR_CLIFF_FRONT_LEFT, 0,
                      !!robot.cliffFrontLeft ());
  CHECK_SENSOR_UCHAR (Create::SENSOR_CLIFF_FRONT_LEFT, 1,
                      !robot.cliffFrontLeft ());
  CHECK_SENSOR_UCHAR (Create::SENSOR_CLIFF_FRONT_LEFT, 15,
                      !robot.cliffFrontLeft ());

  // Cliff front right.
  std::cerr << "Cliff front right" << std::endl;
  CHECK_SENSOR_UCHAR (Create::SENSOR_CLIFF_FRONT_RIGHT, 0,
                      !!robot.cliffFrontRight ());
  CHECK_SENSOR_UCHAR (Create::SENSOR_CLIFF_FRONT_RIGHT, 1,
                      !robot.cliffFrontRight ());
  CHECK_SENSOR_UCHAR (Create::SENSOR_CLIFF_FRONT_RIGHT, 15,
                      !robot.cliffFrontRight ());

  // Cliff right
  std::cerr << "Cliff right" << std::endl;
  CHECK_SENSOR_UCHAR (Create::SENSOR_CLIFF_RIGHT, 0,
                      !!robot.cliffRight ());
  CHECK_SENSOR_UCHAR (Create::SENSOR_CLIFF_RIGHT, 1,
                      !robot.cliffRight ());
  CHECK_SENSOR_UCHAR (Create::SENSOR_CLIFF_RIGHT, 15,
                      !robot.cliffRight ());

  return TEST_SUCCEED;
}

GENERATE_TEST ()
