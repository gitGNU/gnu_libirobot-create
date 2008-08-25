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

  Create::song_t song;

  // Send some valid commands.
  song.push_back (std::make_pair (Create::NOTE_MIN, 0));
  song.push_back (std::make_pair (Create::NOTE_MAX, 0));
  song.push_back (std::make_pair (Create::NOTE_MIN, 255));
  song.push_back (std::make_pair (Create::NOTE_MAX, 255));
  robot.sendSongCommand (Create::SONG_MIN, song);

  // Check velocity song min id - 1.
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendSongCommand (Create::SONG_MIN - 1, song));

  // Check velocity song max id + 1.
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendSongCommand (Create::SONG_MAX + 1, song));

  // Check too long song.
  while (song.size () <= Create::SONG_MAX_SIZE)
    song.push_back (std::make_pair (Create::NOTE_MAX, 0));
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendSongCommand (Create::SONG_MIN, song));
  song.clear ();

  // Check min note - 1.
  song.push_back (std::make_pair (Create::NO_NOTE - 1, 0));
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendSongCommand (Create::SONG_MIN, song));
  song.clear ();

  // Check max note + 1.
  song.push_back (std::make_pair (Create::NOTE_MAX + 1, 0));
  CHECK_FAILURE
    (InvalidArgument,
     robot.sendSongCommand (Create::SONG_MIN, song));

  return TEST_SUCCEED;
}

GENERATE_TEST ()
