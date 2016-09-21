#include <SindormirSevenSegments.h>

struct sevenSegment {
  Sindormir7segs mi7S;

  sevenSegment() {
    mi7S.commonType(CATODO);
    mi7S.attach(2,3,4,5,6,7,8,9);
  }

  void setDisplay(int val) {
    if( val != -1) {
      mi7S.print(val);
    }
  }
};
