#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    float x[3], y[3];
    float xr[3], yr[3];
    int choice, i;
    float m, c;

    initgraph(&gd, &gm, "");

    printf("Enter coordinates of triangle:\n");
    for(i = 0; i < 3; i++)
    {
        printf("Enter x%d y%d: ", i+1, i+1);
        scanf("%f %f", &x[i], &y[i]);
    }

    printf("\n1. Reflection along X-axis");
    printf("\n2. Reflection along Y-axis");
    printf("\n3. Reflection about Origin");
    printf("\n4. Reflection about line y = mx + c");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: // X-axis
            for(i = 0; i < 3; i++)
            {
                xr[i] = x[i];
                yr[i] = -y[i];
            }
            break;

        case 2: // Y-axis
            for(i = 0; i < 3; i++)
            {
                xr[i] = -x[i];
                yr[i] = y[i];
            }
            break;

        case 3: // Origin
            for(i = 0; i < 3; i++)
            {
                xr[i] = -x[i];
                yr[i] = -y[i];
            }
            break;

        case 4: // Line y = mx + c
            printf("Enter m and c: ");
            scanf("%f %f", &m, &c);

            for(i = 0; i < 3; i++)
            {
                xr[i] = ((1 - m*m)*x[i] + 2*m*y[i] - 2*m*c) / (1 + m*m);
                yr[i] = (2*m*x[i] - (1 - m*m)*y[i] + 2*c) / (1 + m*m);
            }
            break;

        default:
            printf("Invalid choice");
            closegraph();
            return 0;
    }

    // Convert mathematical coordinates to screen coordinates
    // Screen origin is top-left, so we shift origin to center
    int midx = getmaxx()/2;
    int midy = getmaxy()/2;

    // Draw axes
    line(0, midy, getmaxx(), midy); // X-axis
    line(midx, 0, midx, getmaxy()); // Y-axis

    // Draw Original Triangle (White)
    setcolor(WHITE);
   
    line(midx + x[0], midy - y[0], midx + x[1], midy - y[1]);
    line(midx + x[1], midy - y[1], midx + x[2], midy - y[2]);
    line(midx + x[2], midy - y[2], midx + x[0], midy - y[0]);

    // Draw Reflected Triangle (Red)
    setcolor(RED);
    line(midx + xr[0], midy - yr[0], midx + xr[1], midy - yr[1]);
    line(midx + xr[1], midy - yr[1], midx + xr[2], midy - yr[2]);
    line(midx + xr[2], midy - yr[2], midx + xr[0], midy - yr[0]);

    getch();
    closegraph();
    return 0;
}
