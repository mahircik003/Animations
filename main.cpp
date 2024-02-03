#include <iostream>
#include <cmath>
int main(void)
{
    int width = 120;
    int height = 30;

    double ratio = (double)width / height;
    double pixel_ratio = 11.0 / 24;

    char *screen = new char[height * width + 1];

    screen[height * width] = '\0';

    for (int t = 0; t < 10000; t++)
    {
        for (int i = 0; i < height; i++)
        {
            for (int k = 0; k < width; k++)
            {
                float x = (float)k / width * 2.0 - 1.0;
                float y = (float)i / height * 2.0 - 1.0;

                x *= ratio * pixel_ratio;
                x += sin(t * 0.001);
                y+=sin(t*0.001);
                char pixel = ' ';
                if (x * x + y * y < 0.5)
                    pixel = '@';
                screen[i * width + k] = pixel;
            }
        }

        std::cout << screen;
    }

    return 0;
}