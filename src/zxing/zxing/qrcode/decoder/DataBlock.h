#ifndef ZXING_DATA_BLOCK_H
#define ZXING_DATA_BLOCK_H

/*
 *  DataBlock.h
 *  zxing
 *
 *  Copyright 2010 ZXing authors All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <vector>
#include <QSharedPointer>
#include <zxing/common/Array.h>
#include <zxing/qrcode/Version.h>
#include <zxing/qrcode/ErrorCorrectionLevel.h>

namespace zxing {
namespace qrcode {

class DataBlock  {
private:
  int numDataCodewords_;
  QSharedPointer<std::vector<zxing::byte>> codewords_;

  DataBlock(int numDataCodewords, QSharedPointer<std::vector<zxing::byte>> codewords);

public:
  static std::vector<QSharedPointer<DataBlock> >
  getDataBlocks(QSharedPointer<std::vector<zxing::byte>> rawCodewords, QSharedPointer<Version>version, ErrorCorrectionLevel &ecLevel);

  int getNumDataCodewords();
  QSharedPointer<std::vector<zxing::byte>> getCodewords();
};

}
}

#endif // ZXING_DATA_BLOCK_H
