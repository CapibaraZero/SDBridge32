/*
 * This file is part of the Capibara zero (https://github.com/CapibaraZero/fw).
 * Copyright (c) 2024 Andrea Canale.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#if CONFIG_TINYUSB_HID_ENABLED
#include "SDBridge32.hpp"
#include "USBHID.h"

SDBridge32::SDBridge32() {}

SDBridge32::~SDBridge32() {
    msc.end();
}

void SDBridge32::begin(const char *vendor_id, const char *product_id, const char *product_revision) {
  msc.vendorID(vendor_id);
  msc.productID(product_id);
  msc.productRevision(product_revision);
  msc.onRead(onRead);
  msc.onWrite(onWrite);
  msc.mediaPresent(true);
  msc.begin(SD.numSectors(), SD.sectorSize());
}

void SDBridge32::end() {
    msc.end();
}
#endif