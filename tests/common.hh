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

#ifndef IROBOT_CREATE_TESTS_COMMON_HH
# define IROBOT_CREATE_TESTS_COMMON_HH
# include "irobot-create.hh"
# include <sstream>

# include "config.h"

static const int TEST_FAILED = 10;
static const int TEST_SUCCEED = 0;

int run_test (iRobot::Create&, std::stringstream&);

# define GENERATE_TEST()                                \
  int                                                   \
  main (int argc, char** argv)                          \
  {                                                     \
    if (argc == 2                                       \
        && std::string (argv[1]) == "--version")        \
      {                                                 \
        std::cout << PACKAGE_STRING << std::endl;       \
        return 0;                                       \
      }                                                 \
                                                        \
    std::stringstream stream;                           \
    int status = 0;                                     \
    try                                                 \
      {                                                 \
        iRobot::Create robot (stream);                  \
        status = run_test (robot, stream);              \
      }                                                 \
    catch (std::runtime_error& e)                       \
      {                                                 \
        std::cerr << e.what () << std::endl;            \
        return 1;                                       \
      }                                                 \
    catch (...)                                         \
      {                                                 \
        std::cerr << "Unexpected error" << std::endl;   \
        return 2;                                       \
      }                                                 \
    std::cout << stream.str ();                         \
    return status;                                      \
  }

#define CHECK_FAILURE(EXCEPTION, CMD)           \
  {                                             \
    bool failed = true;                         \
    try                                         \
      {                                         \
        CMD;                                    \
      }                                         \
    catch (EXCEPTION&)                          \
      {                                         \
        failed = false;                         \
      }                                         \
    catch (...)                                 \
      {}                                        \
    if (failed)                                 \
      return TEST_FAILED;                       \
  }

#define CHECK_SENSOR_CHAR(PACKET, DATA, CONDITION)      \
  robot.sendSensorsCommand (PACKET);                    \
  stream.seekg (stream.tellp ());                       \
  stream.put (DATA);                                    \
  if (CONDITION)                                        \
    return TEST_FAILED

#define CHECK_SENSOR_UCHAR(PACKET, DATA, CONDITION)      \
  CHECK_SENSOR_CHAR (PACKET, DATA, CONDITION)

#endif //! IROBOT_CREATE_TESTS_COMMON_HH
