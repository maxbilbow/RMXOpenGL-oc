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
#include "Physics.h"

@interface SimpleParticle : NSObject
    @property (readwrite,nonatomic)GLKVector3 position, velocity, acceleration, forwardVector, upVector, leftVector, forwardV, upV, leftV;
    @property Physics * physics, *externalPhysics, *localPhysics;
    @property NSString* name;
- (id)initWithName:(NSString*)name;
- (void)setVelocity:(GLKVector3)acceleration;
//- (float)getForwardVelocity;
//- (float)getUpVelocity;
//- (float)getLeftVelocity;
- (GLKVector3)getEye;
- (GLKVector3)getCenter;
- (GLKVector3)getUp;

- (void)setPosition:(GLKVector3)v;
//- (GLKVector3)getVelocity;
@end

@implementation SimpleParticle
    /* ATTRIBUTES
     - Position
     - Velocity
     - (acceloration? Could be an external input)
     - LookAt
     - Up
     - Right
     */


     GLKVector3 position, velocity, acceleration, forwardVector, upVector, leftVector, forwardV, upV, leftV;
    Physics * physics, *externalPhysics, *localPhysics;
    //float * dift = &dt;
   // @synthesize position = _position;
- (id)initWithName:(NSString*)name
{
    self = [super init];
    self.name = name;
   

    if (self) {
        position = GLKVector3Make(0, 0, 0);
        velocity = GLKVector3Make(0, 0, 0);
        acceleration = GLKVector3Make(0, 0, 0);
        forwardVector = GLKVector3Make(0, 0, 1);
        upVector = GLKVector3Make(0, 1, 0);
        leftVector = GLKVector3Make(1, 0, 0);
        forwardV = GLKVector3Make(0, 0, 0);
        upV = GLKVector3Make(0, 0, 0);
        leftV = GLKVector3Make(0, 0, 0);
        localPhysics = [[Physics alloc] init:name];
        physics = localPhysics;
        externalPhysics = [[Physics alloc] init:name];
        NSLog(@"%@",[super description]);
    }
    return self;
    
}


- (void)useExternalPhysics
{
    physics = externalPhysics;
}
    
- (void)useLocalPhysics
{
    physics = localPhysics;
}


- (GLKVector3)getLeftVector
{
    return leftVector;
}
    


- (GLKVector3)getEye
{
    return position;
}
    
- (GLKVector3)getCenter
{
    return GLKVector3Add(position,forwardVector);
}
    
- (GLKVector3)getUp
{
    return upVector;
}

//-(GLKVector3)position{
//    return _position;
//}
//
//-(GLKVector3)velocity{
//    return _velocity;
//}
//-(GLKVector3)acceleration{
//    return _acceleration;
//}
//-(GLKVector3)forwardVector{
//    return _forwardVector;
//}
//-(GLKVector3)upVector{
//    return _upVector;
//}
//-(GLKVector3)leftVector{
//    return _leftVector;
//}
//-(GLKVector3)forwardV{
//    return _forwardV;
//}
//-(GLKVector3)upV{
//    return _upV;
//}
//-(GLKVector3)leftV{
//    return _leftV;
//}

@end