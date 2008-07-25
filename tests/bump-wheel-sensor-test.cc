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

  // All false.
  CHECK_SENSOR_UCHAR (Create::SENSOR_BUMPS_WHEELS_DROPS, 0,
                      !!robot.wheeldropCaster ()
                      || !!robot.wheeldropLeft ()
                      || !!robot.wheeldropRight ()
                      || !!robot.bumpLeft ()
                      || !!robot.bumpRight ());
  // All true.
  CHECK_SENSOR_UCHAR (Create::SENSOR_BUMPS_WHEELS_DROPS, 31,
                      !robot.wheeldropCaster ()
                      || !robot.wheeldropLeft ()
                      || !robot.wheeldropRight ()
                      || !robot.bumpLeft ()
                      || !robot.bumpRight ());

  // Intermediary value.
  CHECK_SENSOR_UCHAR (Create::SENSOR_BUMPS_WHEELS_DROPS, 21,
                      !robot.wheeldropCaster ()
                      || !!robot.wheeldropLeft ()
                      || !robot.wheeldropRight ()
                      || !!robot.bumpLeft ()
                      || !robot.bumpRight ());

  return TEST_SUCCEED;
}

GENERATE_TEST ()
