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

  Create::opcodes_t script;

  // Send some valid commands.
  script.push_back (Create::OPCODE_START);
  script.push_back (Create::OPCODE_WAIT_EVENT);
  robot.sendScriptCommand (script);

  // Check too long script.
  while (script.size () <= Create::SCRIPT_MAX_SIZE)
    script.push_back (Create::OPCODE_START);
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendScriptCommand (script));
  script.clear ();

  // Check min opcode - 1.
  Create::Opcode min = static_cast<Create::Opcode> (Create::OPCODE_START - 1);
  script.push_back (min);
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendScriptCommand (script));
  script.clear ();

  // Check max opcode + 1
  Create::Opcode max = static_cast<Create::Opcode>
    (Create::OPCODE_WAIT_EVENT + 1);
  script.push_back (max);
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendScriptCommand (script));

  return TEST_SUCCEED;
}

GENERATE_TEST ()
