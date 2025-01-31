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

#include "sdkconfig.h"
#if CONFIG_TINYUSB_HID_ENABLED
#include "USB.h"
#include "USBMSC.h"
#include "SD.h"

class SDBridge32
{
private:
    USBMSC msc;
    static int32_t onWrite(uint32_t lba, uint32_t offset, uint8_t *buffer, uint32_t bufsize)
    {
        SD.writeRAW((uint8_t *)buffer, lba);
        return bufsize;
    }

    static int32_t onRead(uint32_t lba, uint32_t offset, void *buffer, uint32_t bufsize)
    {
        SD.readRAW((uint8_t *)buffer, lba);
        return bufsize;
    }

public:
    SDBridge32();
    ~SDBridge32();
    void begin(const char *vendor_id, const char *product_id, const char *product_revision);
    void end();
};
#endif
