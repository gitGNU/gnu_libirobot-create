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

/*!
 * This test program can be used to test direct communication to iRobot Create
 * through a file (like the rfcomm layer or the serial port).
 * No communication specific operation is done by this example, the file
 * should be ready for communication before launching this binary.
 */

#include <iostream>
#include <fstream>
#include "irobot-create.hh"

int
main (int argc, char** argv)
{
  if (argc != 2)
    {
      std::cout << "Usage: " << argv[0] << " <device>" << std::endl;
      std::cout << "The device argument may be /dev/ttyS0 or /dev/rfcomm0."
                << std::endl;
      return 1;
    }
  std::fstream stream (argv[1]);
  if (!stream.good ())
    {
      std::cerr << "Failed to open ``" << argv[1] << "''." << std::endl;
      return 2;
    }

  std::cout << "Create instance..." << std::endl;
  iRobot::Create robot (stream);

  std::cout << "Send start command..." << std::endl;
  robot.sendStartCommand ();

  std::cout << "Send demo command (1)..." << std::endl;
  robot.sendDemoCommand (iRobot::Create::DEMO_COVER);
  return 0;
}
