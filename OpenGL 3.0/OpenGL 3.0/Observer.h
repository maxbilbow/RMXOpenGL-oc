//
//  Particle.h
//  OpenGL 2.0
//
//  Created by Max Bilbow on 23/01/2015.
//  Copyright (c) 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef OpenGL_2_0_Particle_h
#define OpenGL_2_0_Particle_h


#endif

#include "Particle.h"
#include "ActionProcessor.h"

@interface Observer : Particle
@property ActionProcessor *actionProcessor;
@property Particle * item;
@property GLKVector3 itemPosition;
@property float armLength, reach;

- (GLKMatrix4)makeLookAt:(GLKMatrix4(float eyeX,float eyeY, float eyeZ, float cx,float cy, float cz, float ux,float uy, float uz ))lookAt;
- (void)jump;
- (void)setView;
@end
/*
 Provides basic movement attributes to any object
 */
@implementation Observer
    /* ATTRIBUTES 
     - Position
     - Velocity
     - (acceloration? Could be an external input)
     - LookAt
     - Up
     - Right
     */
ActionProcessor *actionProcessor;
Particle * item;
GLKVector3 itemPosition;
    float armLength = 2;
    float reach = 6;
 
    
- (id)initWithName:(NSString*)name
{
    self = [super initWithName:name];
    if (self) {
        actionProcessor = [[ActionProcessor alloc]init];
        item = [[Particle alloc]init];
        itemPosition = item.position;
        ground = 1;
    }
    return self;
    }
    
        
//    NSString* toString(){
//        return PointOfView::toString();
//    }

- (void)jump
{
    if ([self hasGravity]&&[self isGrounded])
        [self accelerateUp:jumpStrength];
}
    
    
- (void)grabObject:(Particle*)item
{
        if ((self.item == item)||(GLKVector3Distance(self.position, item.position)>reach))
            [self releaseObject];
        else {
            self.item = item;
            itemPosition = self.position;
            armLength = GLKVector3Distance([self getCenter], itemPosition);
            
        }
        
    }

-(void)releaseObject
{
        //origin.setPosition(anchor->getCenter());
        self.item = [[Particle alloc]init];
}
    
-(void)manipulate
{
        //item->setAnchor(this->getPosition());
    [item setPosition:GLKVector3Add([self getCenter],
                                    GLKVector3MultiplyScalar(self.forwardVector,armLength))];
}
    
- (void)extendArmLength:(float)i
{
    if (armLength+i>1)
        armLength += i;
        
}

- (GLKMatrix4)makeLookAt:(GLKMatrix4(float eyeX,float eyeY, float eyeZ, float cx,float cy, float cz, float ux,float uy, float uz ))lookAt
{
    return (GLKMatrix4)lookAt(
                              [self getEye].x,   [self getEye].y,     [self getEye].z,
                              [self getCenter].x, [self getCenter].y, [self getCenter].z,
                              [self getUp].x,     [self getUp].y,     [self getUp].z
                              );

}

- (void)makeLookAtGl:(void(double eyeX,double eyeY, double eyeZ, double cx,double cy, double cz, double ux,double uy, double uz ))lookAt
{
     lookAt(
                              [self getEye].x,   [self getEye].y,     [self getEye].z,
                              [self getCenter].x, [self getCenter].y, [self getCenter].z,
                              [self getUp].x,     [self getUp].y,     [self getUp].z
                              );
    
}

- (GLKMatrix4)makePerspective:(GLKMatrix4(float fovyRadians, float aspect, float nearZ, float farZ))make
                            m:(float)m width:(int)width height:(int)height
{//, Number fovyRadians, Number aspect, Number nearZ, Number farZ){
    
    return (GLKMatrix4)make(60*m ,width / height, 1.0, 1000.0);
}
- (void)setView
{
    [rmxDebugger add:1 n:self.name t:@"SetView in Observer not implemented"];
}
@end
