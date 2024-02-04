#include <iostream>
#include <cmath>

std::string pixels=" .:!/r(l1Z4H9W8$@";

double pulsation_function(int t)
{
    return sin(0.001*t);
}

int main(void)
{
    int width = 120;
    int height = 30;

    double radius=0.2;

    double ratio = (double)width / height;
    double pixel_ratio = 11.0 / 24;

    char *screen = new char[height * width + 1];

    screen[height * width] = '\0';

    for (int t = 0; t < 20000; t++)
    {
        for (int i = 0; i < height; i++)
        {
            for (int k = 0; k < width; k++)
            {
                float x = (float)k / width * 2.0 - 1.0;
                float y = (float)i / height * 2.0 - 1.0;

                double p=pulsation_function(t);

                x *= ratio * pixel_ratio;
                x += p;

                double camera_x=0;
                double camera_y=0;
                double camera_z=2;

                camera_z += p*p;

                x*=camera_z;
                y*=camera_z;

                double distance_squared = (x) *(x) + y *y;

                int color = (int)(distance_squared/(radius*radius));
                if(color<0)
                    color=0;
                else if(color>=pixels.size())
                    color=pixels.size()-1;

                char pixel=pixels[pixels.size()-1-color];
                screen[i * width + k] = pixel;
            }
        }

        std::cout << screen;
    }

    return 0;
}
