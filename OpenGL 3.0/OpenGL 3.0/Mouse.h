//
//  Mouse.h
//  OpenGL 2.0
//
//  Created by Max Bilbow on 31/01/2015.
//  Copyright (c) 2015 Rattle Media Ltd. All rights reserved.
//


@interface Mouse : NSObject
    @property bool focus;
    @property int dx, dy;
    @property GLKVector2 pos;
@end

@implementation Mouse

bool focus;
int dx, dy;
GLKVector2 pos;

- (instancetype)init
{
    self = [super init];
    if (self) {
        focus = false;
        dx = 0;
        dy = 0;
        pos = GLKVector2Make(0,0);
    }
    return self;

   
}
    void toggleFocus(){
        focus = !focus;
    }
    bool hasFocus(){
        return focus;
    }

    GLKVector2 getPos(){
        return pos;
    }

    void setPos(int h, int v){
        pos.x=h;
        pos.y=v;
    }

    virtual void rotate(){};
    virtual float getRotationSpeed(){ return 1; }
    virtual void rotateAroundVerticle(float theta){}
    virtual void rotateAroundHorizontal(float phi){}

    virtual void plusAngle(float theta, float phi){}

    
    
    GLKVector2 getMouse(){
        //GLKVector2 pos = { this->pos.x - dx,this->pos.y - dy};
        return pos;
    }
    
    void center(void (*center)(int x, int y)){
        center(pos.x,pos.y);
    }
    
    void setMousePos(int x, int y){
        pos.x = x;// + dx;
        pos.y = y;//;
    }
    void mouse2view(int x, int y){
        //dx = dy = 0;
        
        
        int DeltaX, DeltaY;// =
        
        
        CGGetLastMouseDelta(&DeltaX, &DeltaY);
//        pos.x += DeltaX;
//        pos.y += DeltaY;
        //cout<< "  dx " << "|" << DeltaX << "|" << DeltaY << endl;
        [rmxDebugger add:3 text:@"Mousie diffX: ", DeltaX, @" diffY: ", DeltaY];
       
        
        //DeltaX -= dx; DeltaY -= dy;
        //cout<< "  dx " << "|" << DeltaX << "|" << DeltaY << endl;
        int dir = focus ? 1 : -1;
        
        float theta = (float)(DeltaX)*dir;
        float phi = (float)(DeltaY)*dir;// / 20.0f;
        
        plusAngle(theta,phi);
        // cout<< "  Mouse Pos: " << "|" << pos.x << "|" << pos.y << endl;
        
        
    }
    
    void calibrateMouse(int x, int y){//GLKVector2 pos){
        CGGetLastMouseDelta(&dx, &dy);
//        dx += x - CGDisplayPixelsWide(0)/2;
//        dy += y - CGDisplayPixelsHigh(0)/2;
        //setMousePos(pos.x-dx, pos.y-dy);
        cout<< "  CALABRATING " << "|" << dx << "|" << dy << endl;
    }
@end