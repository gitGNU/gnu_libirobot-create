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

  // Test Mode.
  CHECK_FAILURE
    (CommandNotAvailable,
     robot.sendDriveDirectCommand
     (Create::VELOCITY_MIN, Create::VELOCITY_MIN));

  // Switch to full mode and test a command.
  robot.sendFullCommand ();
  robot.sendDriveDirectCommand (Create::VELOCITY_MIN, Create::VELOCITY_MIN);

  // Switch to safe mode for the rest of the test.
  robot.sendSafeCommand ();

  // Test valid commands (bounds)
  int vmean = (Create::VELOCITY_MAX - Create::VELOCITY_MIN) / 2;
  robot.sendDriveCommand (vmean, vmean);
  robot.sendDriveDirectCommand (Create::VELOCITY_MIN, Create::VELOCITY_MIN);
  robot.sendDriveDirectCommand (Create::VELOCITY_MIN, Create::VELOCITY_MAX);
  robot.sendDriveDirectCommand (Create::VELOCITY_MAX, Create::VELOCITY_MIN);
  robot.sendDriveDirectCommand (Create::VELOCITY_MAX, Create::VELOCITY_MAX);

  // Check velocity minimum - 1.
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendDriveDirectCommand (Create::VELOCITY_MIN - 1,
                                   Create::VELOCITY_MAX / 4));

  // Check velocity maximum + 1.
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendDriveDirectCommand (Create::VELOCITY_MAX + 1,
                             Create::VELOCITY_MAX / 4));

  // Check radius minimum - 1.
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendDriveDirectCommand (Create::VELOCITY_MAX / 4,
                             Create::VELOCITY_MIN - 1));

  // Check radius maximum + 1.
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendDriveDirectCommand (Create::VELOCITY_MAX / 4,
                             Create::VELOCITY_MAX + 1));

  return TEST_SUCCEED;
}

GENERATE_TEST ()
