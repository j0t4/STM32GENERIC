#ifndef _STM32_SDFAT_H_INCLUDED
#define _STM32_SDFAT_H_INCLUDED

#include "SdFat.h"
#include "SDIO.h"


class Stm32SdioCard : public BaseBlockDriver  {
  public:
    bool begin() {
        return sdio.begin();
    }
    bool syncBlocks() {
        return true;
    }
    bool readBlock(uint32_t block, uint8_t* dst) {
        return sdio.readBlocks(block, dst, 1);
    };
    bool writeBlock(uint32_t block, const uint8_t* src) {
        return sdio.writeBlocks(block, src, 1);
    };
    bool readBlocks(uint32_t block, uint8_t* dst, size_t nb) {
        return sdio.readBlocks(block, dst, nb);
    };
    bool writeBlocks(uint32_t block, const uint8_t* src, size_t nb) {
        return sdio.writeBlocks(block, src, nb);
    };
  private:
    SDIOClass sdio;
};
class STM32SdFatSdio : public SdFileSystem<Stm32SdioCard> {
 public:
  bool begin() {
    return m_card.begin() && SdFileSystem::begin();
  }
};

#endif
