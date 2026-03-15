#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void drawTriangle(int x1,int y1,int x2,int y2,int x3,int y3,int color){
    // Draw original triangle
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
	
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    int x[3],y[3];
    int tx, ty;
    printf("2-D Translation\n");
    // Input original triangle coordinates
    for(int i=0;i<3;i++){
    printf("Enter x%d y%d: ",i+1,i+1);
    scanf("%d %d", &x[i], &y[i]);
}
    // Input translation values
    printf("Enter translation tx ty: ");
    scanf("%d %d", &tx, &ty);

drawTriangle(x[0],y[0],x[1],y[1],x[2],y[2],WHITE);

    // Apply translation
    for(int i=0;i<3;i++){
    	x[i]=x[i]+tx;
    	y[i]=y[i]+ty;
	}
    
    // Draw translated triangle
drawTriangle(x[0],y[0],x[1],y[1],x[2],y[2],RED);
    getch();
    closegraph();
    return 0;
}
