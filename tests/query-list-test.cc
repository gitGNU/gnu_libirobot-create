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

int run_test (iRobot::Create& robot, std::stringstream&)
{
  using namespace iRobot;

  Create::sensorPackets_t sensors;

  // Send some valid commands.
  sensors.push_back (Create::SENSOR_GROUP_0);
  sensors.push_back (Create::SENSOR_REQUESTED_LEFT_VELOCITY);
  robot.sendQueryListCommand (sensors);

  // Check too long sensors.
  while (sensors.size () <= 255)
    sensors.push_back (Create::SENSOR_GROUP_0);
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendQueryListCommand (sensors));
  sensors.clear ();

  // Check min opcode - 1.
  Create::SensorPacket min = static_cast<Create::SensorPacket>
    (Create::SENSOR_GROUP_0 - 1);
  sensors.push_back (min);
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendQueryListCommand (sensors));
  sensors.clear ();

  // Check max opcode + 1
  Create::SensorPacket max = static_cast<Create::SensorPacket>
    (Create::SENSOR_REQUESTED_LEFT_VELOCITY + 1);
  sensors.push_back (max);
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendQueryListCommand (sensors));

  return TEST_SUCCEED;
}

GENERATE_TEST ()
