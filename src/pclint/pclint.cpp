/*
 * EpilogCUPS - A laser cutter CUPS driver
 * Copyright (C) 2009-2010 Amir Hassan <amir@viel-zu.org> and Marius Kintel <marius@kintel.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "CImg.h"
#include "Interpreter.h"
#include "2D.h"

using std::string;
using std::cerr;
using std::cout;
using std::endl;

using namespace cimg_library;

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

void printUsage()
{
  fprintf(stderr, "pclint %s\n", TOSTRING(CTRLCUT_VERSION));
  fprintf(stderr,
      "Usage: pclint [options] <PCL file> [<output file>]\n\n");

  fprintf(stderr, "Options:\n");
  fprintf(stderr, "  -i        Enter interactive mode\n");
  fprintf(stderr, "  -c <bbox> Crop to given bounding box\n");
  exit(1);
}

int main(int argc, char *argv[]) {
  bool interactive = false;
  char* ifilename = NULL;
  char* ofilename = NULL;
  BoundingBox* crop = NULL;
  int c;
  opterr = 0;

  while ((c = getopt(argc, argv, "ic:")) != -1)
    switch (c) {
    case 'i':
      interactive = true;
      break;
    case 'c':
      crop = BoundingBox::createFromGeometryString(optarg);
      break;
    case ':':
      printUsage();
      break;
    case '?':
      printUsage();
      break;
    }

  if (optind < argc) {
    ifilename = argv[optind];
  } else {
    printUsage();
  }
  if (++optind < argc) {
    ofilename = argv[optind];
  }

  Interpreter intr(ifilename, crop);
  if(interactive) {
    Debugger::create(intr.plotter);
    Debugger::getInstance()->setInteractive(true);
  }

  intr.render();
  if (ofilename != NULL)
    intr.plotter->getCanvas()->save(ofilename);

  cerr << "bounding box: " << *intr.plotter->getBoundingBox() << endl;
  return 0;
}
