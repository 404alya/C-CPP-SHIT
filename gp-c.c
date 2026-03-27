#include <stdio.h>

int main() {
    const int floorExtent = 25;
    const float tileSize = 5.0f;

    for (int i = -10; i < 20; ++i) {
      printf("%d\n", i & 1);
    }

  return 0;
    // Floor tiles
    for (int y = -floorExtent; y < floorExtent; y++)
    {
        for (int x = -floorExtent; x < floorExtent; x++)
        {
            if ((y & 1) && (x & 1))
            {
        printf("a %d %d\n", x, y);
            }
            else if (!(y & 1) && !(x & 1))
            {
        printf("b %d %d\n", x, y);
            }
        }
    }
}
