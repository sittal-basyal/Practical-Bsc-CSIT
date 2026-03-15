#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

// Function to draw triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color)
{
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

int main()
{
    int x[3], y[3];          // Original coordinates
    int xs[3], ys[3];        // Scaled coordinates
    float sx, sy;
    float xf, yf;
    int choice;

    initwindow(800, 600);  // Graphics window

    printf("2D Scaling\n");

    // Input original triangle
    for(int i = 0; i < 3; i++)
    {
        printf("Enter x%d y%d: ", i+1, i+1);
        scanf("%d %d", &x[i], &y[i]);
    }

    // Draw original triangle (WHITE)
    drawTriangle(x[0], y[0], x[1], y[1], x[2], y[2], WHITE);

    // Input scaling factors
    printf("Enter scaling factors sx sy: ");
    scanf("%f %f", &sx, &sy);

    printf("\n1. Scaling about Origin");
    printf("\n2. Scaling about Fixed Point (xf, yf)");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:   // Scaling about Origin
            for(int i = 0; i < 3; i++)
            {
                xs[i] = round(x[i] * sx);
                ys[i] = round(y[i] * sy);
            }
            break;

        case 2:   // Scaling about Fixed Point
            printf("Enter fixed point (xf yf): ");
            scanf("%f %f", &xf, &yf);

            for(int i = 0; i < 3; i++)
            {
                xs[i] = round(xf + (x[i] - xf) * sx);
                ys[i] = round(yf + (y[i] - yf) * sy);
            }
            break;

        default:
            printf("Invalid choice!");
            closegraph();
            return 0;
    }

    // Draw scaled triangle (RED)
    drawTriangle(xs[0], ys[0], xs[1], ys[1], xs[2], ys[2], RED);

    getch();
    closegraph();
    return 0;
}
