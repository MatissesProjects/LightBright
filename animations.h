#include "colors.h"

#define animation firework1

int frame = 0;

int animation1[][9][3] = {
  {
    colorgreen, colorblue, colorgreen,
    colorblue, colorgreen, colorblue,
    colorgreen, colorblue, colorgreen
  },
  {
    colorblue, colorgreen, colorblue,
    colorgreen, colorblue, colorgreen,
    colorblue, colorgreen, colorblue
  }
};

int animation2[][9][3] = {
  {
    colorred, colorgreen, colorblue,
    colorgreen, colorred, colorred,
    colorblue, colorred, colorwhite
  },
  {
    colorwhite, colorred, colorblue,
    colorred, colorred, colorgreen,
    colorblue, colorgreen, colorred
  },
};

int animation3[][9][3] = {
  {
    colorred, colorgreen, colorblue,
    colorgreen, colorred, colorred,
    colorblue, colorred, colorwhite
  },
  {
    colorblue, colorgreen, colorred,
    colorred, colorred, colorgreen,
    colorwhite, colorred, colorblue
  },
  {
    colorwhite, colorred, colorblue,
    colorred, colorred, colorgreen,
    colorblue, colorgreen, colorred
  },
  {
    colorblue, colorred, colorwhite,
    colorgreen, colorred, colorred,
    colorblue, colorgreen, colorblue
  },
};

int rwb[][9][3] = {
  {
    colorred, colorred, colorred,
    colorred, colorred, colorred,
    colorred, colorred, colorred
  },
  {
    colorwhite, colorwhite, colorwhite,
    colorwhite, colorwhite, colorwhite,
    colorwhite, colorwhite, colorwhite
  },
  {
    colorblue, colorblue, colorblue,
    colorblue, colorblue, colorblue,
    colorblue, colorblue, colorblue
  }
};

int rwb2[][9][3] = {
  {
    colorred, colorred, colorred,
    colorwhite, colorwhite, colorwhite,
    colorblue, colorblue, colorblue
  },
  {
    colorwhite, colorwhite, colorwhite,
    colorblue, colorblue, colorblue,
    colorred, colorred, colorred
  },
  {
    colorblue, colorblue, colorblue,
    colorred, colorred, colorred,
    colorwhite, colorwhite, colorwhite
  }
};

int rwb3[][9][3] = {
  {
    colorblue, colorblue, colorred,
    colorwhite, colorwhite, colorwhite,
    colorred, colorred, colorred
  },
  {
    colorblue, colorblue, colorwhite,
    colorred, colorred, colorred,
    colorwhite, colorwhite, colorwhite
  },
};

int firework1[][9][3] = {
  {
    coloroff, coloroff, coloroff,
    coloroff, coloroff, coloroff,
    coloroff, coloroff, coloroff
  },
  {
    coloroff, coloroff, coloroff,
    coloroff, coloroff, coloroff,
    coloroff, coloroff, coloroff
  },
  {
    coloroff, coloroff, coloroff,
    coloroff, coloroff, coloroff,
    colorred, coloroff, coloroff
  },
  {
    coloroff, coloroff, coloroff,
    coloroff, colorred, coloroff,
    coloryellow, coloroff, coloroff
  },
  {
    coloroff, coloroff, coloroff,
    coloroff, colorwhite, coloroff,
    coloroff, coloroff, coloroff
  },
  {
    coloroff, colorred, coloroff,
    colorred, coloroff, colorred,
    coloroff, colorred, coloroff
  },
  {
    colorwhite, colorwhite, colorwhite,
    colorwhite, coloroff, colorwhite,
    colorwhite, colorwhite, colorwhite
  },
  {
    colorblue, colorblue, colorblue,
    colorblue, coloroff, colorblue,
    colorblue, colorblue, colorblue
  },
  {
    coloroff, coloroff, coloroff,
    coloroff, coloroff, coloroff,
    coloroff, coloroff, coloroff
  },
  {
    coloroff, coloroff, coloroff,
    coloroff, coloroff, coloroff,
    coloroff, coloroff, coloroff
  },
};

