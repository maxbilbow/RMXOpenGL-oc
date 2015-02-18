//
//  LightSource.h
//  OpenGL 2.0
//
//  Created by Max Bilbow on 25/01/2015.
//  Copyright (c) 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef OpenGL_2_0_LightSource_h
#define OpenGL_2_0_LightSource_h


#endif
#include "ShapeObject.h"

@interface LightSource : ShapeObject
@property float w;
@end

@implementation LightSource

    GLenum type = GL_POSITION;
    GLenum gl_light = GL_LIGHT0;
    float w;


    
//    LightSource(GLenum num, GLenum type, GLKVector4 position){
//        this->position = position;
//        this->gl_light = num;
//        this->type = type;
//    }
    
- (id)initWithName:(NSString*)name
{
    self = [super initWithName:name];
    if (self) {
        position = GLKVector3Make(50,0,0);
        w=1;
        size = 100;
        isRotating = true;
        temp = false;
        gravity = 0;
    }
    return self;
}
    
    
- (void)shine:(void(GLenum l, GLenum type, const float* pos))light
{
    light(gl_light, type, GLKVector4MakeWithVector3(position, w).v);
}
    
        
- (void)lightUp:(float)i
{
    position.x += i;
    [rmxDebugger add:8 n:self.name t:[NSString stringWithFormat:@" Light Y: %f", position.x]];
}
- (void)lightSwitch:(char)i
{
        switch (i){
            case '1':
                type = GL_POSITION;
                break;
            case '2':
                type = GL_SPECULAR;
                break;
            case '3':
                type = GL_AMBIENT;
                break;
            case '4':
                type = GL_DIFFUSE;
                break;
            case '5':
                type = GL_AMBIENT_AND_DIFFUSE;
                break;
        }
    }
    
- (void)setMaterial{
    glMaterialfv(GL_FRONT,GL_EMISSION, color.v);
}
    
- (void)unsetMaterial{
    glMaterialfv(GL_FRONT, GL_EMISSION,nill);
}

@end
