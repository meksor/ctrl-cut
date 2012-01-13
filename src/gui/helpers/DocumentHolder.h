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

#ifndef DOCUMENTHOLDER_H_
#define DOCUMENTHOLDER_H_

#include <QList>
#include "CutItem.h"
#include "EngraveItem.h"

class Document;
class DocumentHolder {
public:
  QList<CutItem* > cutItems;
  QList<EngraveItem* > engraveItems;
  Document* doc;

  DocumentHolder();
  DocumentHolder(const DocumentHolder& holder);
  void add(CutItem& cutItem);
  void remove(CutItem& cutItem);
  void add(EngraveItem& engraveItem);
  void remove(EngraveItem& engraveItem);
};

#endif /* DOCUMENTHOLDER_H_ */