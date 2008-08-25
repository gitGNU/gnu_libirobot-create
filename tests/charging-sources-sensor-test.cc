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

  CHECK_SENSOR_UCHAR (Create::SENSOR_CHARGING_SOURCES_AVAILABLE, 0,
                      !!robot.homeBaseChargerAvailable ()
                      || !!robot.internalChargerAvailable ());

  CHECK_SENSOR_UCHAR (Create::SENSOR_CHARGING_SOURCES_AVAILABLE, 1,
                      !robot.homeBaseChargerAvailable ()
                      || !!robot.internalChargerAvailable ());

  CHECK_SENSOR_UCHAR (Create::SENSOR_CHARGING_SOURCES_AVAILABLE, 2,
                      !!robot.homeBaseChargerAvailable ()
                      || !robot.internalChargerAvailable ());

  CHECK_SENSOR_UCHAR (Create::SENSOR_CHARGING_SOURCES_AVAILABLE, 3,
                      !robot.homeBaseChargerAvailable ()
                      || !robot.internalChargerAvailable ());

  CHECK_SENSOR_UCHAR (Create::SENSOR_CHARGING_SOURCES_AVAILABLE, 4,
                      !!robot.homeBaseChargerAvailable ()
                      || !!robot.internalChargerAvailable ());

  return TEST_SUCCEED;
}

GENERATE_TEST ()
