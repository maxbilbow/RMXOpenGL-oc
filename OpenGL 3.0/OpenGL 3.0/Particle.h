//
//  Particle.h
//  OpenGL 2.0
//
//  Created by Max Bilbow on 23/01/2015.
//  Copyright (c) 2015 Rattle Media Ltd. All rights reserved.
//


#include "SimpleParticle.h"
//#include "Mouse.h"

@interface Particle : SimpleParticle
@property GLKVector3 anchor;
@property float accelerationRate, speedLimit,ground,rotationSpeed,jumpStrength;
@property bool limitSpeed, drift, forward;
@property SimpleParticle *origin;// = [[SimpleParticle alloc]init];

- (void)accelerateForward:(float)velocity;
- (void)accelerateUp:(float)velocity;
- (void)accelerateLeft:(float)velocity;
- (void)forwardStop;
- (void)upStop;
- (void)leftStop;
- (void)animate;
- (void)setVelocity:(GLKVector3)acceleration;
- (void)manipulate;
- (bool)translate;
- (void)addGravity:(float)g;
- (void)toggleGravity;
- (bool)hasGravity;
- (bool)isGrounded;
- (void)push:(GLKVector3)direction;
- (void)plusAngle:(float)theta phi:(float)phi;
- (bool)isDrift;
- (void)setAnchor:(GLKVector3)vector;

@end
/*
 Provides basic movement attributes to any object
 */
@implementation Particle //, public PointOfView, public Mouse{
    /* ATTRIBUTES 
     - Position
     - Velocity
     - (acceloration? Could be an external input)
     - LookAt
     - Up
     - Right
     */

GLKVector3 anchor;
float accelerationRate, speedLimit,ground,rotationSpeed,jumpStrength;
bool limitSpeed, drift, forward;
SimpleParticle *origin;// = [[SimpleParticle alloc]init];
GLKVector3 anchor;

    

- (id)initWithName:(NSString*)name
{
    self = [super initWithName:name];
    if (self) {
        accelerationRate = 0.01;
        speedLimit = 0.20;
        limitSpeed = true;
        drift = false;
        forward = false;
        ground = 0;
        origin = [[SimpleParticle alloc]init];
        anchor = GLKVector3Make(0,0,0);
    }
    return self;
    
}
- (bool)isDrift
{
    return !drift;
}
    
- (void)setPosition:(GLKVector3)v
{
    if (v.y < ground)
        v.y = ground;
    position = v;
    [rmxDebugger add:1 n:self.name t:[NSString stringWithFormat:@"x: %f, y: %f, z: %f, GROUND: %f",position.x,position.y,position.z,ground]];
}
    
- (bool)checkLimits:(GLKVector3)dV
{
    [rmxDebugger add:1 n:self.name t:@"Check Limits in Particle should be overriten"];
    return true;
}
    
- (bool)isZero:(GLKVector3)v
{
    return ((v.x==0)&&(v.y==0)&&(v.z==0));
}
    
   
- (bool)translate
{
    if ([self isZero:velocity])
        return false;
    else
        [self setPosition:GLKVector3Add(position,velocity)];
    return true;
}
    
-(void)animate
{
    [rmxDebugger add:1 n:self t:[NSString stringWithFormat:@"PX: %f, PY: %f, PZ: %f",position.x,position.y,position.z ]];
    //[rmxDebugger add:1 n:self.name t:[NSString stringWithFormat:@"acc: %f, Vel: %f, Pos: %f",acceleration.z,velocity.z,position.z ]];
    [self accelerate];
    [self setLeftVector:GLKVector3CrossProduct(forwardVector, upVector)];
    if (![self translate])
        [rmxDebugger add:1 n:self.name t:@"no movement!"];
    [self manipulate];
    [rmxDebugger add:1 n:self t:[NSString stringWithFormat:@"PX: %f, PY: %f, PZ: %f",position.x,position.y,position.z ]];
    }

- (void)manipulate
{
    [rmxDebugger add:1 n:self.name t:@"'Manipulate' should be overridden"];
}
    //MOVEMENT

- (void)stop
{
    [self setVelocity: GLKVector3Make(0,0,0)];
        //setRotationalVelocity(GLKVector3Make(0,0,0));
}
    
//    void accelerateForward(){
//        forward = !forward;
//    }
    
- (void)accelerateForward:(float)velocity
{
    acceleration.z = velocity * accelerationRate;
    
}
    
- (void)accelerateUp:(float)velocity
{
        acceleration.y = velocity * accelerationRate;
      //  accelerate();
 //       accelerate(GLKVector3Make(0,velocity*accelerationRate,0));
}
    
- (void)accelerateLeft:(float)velocity
{
        acceleration.x = velocity * accelerationRate;
        //accelerate();//accelerate(GLKVector3Make(velocity*accelerationRate,0,0));
}


- (void)forwardStop
{
        if (!drift) {
            acceleration.z = 0;
//            if(getForwardVelocity()>0)
//                acceleration.z = -physics.friction;
//            else if (getForwardVelocity()<0)
//                acceleration.z = physics.friction;
//            else
//                acceleration.z = 0;//-velocity.z;
        }
    }
    
