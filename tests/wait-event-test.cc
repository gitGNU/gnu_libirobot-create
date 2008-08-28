// Copyright (C) 2008 by Thomas Moulard, the University of Southern California
// (USC), and iLab at USC.
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

  // Send valid commands.
  robot.sendWaitEventCommand (Create::EVENT_WHEEL_DROP);
  robot.sendWaitEventCommand (Create::EVENT_OI_MODE_PASSIVE);

  robot.sendWaitEventCommand (Create::EVENT_WHEEL_DROP,
                              Create::EVENT_NOT_OCCURRING);
  robot.sendWaitEventCommand (Create::EVENT_OI_MODE_PASSIVE,
                              Create::EVENT_NOT_OCCURRING);

  // Check event minimum - 1.
  Create::Event minE =
    static_cast<Create::Event> (Create::EVENT_WHEEL_DROP - 1);
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendWaitEventCommand (minE));

  // Check event maximum + 1.
  Create::Event maxE =
    static_cast<Create::Event> (Create::EVENT_OI_MODE_PASSIVE + 1);
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendWaitEventCommand (maxE));

  // Check event occurring minimum - 1.
  Create::EventState minO =
    static_cast<Create::EventState> (Create::EVENT_OCCURRING - 1);

  CHECK_FAILURE
    (InvalidArgument,
     robot.sendWaitEventCommand (Create::EVENT_WHEEL_DROP, minO));

  // Check event occurring maximum + 1.
  Create::EventState maxO =
    static_cast<Create::EventState> (Create::EVENT_NOT_OCCURRING + 1);

  CHECK_FAILURE
    (InvalidArgument,
     robot.sendWaitEventCommand (Create::EVENT_WHEEL_DROP, maxO));

  return TEST_SUCCEED;
}

GENERATE_TEST ()
