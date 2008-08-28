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
     robot.sendDriveCommand (Create::VELOCITY_MIN, Create::RADIUS_MIN));

  // Switch to full mode and test a command.
  robot.sendFullCommand ();
  robot.sendDriveCommand (Create::VELOCITY_MIN, Create::RADIUS_MIN);

  // Switch to safe mode for the rest of the test.
  robot.sendSafeCommand ();

  // Send a couple of valid commands (test bounds).
  int vmean = (Create::VELOCITY_MAX - Create::VELOCITY_MIN) / 2;
  int rmean = (Create::RADIUS_MAX - Create::RADIUS_MIN) / 2;
  robot.sendDriveCommand (vmean, rmean);
  robot.sendDriveCommand (Create::VELOCITY_MIN, Create::RADIUS_MIN);
  robot.sendDriveCommand (Create::VELOCITY_MIN, Create::RADIUS_MAX);
  robot.sendDriveCommand (Create::VELOCITY_MAX, Create::RADIUS_MIN);
  robot.sendDriveCommand (Create::VELOCITY_MAX, Create::RADIUS_MAX);

  // Check velocity minimum - 1.
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendDriveCommand (Create::VELOCITY_MIN - 1,
                             Create::RADIUS_MAX / 4));

  // Check velocity maximum + 1.
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendDriveCommand (Create::VELOCITY_MAX + 1,
                             Create::RADIUS_MAX / 4));

  // Check radius minimum - 1.
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendDriveCommand (Create::VELOCITY_MAX / 4,
                             Create::RADIUS_MIN - 1));

  // Check radius maximum + 1.
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendDriveCommand (Create::VELOCITY_MAX / 4,
                             Create::RADIUS_MAX + 1));

  // Test special cases.
  robot.sendDriveCommand (vmean,
                          Create::DRIVE_STRAIGHT);
  robot.sendDriveCommand (Create::VELOCITY_MIN,
                          Create::DRIVE_STRAIGHT);
  robot.sendDriveCommand (Create::VELOCITY_MAX,
                          Create::DRIVE_STRAIGHT);

  robot.sendDriveCommand (vmean,
                          Create::DRIVE_INPLACE_CLOCKWISE);
  robot.sendDriveCommand (Create::VELOCITY_MIN,
                          Create::DRIVE_INPLACE_CLOCKWISE);
  robot.sendDriveCommand (Create::VELOCITY_MAX,
                          Create::DRIVE_INPLACE_CLOCKWISE);

  robot.sendDriveCommand (vmean,
                          Create::DRIVE_INPLACE_COUNTERCLOCKWISE);
  robot.sendDriveCommand (Create::VELOCITY_MIN,
                          Create::DRIVE_INPLACE_COUNTERCLOCKWISE);
  robot.sendDriveCommand (Create::VELOCITY_MAX,
                          Create::DRIVE_INPLACE_COUNTERCLOCKWISE);

  // Test special cases failures.
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendDriveCommand (Create::VELOCITY_MIN - 1,
                             Create::DRIVE_STRAIGHT));

  CHECK_FAILURE
    (InvalidArgument,
     robot.sendDriveCommand (Create::VELOCITY_MAX + 1,
                             Create::DRIVE_STRAIGHT));

  CHECK_FAILURE
    (InvalidArgument,
     robot.sendDriveCommand (Create::VELOCITY_MIN - 1,
                             Create::DRIVE_INPLACE_CLOCKWISE));

  CHECK_FAILURE
    (InvalidArgument,
     robot.sendDriveCommand (Create::VELOCITY_MAX + 1,
                             Create::DRIVE_INPLACE_CLOCKWISE));

  CHECK_FAILURE
    (InvalidArgument,
     robot.sendDriveCommand (Create::VELOCITY_MIN - 1,
                             Create::DRIVE_INPLACE_COUNTERCLOCKWISE));

  CHECK_FAILURE
    (InvalidArgument,
     robot.sendDriveCommand (Create::VELOCITY_MAX + 1,
                             Create::DRIVE_INPLACE_COUNTERCLOCKWISE));

  return TEST_SUCCEED;
}

GENERATE_TEST ()
