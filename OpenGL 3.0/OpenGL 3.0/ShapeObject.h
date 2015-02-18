//
//  ShapeObject.h
//  OpenGL 2.0
//
//  Created by Max Bilbow on 25/01/2015.
//  Copyright (c) 2015 Rattle Media Ltd. All rights reserved.
//


@interface ShapeObject : Particle
@property float size, rotation;
//@property  GLKVector4 color;// = GLKVector4Make(1,1, 1, 10);
@property  bool isRotating;

@property  GLKVector3 rAxis;
@end

@implementation ShapeObject
    //GLKVector4 position;
    float size =1;
GLKVector4 color;// = GLKVector4Make(1,1, 1, 10);
    const float nill[4] = {0,0,0,0};
    float rotation = 0;
    bool isRotating = false;

GLKVector3 rAxis;

- (id)initWithName:(NSString*)name
{
    self = [super initWithName:name];
    if (self) {
        color = GLKVector4Make(1,1, 1, 10);
        rAxis = GLKVector3Make(0,0,1);
        
    }
    return self;
    
}

- (void)draw
{
    glPushMatrix();
    
    glRotatef(rotation, rAxis.x, rAxis.y, rAxis.z);
    
    glPushMatrix();
    
    glTranslatef(anchor.x,anchor.y, anchor.z);
    glTranslatef(position.x,position.y,position.z);
    [self setMaterial];
    //drawMe(size);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    [self unsetMaterial];
    
    //glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}
- (void)draw:(void(float size))drawMe{
        glPushMatrix();
       
        glRotatef(rotation, rAxis.x, rAxis.y, rAxis.z);
        
        glPushMatrix();
        
        glTranslatef(anchor.x,anchor.y, anchor.z);
        glTranslatef(position.x,position.y,position.z);
    [self setMaterial];
        drawMe(size);
       // glDrawArrays(GL_TRIANGLES, 0, 36);
    [self unsetMaterial];
        
        //glPopMatrix();
        glPopMatrix();
        glPopMatrix();
    }

    
    bool temp = true;
- (void)animate
{
    //if (temp) tester.checks[9] += "\nSHAPE:\n" + toString();
    if (isRotating) rotation += _dt;//*dift;// * 30;
    [super animate];
    }

- (void)setMaterial
{
        //glMaterialfv(GL_FRONT,GL_EMISSION, color.v);
}
    
- (void)unsetMaterial
{
        //glMaterialfv(GL_FRONT, GL_EMISSION,nill);
}
    
    float * getColorfv(){
        return color.v;
    }
    
- (void)setColor:(float*)c
{
    color = GLKVector4MakeWithArray(c);
}
    
    void setrAxis(GLKVector3 axis){
        rAxis = axis;
    }
    
    void setTranslation(GLKVector3 vector){
        
    }
@end