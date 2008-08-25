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

  CHECK_SENSOR_UCHAR (Create::SENSOR_SONG_NUMBER, 0,
                      robot.songNumber () != 0);

  CHECK_SENSOR_UCHAR (Create::SENSOR_SONG_NUMBER, 7,
                      robot.songNumber () != 7);

  CHECK_SENSOR_UCHAR (Create::SENSOR_SONG_NUMBER, 15,
                      robot.songNumber () != 15);

  CHECK_SENSOR_UCHAR (Create::SENSOR_SONG_PLAYING, 1,
                      !!robot.songPlaying ());

  CHECK_SENSOR_UCHAR (Create::SENSOR_SONG_PLAYING, 0,
                      !robot.songPlaying ());

  return TEST_SUCCEED;
}

GENERATE_TEST ()
