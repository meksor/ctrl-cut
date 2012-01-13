/*
 * Ctrl-Cut - A laser cutter CUPS driver
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

#include "DocumentSettings.hpp"
#include "EngraveSettings.hpp"
#include "BitmapSettings.hpp"
#include "PathSettings.hpp"
#include "CutSettings.hpp"
#include "util/Measurement.hpp"

const DocumentSettings::Key<LaserCutter::Driver>  DocumentSettings::DRIVER = "driver";
const DocumentSettings::Key<string> DocumentSettings::USER = "user";
const DocumentSettings::Key<string> DocumentSettings::TITLE = "title";
const DocumentSettings::Key<string> DocumentSettings::TEMP_DIR = "tmpDir";
const DocumentSettings::Key<string> DocumentSettings::DATA_DIR = "dataDir";
const DocumentSettings::Key<string> DocumentSettings::BASENAME = "basename";

const DocumentSettings::Key<uint16_t> DocumentSettings::RESOLUTION = "resolution";
const DocumentSettings::Key<Measurement> DocumentSettings::WIDTH = "width";
const DocumentSettings::Key<Measurement> DocumentSettings::HEIGHT = "height";
const DocumentSettings::Key<bool> DocumentSettings::AUTO_FOCUS = "autoFocus";
const DocumentSettings::Key<uint16_t> DocumentSettings::SCREEN = "screen";

const DocumentSettings::Key<bool> DocumentSettings::ENABLE_RASTER = "enableRaster";
const DocumentSettings::Key<bool> DocumentSettings::ENABLE_VECTOR = "enableVector";
const DocumentSettings::Key<bool> DocumentSettings::LOAD_CUT = "loadCut";
const DocumentSettings::Key<bool> DocumentSettings::LOAD_ENGRAVING = "loadEngraving";

const DocumentSettings::Key<bool> DocumentSettings::DUMP_XML = "dumpXml";

DocumentSettings::DocumentSettings() : Settings() {
  this->put(DRIVER, LaserCutter::UNINITIALIZED);
  this->put(TEMP_DIR, string("tmp"));
  this->put(AUTO_FOCUS, true);
  this->put(RESOLUTION, 600);
  this->put(SCREEN, 8);
  this->put(ENABLE_VECTOR, true);
  this->put(ENABLE_RASTER, false);
  this->put(LOAD_CUT, true);
  this->put(LOAD_ENGRAVING, false);

  this->put(WIDTH, Measurement(21600,PX,600));
  this->put(HEIGHT, Measurement(14400,PX,600));
  this->put(DUMP_XML, false);
  //FIXME dont do empty defaults
  this->put(TITLE, "");
  this->put(USER, "");
  this->put(EngraveSettings::DITHERING, EngraveSettings::DEFAULT_DITHERING);
  this->put(EngraveSettings::DIRECTION, EngraveSettings::TOPDOWN);
  this->put(EngraveSettings::EPOWER, 20);
  this->put(EngraveSettings::ESPEED, 100);
  this->put(EngraveSettings::EPOS, Point());

  this->put(BitmapSettings::BPOS, Point());

  this->put(CutSettings::OPTIMIZE, CutSettings::INNER_OUTER);
  this->put(CutSettings::CSPEED, 33);
  this->put(CutSettings::CPOWER, 80);
  this->put(CutSettings::FREQUENCY, 5000);
  this->put(CutSettings::CPOS, Point());

  this->put(PathSettings::S_SPEED, 33);
  this->put(PathSettings::S_POWER, 80);
  this->put(PathSettings::S_FREQUENCY, 5000);
}