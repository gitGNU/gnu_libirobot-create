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

  // Test Mode.
  CHECK_FAILURE
    (CommandNotAvailable,
     robot.sendLowSideDriversCommand (false, false, false));

  // Switch to full mode and test a command.
  robot.sendFullCommand ();
  robot.sendLowSideDriversCommand (false, false, false);

  // Switch to safe mode for the rest of the test.
  robot.sendSafeCommand ();

  robot.sendLowSideDriversCommand (false, false, false);
  robot.sendLowSideDriversCommand (true, true, true);
  return TEST_SUCCEED;
}

GENERATE_TEST ()
