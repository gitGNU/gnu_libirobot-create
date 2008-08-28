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

/**
 * \file doc.hh
 *
 * \brief Main documentation header.
 */

/**

   \mainpage

   <b>Important: this library is not supported by iRobot.</b>

   \section intro Introduction

   This library allows to control easily the iRobot Create robot.  It
   implements the <a
   href="http://www.irobot.com/sp.cfm?pageid=294">Open Interface
   version 2</a>.

   Using this library also ensures that the commands sent to the robot will be
   valid (if an uncompleted command is sent, the robot will remain in a
   "waiting" state). It also prevents you from sending invalid and malformed
   commands (all arguments are checked). Basically, if a command is
   successfully sent (no exception has been thrown), you can be sure that the
   command is valid and will be correctly executed.

   The library also provides a set of types to avoid using "magic constants" in
   your code and make it more readable.


   \section tutorial Tutorial

   iRobot Create uses a specific protocol which is implemented by this library.
   It is called Open Interface (OI) version 2. When instantiating the robot
   class (iRobot::Create) you have to indicate which stream is used to
   communicate with the robot.

   Typically you probably want to use a serial port device for the
   communication such as:

   <ul>
   <li><code>/dev/ttySX</code> (where X is the serial port number),
   <li><code>/dev/rfcommX</code> (where X is the serial-over-bluetooth port number).
   </ul>

   The last solution requires the Bluetooth adapter module (BAM).


   To communicate with the robot, you <strong>need</strong> the serial
   port support. To enable this, you have to use the <a
   href="http://libserial.sourceforge.net/">libserial library</a>
   (this library has to be installed on your computer).

   Here is a complete example using the LibSerial library:

   \code
#include <SerialStream.h>
#include <irobot-create.hh>

int main (int argc, char** argv)
{
  using namespace iRobot;
  using namespace LibSerial;


  if (argc < 2)
    return 1;
  SerialStream stream (argv[1]);

  try
    {
      Create robot (stream);

      // Swith to full mode.
      robot.sendFullCommand ();

      // Let's stream some sensors.
      Create::sensorPackets_t sensors;
      sensors.push_back (Create::SENSOR_BUMPS_WHEELS_DROPS);
      sensors.push_back (Create::SENSOR_WALL);
      sensors.push_back (Create::SENSOR_BUTTONS);

      robot.sendStreamCommand (sensors);

      // Let's turn!
      int speed = 200;
      int ledColor = Create::LED_COLOR_GREEN;
      robot.sendDriveCommand (speed, Create::DRIVE_INPLACE_CLOCKWISE);
      robot.sendLedCommand (Create::LED_PLAY, 0, 0);

      while (!robot.playButton ())
        {
          if (robot.bumpLeft () || robot.bumpRight ())
            std::cout << "Bump !" << std::endl;
          if (robot.wall ())
            std::cout << "Wall !" << std::endl;
          if (robot.advanceButton ())
            {
              speed = -1 * speed;
              ledColor += 10;
              if (ledColor > 255)
                ledColor = 0;

              robot.sendDriveCommand (speed, Create::DRIVE_INPLACE_CLOCKWISE);
              if (speed < 0)
                robot.sendLedCommand (Create::LED_PLAY,
                                      ledColor,
                                      Create::LED_INTENSITY_FULL);
              else
                robot.sendLedCommand (Create::LED_ADVANCE,
                                      ledColor,
                                      Create::LED_INTENSITY_FULL);
            }

          // You can add more commands here.
          usleep(100 * 1000);
        }

      robot.sendDriveCommand (0, Create::DRIVE_STRAIGHT);
    }
  catch (InvalidArgument& e)
    {
      std::cerr << e.what () << std::endl;
      return 3;
    }
  catch (CommandNotAvailable& e)
    {
      std::cerr << e.what () << std::endl;
      return 4;
    }
}
   \endcode

   The robot will start to turn clockwise, then if you push the advance button,
   it will change its direction. Each time you're pushing the button,
   the LEDs will also change.


   \section other What if I do not want to use LibSerial?

   You can construct the object with any kind of std::iostream, it means that
   it can come from another serial library, it may be a std::stringstream or a
   std::fstream. However, do <strong>not</strong> use a fstream to open a
   serial port device (<a href="#faq">see FAQ</a>).


   Here is a simple example that displays on the standard output the binary
   command used to start the "cover" demo (warning: this will display non-ascii
   characters to your term if you do not redirect the standard output, you may
   want to use a tool like hexdump to see the result).

   \code
   #include <sstream>
   #include <irobot-create.hh>

   int main ()
   {
      using namespace iRobot;

      std::stringstream ss;
      Create robot (ss);
      robot.sendDemoCommand (Create::DEMO_COVER);
      std::cout << ss.str ();
   }
   \endcode


   \section faq Frequently Asked Questions (FAQ)

   \subsection faq1 Why is the program failing when I use serial port communication?

   If you try to use the serial port communication without having the LibSerial
   support, the constructor will fail and throw a LibSerialNotAvailable
   exception. It means that when the configure script has not detected the
   LibSerial library on your computer.  Check your config.log, it should
   contain something like that:

   \verbatim
   configure:XXXXX: checking for main in -lserial
   [...]
   configure:XXXXX: result: yes
   \endverbatim

   If the result is <strong>no</strong>, please specify the header and library
   path in CPPFLAGS and LDFLAGS. For instance, if you are using gcc (which is
   usually the case), it should be something like that:

   \verbatim
   ./configure CPPFLAGS=-I/my/path/to/libserial LDFLAGS=-L/my/path/to/libserial
   \endverbatim


   <em>Note: if you have installed a package to get this library, please ask
   the maintainer of the package for your distribution to enable the LibSerial
   support.</em>


   \subsection faq2 Why does the communication through the serial port not work?

   If you have opened the serial port through a std::fstream, <strong>it will
   not work</strong>. Always use the LibSerial library (or another 3rd party
   serial library). Failing to do so may lead to random errors, wrong values
   for the sensors, etc.

   \subsection faq3 The sensor I'm using is never updated, why?

   If you want an updated value of a sensor, you have to explicitly ask for an update.
   It can either be done with the Create::sendSensorsCommand or the
   Create::sendQueryListCommand command.

   If you are using the sensors frequently, you probably want to use the
   Create::sendStreamCommand that will ask the robot to send the sensor's
   value each 15ms. It is the only way to keep a sensor updated automatically.
   If you are using a connection with poor real-time characteristics (such as a
   wireless network using the BAM for instance), the solution recommended by
   iRobot is to use the stream command.

   \code
   iRobot::Create robot (...);

   robot.wall (); // Always false, no update.
   // [...]
   robot.wall (); // Always false, no update.

   Create::sensorPackets_t sensors;
   sensors.push_back (Create::SENSOR_BUMPS_WHEELS_DROPS);

   robot.sendQueryListCommand (robot);

   robot.wall (); // Updated value.
   robot.wall (); // *NO* update here.
   robot.wall (); // *NO* update here.
   // etc.

   robot.sendStreamCommand (robot);

   robot.wall (); // Updated value.
   robot.wall (); // Updated value.
   robot.wall (); // Updated value.
   // etc.
   \endcode


   \subsection faq4 How to use the Bluetooth adapter module (BAM)?

   To use the BAM with this library, you will need two tools:
   <ul>
   <li>hcitool</li>
   <li>rfcomm</li>
   </ul>

   Both tools are provided by the "bluez" package.

   Install the Bluetooth adapter module and start the robot.
   Then, execute the following command:
   \verbatim
   $ hcitool scan
   \endverbatim

   You should see something that looks like that:
   \verbatim
   Scanning ...
        00:0A:3A:26:49:AF       Element Serial
        [...]
   \endverbatim

   The "Element Serial" is the iRobot Create. Remember the address as it
   will be required for the next step.
   If it fails, check that your kernel supports bluetooth (check your
   distribution's documentation).

   Execute the following command:
   \verbatim
   $ rfcomm connect 1 '00:0A:3A:26:49:AF'
   \endverbatim

   You should then see:
   \verbatim
   Connected /dev/rfcomm1 to 00:0A:3A:26:49:AF on channel 1
   Press CTRL-C for hangup
   \endverbatim

   You are now connected to the robot and you can read the
   <code>/dev/rfcomm1</code> file to communicate with it.

   If the connection fails, wait for a couple of seconds and retry.


   \subsection faq4 How to compile my project with libirobot-create?

   Basically, if the library and the headers are installed in standard
   directories, you only have to link against the library. If you are
   using GCC, you probably want:
   \verbatim
   $ g++ myproject.cc -lirobot-create
   \endverbatim

   If you have not installed the library in a standard directory, you
   have to indicate the header directory when compiling and the
   library directory when linking. With GCC:
   \verbatim
$ g++ myproject.cc -I/my/include/path -L/my/library/path -Wl,-R/my/library/path -lirobot-create
   \endverbatim

   The <code>-Wl,-R/my/library/pat</code> flag adds the library directory
   to the list used to search dynamic libraries at run-time (<code>-L</code>
   is only used at compile-time).

   If you are using  the Autotools, see the next section.

   \subsection faq5 How to integrate this library to my Autotools software?

   A m4 file is provided with the macros required to check for this library.

   Here is a sample configure.ac that check for the library:

   \code
   AC_INIT([test], [0.1])
   AM_INIT_AUTOMAKE

   AC_LANG([C++])
   AC_PROG_CXX

   LIBIROBOT_CREATE_ARG_WITH

   AC_CONFIG_HEADERS([config.h])

   AC_CONFIG_FILES([Makefile])
   AC_OUTPUT
   \endcode

   It also define the boolean LIBIROBOT_CREATE that can be used in Automake
   files.
*/

/*!
  \namespace iRobot

  \brief Main namespace

  The namespace gathers all the classes of this library.
*/
