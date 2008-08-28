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
     robot.sendLedCommand (Create::LED_PLAY,
                           Create::LED_COLOR_RED,
                           Create::LED_INTENSITY_OFF));

  // Switch to full mode and test a command.
  robot.sendFullCommand ();
  robot.sendLedCommand (Create::LED_PLAY,
                        Create::LED_COLOR_RED,
                        Create::LED_INTENSITY_OFF);

  // Switch to safe mode for the rest of the test.
  robot.sendSafeCommand ();

  // Send valid commands (some bounds).
  robot.sendLedCommand (Create::LED_NONE,
                        Create::LED_COLOR_RED,
                        Create::LED_INTENSITY_OFF);
  robot.sendLedCommand (Create::LED_PLAY,
                        Create::LED_COLOR_GREEN,
                        Create::LED_INTENSITY_OFF);
  robot.sendLedCommand (Create::LED_ADVANCE,
                        Create::LED_COLOR_GREEN,
                        Create::LED_INTENSITY_FULL);
  robot.sendLedCommand (Create::LED_ALL,
                        Create::LED_COLOR_RED,
                        Create::LED_INTENSITY_FULL);

  // Test invalid command (out of bound).
  Create::Led l = static_cast<Create::Led> (342);

  CHECK_FAILURE
    (InvalidArgument,
     robot.sendLedCommand (l,
                           Create::LED_COLOR_GREEN,
                           Create::LED_INTENSITY_OFF));

  return TEST_SUCCEED;
}

GENERATE_TEST ()
