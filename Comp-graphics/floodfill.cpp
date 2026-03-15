#include <graphics.h>
#include <conio.h>

// 4-connected Flood Fill
void floodFill4(int x, int y, int old_color, int new_color)
{
    if(getpixel(x, y) == old_color)
    {
        putpixel(x, y, new_color);

        floodFill4(x + 1, y, old_color, new_color);
        floodFill4(x - 1, y, old_color, new_color);
        floodFill4(x, y + 1, old_color, new_color);
        floodFill4(x, y - 1, old_color, new_color);
    }
}

// 8-connected Flood Fill
void floodFill8(int x, int y, int old_color, int new_color)
{
    if(getpixel(x, y) == old_color)
    {
        putpixel(x, y, new_color);

        floodFill8(x + 1, y, old_color, new_color);
        floodFill8(x - 1, y, old_color, new_color);
        floodFill8(x, y + 1, old_color, new_color);
        floodFill8(x, y - 1, old_color, new_color);

        // Diagonal
        floodFill8(x + 1, y + 1, old_color, new_color);
        floodFill8(x - 1, y - 1, old_color, new_color);
        floodFill8(x - 1, y + 1, old_color, new_color);
        floodFill8(x + 1, y - 1, old_color, new_color);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Draw rectangle
    setcolor(WHITE);
    rectangle(150, 150, 300, 300);
int choice;
    printf("Enter 1 for 4 -connected and 2 for 8 connected");
    scanf("%d",&choice);
    switch (choice){
    	case 1:
                floodFill4(200, 200, BLACK, GREEN);
    		    break;
    	
    	case 2:
    		    floodFill8(200, 200, BLACK, RED);
    		     break;
    		     
        default:
        	printf("Wrong Choice");
        	break;
    		

	}

    getch();
    closegraph();
    return 0;
}
