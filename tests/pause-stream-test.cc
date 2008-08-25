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

  robot.sendPauseStreamCommand (Create::STREAM_STATE_OFF);
  robot.sendPauseStreamCommand (Create::STREAM_STATE_ON);

  // Check stream state minimum - 1.
  Create::StreamState minS =
    static_cast<Create::StreamState> (Create::STREAM_STATE_OFF - 1);

  CHECK_FAILURE
    (InvalidArgument,
     robot.sendPauseStreamCommand (minS));

  // Create stream state maximum + 1.
  Create::StreamState maxS =
    static_cast<Create::StreamState> (Create::STREAM_STATE_ON + 1);
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendPauseStreamCommand (maxS));

  return TEST_SUCCEED;
}

GENERATE_TEST ()
