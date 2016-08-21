#include "colors.h"
#define animation twoByTwo
//arrows
//flag
//binary
//firework

int frame = 0;

int oneByOne[][1][3] = {
  {colorred},
  {colorgreen},
  {colorblue},
  {colorcyan},
  {coloryellow},
  {colorpurple},
  {colorwhite},
  {coloroff}
};

int oneByTwo[][2][3] = {
  {colorred,colorgreen},
  {colorgreen,colorblue},
  {colorblue,colorcyan},
  {colorcyan,coloryellow},
  {coloryellow,colorpurple},
  {colorpurple,colorwhite},
  {colorwhite,coloroff},
  {coloroff,colorred}
};

int twoByTwo_test[][4][3] = {
  {
    colorgreen, colorgreen,
    colorgreen, colorgreen
  },
  {
    colorblue, colorblue,
    colorblue, colorblue
  },
    {
    colorred, colorred,
    colorred, colorred
  }
};

int twoByTwo[][4][3] = {
  {
    colorred, colorgreen,
    coloroff, colorblue
  },
  {
    coloroff, colorred,
    colorblue, colorgreen
  },
    {
    colorblue, coloroff,
    colorgreen, colorred
  },
  {
    colorgreen, colorblue,
    colorred, coloroff
  },
};

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
    colorred, colorgreen, colorblue
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

int flag[][9][3] = {
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

int flagRipple[][9][3] = {
  {
    colorblue, colorblue, colorred,
    brightwhite, colorwhite, colorwhite,
    brightred, colorred, colorred
  },
  {
    colorblue, colorblue, colorred,
    colorwhite, brightwhite, colorwhite,
    colorred, brightred, colorred
  },
  {
    colorblue, colorblue, colorred,
    colorwhite, colorwhite, brightwhite,
    colorred, colorred, brightred
  },
  {
    colorblue, colorblue, colorwhite,
    brightred, colorred, colorred,
    brightwhite, colorwhite, colorwhite
  },
  {
    colorblue, colorblue, colorwhite,
    colorred, brightred, colorred,
    colorwhite, brightwhite, colorwhite
  },
  {
    colorblue, colorblue, brightwhite,
    colorred, colorred, brightred,
    colorwhite, colorwhite, brightwhite
  },
};

int firework[][9][3] = {
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

int arrows[][9][3] = {
  {
    colorblue, colorblue, colorblue,
    coloroff, colorblue, colorblue,
    colorblue, coloroff, colorblue
  },
  {
    colorgreen, coloroff, colorgreen,
    coloroff, colorgreen, colorgreen,
    colorgreen, colorgreen, colorgreen
  },
  {
    colorred, coloroff, colorred,
    colorred, colorred, coloroff,
    colorred, colorred, colorred
  },
  {
    coloryellow, coloryellow, coloryellow,
    coloryellow, coloryellow, coloroff,
    coloryellow, coloroff, coloryellow
  }
};

int binary[][9][3] = {
  {
    coloroff, coloroff, coloroff,
    coloroff, coloroff, coloroff,
    coloroff, coloroff, coloroff
  },
  {
    coloroff, colorred, coloroff,
    coloroff, coloroff, colorblue,
    colorwhite, coloroff, coloroff
  },
  {
    coloroff, coloroff, colorred,
    coloroff, colorblue, coloroff,
    coloroff, colorwhite, coloroff
  },
  {
    coloroff, colorred, colorred,
    coloroff, colorblue, colorblue,
    colorwhite, colorwhite, coloroff
  },
  {
    colorred, coloroff, coloroff,
    colorblue, coloroff, coloroff,
    coloroff, coloroff, colorwhite
  },
  {
    colorred, colorred, coloroff,
    colorblue, coloroff, colorblue,
    colorwhite, coloroff, colorwhite
  },
  {
    colorred, coloroff, colorred,
    colorblue, colorblue, coloroff,
    coloroff, colorwhite, colorwhite
  },
  {
    colorred, colorred, colorred,
    colorblue, colorblue, colorblue,
    colorwhite, colorwhite, colorwhite
  },
};

