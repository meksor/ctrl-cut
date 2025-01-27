/*
 * Ctrl-Cut - Laser cutter toolchain
 * See LICENSE file
 * Copyright (C) 2011 Amir Hassan <amir@viel-zu.org> and Marius kintel <kintel@kintel.net>
 */

#ifndef DITHERFLOYDSTEINGBERG_H_
#define DITHERFLOYDSTEINGBERG_H_

#include "Dither.hpp"

class DitherFloydSteinberg: public Dither {
public:
  DitherFloydSteinberg(GrayscaleImage& img): Dither(img) {}
  virtual ~DitherFloydSteinberg(){}
  void ditherPixel(const uint32_t x, const uint32_t y, Pixel<uint8_t>& pix, const uint32_t colors = 1);

};

#endif /* DITHERFLOYDSTEINGBERG_H_ */