- (void)upStop
{
        if (!drift) {
            acceleration.y = 0;// -velocity.y;
            //accelerate();
        }
    }
    
- (void)leftStop
{
        if (!drift) {
            acceleration.x = 0;// -velocity.x;
            //accelerate();
        }
        
    }
    
    
- (void)accelerate
{
        //acceleration.z =
        [rmxDebugger add:1 n:self.name t:[NSString stringWithFormat:@"FV: %f, LV: %f, UV: %f",velocity.x,velocity.y,velocity.z]];
        acceleration.y -= [physics getGravity];
        [self setVelocity:acceleration]; //Need to calculate this
        
        if (limitSpeed){
            for (int i=0;i<3;++i)
                if (velocity.v[i] > speedLimit){
                    [rmxDebugger add:1 n:self.name t:[NSString stringWithFormat:@"speed%i = %f",i,velocity.v[i]]];
                    velocity.v[i] = speedLimit;
                } else if (velocity.v[i] < -speedLimit){
                    [rmxDebugger add:1 n:self.name t:[NSString stringWithFormat:@"speed%i = %f",i,velocity.v[i]]];
                    velocity.v[i] = -speedLimit;
                } else
                    [rmxDebugger add:1 n:self.name t:[NSString stringWithFormat:@"speed%i OK: %f",i,velocity.v[i]]];
        }
        
 
        [rmxDebugger add:6 n:self.name t:[NSString stringWithFormat:@"accZ: %f, velZ: %f",acceleration.z,velocity.z]];
        
        
    }

//    void setAngle(float theta, float phi) RMX_DEPRECATED(10_0, 10_9){
//        theta = -theta*PI_OVER_180;
//        phi = phi*PI_OVER_180;
//        forwardVector.z = cos(theta);// * sin(phi);
//        forwardVector.x = sin(theta);
//        GLKVector3Normalize(forwardVector);
//    }

    
    
- (void)plusAngle:(float)theta phi:(float)phi
{
    theta *= PI_OVER_180*rotationSpeed;
    phi *= PI_OVER_180*rotationSpeed;
    [self rotateAroundVerticle:theta];
    [self rotateAroundHorizontal:phi];
    [rmxDebugger add:2 n:self.name t:[NSString stringWithFormat:@"plusAngle: THETA %f, PHY: %f",theta,phi]];
}
    
-(void)rotateAroundVerticle:(float)theta
{
        GLKMatrix4 rm = GLKMatrix4MakeRotation(theta, upVector.x, upVector.y, upVector.z);
        //GLKMatrix4RotateWithVector3(GLKMatrix4MakeYRotation(theta), theta, getUpVector());
        forwardVector = GLKMatrix4MultiplyVector3WithTranslation(rm, forwardVector);
        //leftVector = GLKMatrix4MultiplyVector3WithTranslation(rm, leftVector);
    }
-(void)rotateAroundHorizontal:(float)phi
{
    // leftVector = GLKVector3CrossProduct(getForwardVector(), getUpVector()); // Set the Right Vector
    GLKMatrix4 rm = GLKMatrix4MakeRotation(phi, leftVector.x, leftVector.y, leftVector.z);
    
    //upVector = GLKMatrix4MultiplyVector3WithTranslation(rm, upVector);
    forwardVector = GLKMatrix4MultiplyVector3WithTranslation(rm, forwardVector);
    
}

- (void)setVelocity:(GLKVector3)acceleration
{
    float forward = acceleration.z;
    float left = -acceleration.x;
    float up = acceleration.y;
    [rmxDebugger add:1 n:self.name t:[NSString stringWithFormat:@"FV: %f, LV: %f, UV: %f",forward,left,up]];
    forwardV = GLKVector3MultiplyScalar(forwardVector, forward);
    //forwardV = GLKVector3DivideScalar(forwardV, physics.friction);
    upV = GLKVector3MultiplyScalar(upVector, up);
    leftV = GLKVector3MultiplyScalar(leftVector, left);
    // GLKVector3 tm = GLKVector3Project(acceleration, forwardVector);
    //GLKVector3 tm
    
    velocity = GLKVector3Add(velocity,GLKVector3Add(forwardV,leftV));
    velocity = GLKVector3DivideScalar(velocity,[physics getFriction]);
    velocity = GLKVector3Add(upV,velocity);
    
}

    

- (void)addGravity:(float)g
{
    [physics addGravity:g];
}
    
- (void)toggleGravity
{
    [physics toggleGravity];
}
    
- (bool)hasGravity{
    return ([physics getGravity] > 0);
}
    
- (bool)isGrounded{
        return (position.y == ground);
    }
    
- (void)push:(GLKVector3)direction
{
    velocity = GLKVector3Add(velocity, direction);
}
    
//- (void)setAnchor:(GLKVector3)anchor
//{
//    self.anchor = anchor;
//}


    
//    void unsetAnchor(){
//        origin.setPosition(anchor->getCenter());
//        this->anchor = &origin;
//    }
    

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


//    string toString(){
//        string s = "Camera Attributes: ";
//        s +=
//        "\n      POS: " + to_string(getEye().x) + ", " + to_string(getEye().y) + ", " + to_string(getEye().z);
//        return s;
//    }


    
    
    
@end


