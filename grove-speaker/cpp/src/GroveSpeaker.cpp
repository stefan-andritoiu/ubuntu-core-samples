/*
* Author: Flavian Manea <flavian.manea@rinftech.com>
* Copyright (c) 2017 Intel Corporation.
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
* LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
* OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
* WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <unistd.h>
#include <iostream>
#include <signal.h>
#include "grovespeaker.hpp"

using namespace std;

#define DEFAULT_IOPIN 20
static int iopin;

int main(int argc, char** argv)
{
	if (argc < 2) {
        printf("Provide an int arg if you want to use other pin than %d\n", DEFAULT_IOPIN);
        iopin = DEFAULT_IOPIN;
    } else {
        iopin = strtol(argv[1], NULL, 10);
    }
//! [Interesting]
  // Instantiate a Grove Speaker on digital pin 20
  upm::GroveSpeaker* speaker = new upm::GroveSpeaker(iopin);

  // Play all 7 of the lowest notes
  speaker->playAll();

  // Play a medium C-sharp
  speaker->playSound('c', true, "med");

//! [Interesting]

  cout << "Exiting" << endl;

  delete speaker;
  return 0;
}
