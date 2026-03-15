#include <graphics.h>
#include <conio.h>
#include<stdio.h>

// 4-connected Boundary Fill
void boundaryFill4(int x, int y, int fill_color, int boundary_color)
{
    if(getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color)
    {
        putpixel(x, y, fill_color);

        boundaryFill4(x + 1, y, fill_color, boundary_color);
        boundaryFill4(x - 1, y, fill_color, boundary_color);
        boundaryFill4(x, y + 1, fill_color, boundary_color);
        boundaryFill4(x, y - 1, fill_color, boundary_color);
    }
}

// 8-connected Boundary Fill
void boundaryFill8(int x, int y, int fill_color, int boundary_color)
{
    if(getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color)
    {
        putpixel(x, y, fill_color);

        boundaryFill8(x + 1, y, fill_color, boundary_color);
        boundaryFill8(x - 1, y, fill_color, boundary_color);
        boundaryFill8(x, y + 1, fill_color, boundary_color);
        boundaryFill8(x, y - 1, fill_color, boundary_color);

        // Diagonal calls
        boundaryFill8(x + 1, y + 1, fill_color, boundary_color);
        boundaryFill8(x - 1, y - 1, fill_color, boundary_color);
        boundaryFill8(x - 1, y + 1, fill_color, boundary_color);
        boundaryFill8(x + 1, y - 1, fill_color, boundary_color);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Draw a rectangle
    rectangle(150, 150, 300, 300);

    int choice;
    printf("Enter 1 for 4 -connected and 2 for
	
	 8 connected");
    scanf("%d",&choice);
    switch (choice){
    	case 1:
    		    boundaryFill4(200, 200, GREEN, WHITE);
    		    break;
    	
    	case 2:
    		     boundaryFill8(200, 200, RED, WHITE);
    		     break;
    		     
        default:
        	printf("Wrong Choice");
        	break;
    		

	}

    getch();
    closegraph();
    return 0;
}
